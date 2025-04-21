/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_mag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 08:04:37 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 14:26:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_elf_error ft_read_e_ident_known_mag(int magic_number)
{
	if (magic_number == 0x4d5a9000)
		return (1);
	return (0);
}

t_elf_error ft_read_e_ident_mag(char *file_ptr, t_elf_hdr_ident *e_ident)
{
	if (ft_strncmp(file_ptr, ELFMAG, SELFMAG))
	{
		if (ft_read_e_ident_known_mag(ft_htonl(*(int *)file_ptr)))
		{
			ft_pdeb(ELF_STR_PAD ELF_STR_PAD ELF_STR_LIST "Invalid KNOWN ELF magic number\n");
			return (ERR_IDENT_KNOWN_NUMBER);
		}
		ft_pdeb(ELF_STR_PAD ELF_STR_PAD ELF_STR_LIST "Invalid ELF magic number\n");
		return (ERR_IDENT_MAGIC_NUMBER);
	}
	ft_pdeb(ELF_STR_PAD ELF_STR_PAD ELF_STR_LIST "Correct ELF magic number\n");
	e_ident->good_magic_number = TRUE;
	return (SUCCESS);
}
