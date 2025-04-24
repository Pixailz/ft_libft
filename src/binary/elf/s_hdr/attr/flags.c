/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:14:10 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_sh_flags	ft_s_hdr_get_flags_32(t_s_hdr_view *s_hdr)
{
	return (t_sh_flags)s_hdr->raw._32->sh_flags;
}

t_sh_flags	ft_s_hdr_get_flags_64(t_s_hdr_view *s_hdr)
{
	return (t_sh_flags)s_hdr->raw._64->sh_flags;
}

void	ft_s_hdr_set_flags_32(t_s_hdr_view *s_hdr, t_sh_flags value)
{
	s_hdr->raw._32->sh_flags = value;
}

void	ft_s_hdr_set_flags_64(t_s_hdr_view *s_hdr, t_sh_flags value)
{
	s_hdr->raw._64->sh_flags = value;
}

void	ft_check_s_hdr_flags(t_sh_flags value)
{
	char		flags_str[7];
	int			counter;

	ft_bzero(flags_str, 7);
	counter = 0;
	if (value & SHF_WRITE)
		flags_str[counter++] = 'W';
	if (value & SHF_ALLOC)
		flags_str[counter++] = 'A';
	if (value & SHF_EXECINSTR)
		flags_str[counter++] = 'X';
	if (value & SHF_MERGE)
		flags_str[counter++] = 'M';
	if (value & SHF_STRINGS)
		flags_str[counter++] = 'S';
	if (value & SHF_INFO_LINK)
		flags_str[counter++] = 'I';
	if (value & SHF_LINK_ORDER)
		flags_str[counter++] = 'L';
	if (value & SHF_OS_NONCONFORMING)
		flags_str[counter++] = 'O';
	if (value & SHF_GROUP)
		flags_str[counter++] = 'G';
	if (value & SHF_TLS)
		flags_str[counter++] = 'T';
	if (value & SHF_COMPRESSED)
		flags_str[counter++] = 'C';
	if (value & SHF_MASKOS)
		flags_str[counter++] = 'o';
	if (value & SHF_MASKPROC)
		flags_str[counter++] = 'p';
	if (value & SHF_ORDERED)
		flags_str[counter++] = 'R';
	if (value & SHF_EXCLUDE)
		flags_str[counter++] = 'E';
	ft_pdeb(ELF_STR_SHDR_FLAGS SEP "%s\n", flags_str);
}
