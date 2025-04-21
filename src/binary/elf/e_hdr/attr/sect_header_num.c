/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sect_header_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:42:54 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 14:14:43 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

extern t_uint8	NM_CLASS;

t_eh_shnum	ft_get_e_hdr_shnum(t_elf_ehdr *e_hdr)
{
	t_eh_shnum	shnum;

	if (ft_is_good_e_hdr(e_hdr))
		return (0);
	if (NM_CLASS == ELFCLASS64)
		shnum = e_hdr->_64->e_shnum;
	else if (NM_CLASS == ELFCLASS32)
		shnum = e_hdr->_32->e_shnum;
	return (shnum);
}

t_elf_error	ft_check_e_hdr_shnum(t_elf_ehdr *e_hdr)
{
	t_eh_shnum	shnum;
	char		*fmt;

	shnum = ft_get_e_hdr_shnum(e_hdr);
	fmt = ELF_STR_EHDR_SECT_HDR_NUM SEP ELF_FMT_NB "\n";
	ft_pdeb(fmt, shnum);
	return (SUCCESS);
}
