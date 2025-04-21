/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 14:26:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

extern t_uint8	NM_CLASS;

t_sh_type	ft_get_s_hdr_flags(t_elf_shdr *s_hdr)
{
	t_sh_flags	flags;

	if (ft_is_good_s_hdr(s_hdr))
		return (0);
	if (NM_CLASS == ELFCLASS64)
		flags = s_hdr->_64->sh_flags;
	else if (NM_CLASS == ELFCLASS32)
		flags = (t_sh_flags)s_hdr->_32->sh_flags;
	return (flags);
}

t_elf_error	ft_check_s_hdr_flags(t_elf_shdr *s_hdr)
{
	t_sh_flags	flags;
	char		flags_str[5];
	int			counter;

	ft_bzero(flags_str, 5);
	flags = ft_get_s_hdr_flags(s_hdr);
	counter = 0;
	if (flags & SHF_WRITE)
		flags_str[counter++] = 'W';
	if (flags & SHF_ALLOC)
		flags_str[counter++] = 'A';
	if (flags & SHF_EXECINSTR)
		flags_str[counter++] = 'X';
	if (flags & SHF_MERGE)
		flags_str[counter++] = 'M';
	if (flags & SHF_STRINGS)
		flags_str[counter++] = 'S';
	if (flags & SHF_INFO_LINK)
		flags_str[counter++] = 'I';
	if (flags & SHF_LINK_ORDER)
		flags_str[counter++] = 'L';
	if (flags & SHF_OS_NONCONFORMING)
		flags_str[counter++] = 'O';
	if (flags & SHF_GROUP)
		flags_str[counter++] = 'G';
	if (flags & SHF_TLS)
		flags_str[counter++] = 'T';
	if (flags & SHF_COMPRESSED)
		flags_str[counter++] = 'C';
	if (flags & SHF_MASKOS)
		flags_str[counter++] = 'o';
	if (flags & SHF_MASKPROC)
		flags_str[counter++] = 'p';
	if (flags & SHF_ORDERED)
		flags_str[counter++] = 'R';
	if (flags & SHF_EXCLUDE)
		flags_str[counter++] = 'E';
	ft_pdeb(ELF_STR_SHDR_FLAGS SEP "%s\n", flags_str);
	return (SUCCESS);
}
