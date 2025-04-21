/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_section.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:25:44 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 14:09:48 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

int	ft_get_section_index_byname(t_elfbin *bin, char *name)
{
	t_eh_shnum	shnum = -1;
	int			idx;

	shnum = ft_get_e_hdr_shnum(&bin->e_hdr);
	idx = 0;
	while (idx < shnum)
	{
		if (ft_strcmp(bin->s_hdrs_name[idx], name) == 0)
			return (idx);
		idx++;
	}
	return (-1);
}

t_elf_shdr	*ft_get_section_header_byname(t_elfbin *bin, char *name)
{
	int			idx;

	idx = ft_get_section_index_byname(bin, name);
	if (idx == -1)
		return (FT_NULL);
	return (&bin->s_hdrs[idx]);
}

t_elf_shdr	*ft_get_section_header_byndx(t_elfbin *bin, t_eh_shstrndx ndx)
{
	t_eh_shnum	shnum = -1;

	shnum = ft_get_e_hdr_shnum(&bin->e_hdr);
	if (ndx >= shnum)
		return (FT_NULL);
	return (&bin->s_hdrs[ndx]);
}

char	*ft_get_section_str(t_elfbin *bin, char *name, int at)
{
	t_elf_shdr	*shtab;

	shtab = ft_get_section_header_byname(bin, name);
	if (shtab == FT_NULL)
		return (FT_NULL);
	return (bin->file_ptr + ft_get_s_hdr_offset(shtab) + at);
}

char	*ft_get_section_name_byndx(t_elfbin *bin, t_eh_shstrndx ndx)
{
	t_eh_shnum	shnum = -1;

	shnum = ft_get_e_hdr_shnum(&bin->e_hdr);
	if (ndx >= shnum)
		return (FT_NULL);
	return (bin->s_hdrs_name[ndx]);
}