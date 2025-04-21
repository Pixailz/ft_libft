/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 14:26:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

extern t_uint8	NM_CLASS;

t_sh_name	ft_get_s_hdr_name(t_elf_shdr *s_hdr)
{
	t_sh_name	name;

	if (ft_is_good_s_hdr(s_hdr))
		return (0);
	if (NM_CLASS == ELFCLASS64)
		name = s_hdr->_64->sh_name;
	else if (NM_CLASS == ELFCLASS32)
		name = (t_sh_name)s_hdr->_32->sh_name;
	return (name);
}

t_elf_error	ft_check_s_hdr_name(t_elf_shdr *s_hdr)
{
	t_sh_name	name;
	char		*fmt;

	name = ft_get_s_hdr_name(s_hdr);
	fmt = ELF_STR_SHDR_NAME SEP ELF_FMT_NB "\n";
	ft_pdeb(fmt, name);
	return (SUCCESS);
}
