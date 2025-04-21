/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_header_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:42:54 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 14:14:43 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

extern t_uint8	NM_CLASS;

t_eh_phentsize	ft_get_e_hdr_phentsize(t_elf_ehdr *e_hdr)
{
	t_eh_phentsize	phentsize;

	if (ft_is_good_e_hdr(e_hdr))
		return (0);
	if (NM_CLASS == ELFCLASS64)
		phentsize = e_hdr->_64->e_phentsize;
	else if (NM_CLASS == ELFCLASS32)
		phentsize = e_hdr->_32->e_phentsize;
	return (phentsize);
}

t_elf_error	ft_check_e_hdr_phentsize(t_elf_ehdr *e_hdr)
{
	t_eh_phentsize	phentsize;
	char		*fmt;

	phentsize = ft_get_e_hdr_phentsize(e_hdr);
	fmt = ELF_STR_EHDR_PROG_HDR_SIZE SEP ELF_FMT_NB "\n";
	ft_pdeb(fmt, phentsize);
	return (SUCCESS);
}
