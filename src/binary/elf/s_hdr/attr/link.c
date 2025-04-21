/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/07 16:03:42 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

extern t_uint8	NM_CLASS;

t_sh_link	ft_get_s_hdr_link(t_elf_shdr *s_hdr)
{
	t_sh_link	link;

	if (ft_is_good_s_hdr(s_hdr))
		return (0);
	if (NM_CLASS == ELFCLASS64)
		link = s_hdr->_64->sh_link;
	else if (NM_CLASS == ELFCLASS32)
		link = (t_sh_link)s_hdr->_32->sh_link;
	return (link);
}

t_elf_error	ft_check_s_hdr_link(t_elf_shdr *s_hdr)
{
	t_sh_link	link;
	char		*fmt;

	link = ft_get_s_hdr_link(s_hdr);
	fmt = ELF_STR_SHDR_LINK SEP ELF_FMT_NB "\n";
	ft_pdeb(fmt, link);
	return (SUCCESS);
}
