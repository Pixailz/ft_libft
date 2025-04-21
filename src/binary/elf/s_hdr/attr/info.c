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

t_sh_info	ft_get_s_hdr_info(t_elf_shdr *s_hdr)
{
	t_sh_info	info;

	if (ft_is_good_s_hdr(s_hdr))
		return (0);
	if (NM_CLASS == ELFCLASS64)
		info = s_hdr->_64->sh_info;
	else if (NM_CLASS == ELFCLASS32)
		info = (t_sh_info)s_hdr->_32->sh_info;
	return (info);
}

t_elf_error	ft_check_s_hdr_info(t_elf_shdr *s_hdr)
{
	t_sh_info	info;
	char		*fmt;

	info = ft_get_s_hdr_info(s_hdr);
	fmt = ELF_STR_SHDR_INFO SEP ELF_FMT_NB "\n";
	ft_pdeb(fmt, info);
	return (SUCCESS);
}
