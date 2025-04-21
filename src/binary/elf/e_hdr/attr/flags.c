/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:42:54 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 14:14:43 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

extern t_uint8	NM_CLASS;

t_eh_flags	ft_get_e_hdr_flags(t_elf_ehdr *e_hdr)
{
	t_eh_flags	flags;

	if (ft_is_good_e_hdr(e_hdr))
		return (0);
	if (NM_CLASS == ELFCLASS64)
		flags = e_hdr->_64->e_flags;
	else if (NM_CLASS == ELFCLASS32)
		flags = e_hdr->_32->e_flags;
	return (flags);
}

t_elf_error	ft_check_e_hdr_flags(t_elf_ehdr *e_hdr)
{
	t_eh_flags	flags;
	char		*fmt;

	flags = ft_get_e_hdr_flags(e_hdr);
	fmt = ELF_STR_EHDR_FLAGS SEP ELF_FMT_NB "\n";
	ft_pdeb(fmt, flags);
	return (SUCCESS);
}
