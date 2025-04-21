/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_header_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:42:54 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 14:14:43 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

extern t_uint8	NM_CLASS;

t_eh_phnum	ft_get_e_hdr_phnum(t_elf_ehdr *e_hdr)
{
	t_eh_phnum	phnum;

	if (ft_is_good_e_hdr(e_hdr))
		return (0);
	if (NM_CLASS == ELFCLASS64)
		phnum = e_hdr->_64->e_phnum;
	else if (NM_CLASS == ELFCLASS32)
		phnum = e_hdr->_32->e_phnum;
	return (phnum);
}

t_elf_error	ft_check_e_hdr_phnum(t_elf_ehdr *e_hdr)
{
	t_eh_phnum	phnum;
	char		*fmt;

	phnum = ft_get_e_hdr_phnum(e_hdr);
	fmt = ELF_STR_EHDR_PROG_HDR_NUM SEP ELF_FMT_NB "\n";
	ft_pdeb(fmt, phnum);
	return (SUCCESS);
}
