/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sect_header_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:42:54 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 14:14:43 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

extern t_uint8	NM_CLASS;

t_eh_shentsize	ft_get_e_hdr_shentsize(t_elf_ehdr *e_hdr)
{
	t_eh_shentsize	shentsize;

	if (ft_is_good_e_hdr(e_hdr))
		return (0);
	if (NM_CLASS == ELFCLASS64)
		shentsize = e_hdr->_64->e_shentsize;
	else if (NM_CLASS == ELFCLASS32)
		shentsize = e_hdr->_32->e_shentsize;
	return (shentsize);
}

t_elf_error	ft_check_e_hdr_shentsize(t_elf_ehdr *e_hdr)
{
	t_eh_shentsize	shentsize;
	char		*fmt;

	shentsize = ft_get_e_hdr_shentsize(e_hdr);
	fmt = ELF_STR_EHDR_SECT_HDR_SIZE SEP ELF_FMT_NB "\n";
	ft_pdeb(fmt, shentsize);
	return (SUCCESS);
}
