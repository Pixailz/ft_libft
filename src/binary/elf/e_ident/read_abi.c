/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_abi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:07:52 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 14:26:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

# define ELF_NB_ABI	16

t_id_str ABI[ELF_NB_ABI] = {
	{ELFOSABI_SYSV,			"UNIX - System V"},
	{ELFOSABI_HPUX,			"HP-UX"},
	{ELFOSABI_NETBSD,		"NetBSD"},
	{ELFOSABI_GNU,			"GNU/Linux"},
	{4,						"GNU/Hurd"},
	{ELFOSABI_SOLARIS,		"Sun Solaris"},
	{ELFOSABI_AIX,			"IBM AIX"},
	{ELFOSABI_IRIX,			"SGI Irix"},
	{ELFOSABI_FREEBSD,		"FreeBSD"},
	{ELFOSABI_TRU64,		"Tru64"},
	{ELFOSABI_MODESTO,		"Novell Modesto"},
	{ELFOSABI_OPENBSD,		"OpenBSD"},
	{ELFOSABI_ARM_AEABI,	"ARM EABI"},
	{ELFOSABI_IRIX,			"ARM"},
	{ELFOSABI_STANDALONE,	"Standalone (embedded) application"},
};

t_elf_error	ft_read_e_ident_abi(char *file_ptr, t_elf_hdr_ident *elf_hdr)
{
	int		counter;
	t_uint8	ptr;

	ptr = *(file_ptr + EI_OSABI);
	counter = 0;
	while (counter < ELF_NB_ABI)
	{
		if (ptr == ABI[counter].id)
		{
			ft_pdeb(ELF_STR_EHDR_IDENT_ABI SEP "%s\n", ABI[counter].str);
			elf_hdr->abi = ABI[counter].id;
			return (SUCCESS);
		}
		counter++;
	}
	ft_pdeb(ELF_STR_EHDR_IDENT_ABI SEP "Unknown\n");
	return (ERR_IDENT_ABI);
}
