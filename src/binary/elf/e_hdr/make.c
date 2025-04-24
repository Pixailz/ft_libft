/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:47:44 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:12:54 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

extern t_uint32	NM_CLASS;

static void	ft_make_e_hdr_32(t_e_hdr_view *e_hdr)
{
	e_hdr->get_type			= ft_e_hdr_get_type_32;
	e_hdr->get_machine		= ft_e_hdr_get_machine_32;
	e_hdr->get_version		= ft_e_hdr_get_version_32;
	e_hdr->get_entry		= ft_e_hdr_get_entry_32;
	e_hdr->get_phoff		= ft_e_hdr_get_phoff_32;
	e_hdr->get_shoff		= ft_e_hdr_get_shoff_32;
	e_hdr->get_flags		= ft_e_hdr_get_flags_32;
	e_hdr->get_size			= ft_e_hdr_get_size_32;
	e_hdr->get_phentsize	= ft_e_hdr_get_phentsize_32;
	e_hdr->get_phnum		= ft_e_hdr_get_phnum_32;
	e_hdr->get_shentsize	= ft_e_hdr_get_shentsize_32;
	e_hdr->get_shnum		= ft_e_hdr_get_shnum_32;
	e_hdr->get_shstrndx		= ft_e_hdr_get_shstrndx_32;

	e_hdr->set_type			= ft_e_hdr_set_type_32;
	e_hdr->set_machine		= ft_e_hdr_set_machine_32;
	e_hdr->set_version		= ft_e_hdr_set_version_32;
	e_hdr->set_entry		= ft_e_hdr_set_entry_32;
	e_hdr->set_phoff		= ft_e_hdr_set_phoff_32;
	e_hdr->set_shoff		= ft_e_hdr_set_shoff_32;
	e_hdr->set_flags		= ft_e_hdr_set_flags_32;
	e_hdr->set_size			= ft_e_hdr_set_size_32;
	e_hdr->set_phentsize	= ft_e_hdr_set_phentsize_32;
	e_hdr->set_phnum		= ft_e_hdr_set_phnum_32;
	e_hdr->set_shentsize	= ft_e_hdr_set_shentsize_32;
	e_hdr->set_shnum		= ft_e_hdr_set_shnum_32;
	e_hdr->set_shstrndx		= ft_e_hdr_set_shstrndx_32;
}

static void	ft_make_e_hdr_64(t_e_hdr_view *e_hdr)
{
	e_hdr->get_type			= ft_e_hdr_get_type_64;
	e_hdr->get_machine		= ft_e_hdr_get_machine_64;
	e_hdr->get_version		= ft_e_hdr_get_version_64;
	e_hdr->get_entry		= ft_e_hdr_get_entry_64;
	e_hdr->get_phoff		= ft_e_hdr_get_phoff_64;
	e_hdr->get_shoff		= ft_e_hdr_get_shoff_64;
	e_hdr->get_flags		= ft_e_hdr_get_flags_64;
	e_hdr->get_size			= ft_e_hdr_get_size_64;
	e_hdr->get_phentsize	= ft_e_hdr_get_phentsize_64;
	e_hdr->get_phnum		= ft_e_hdr_get_phnum_64;
	e_hdr->get_shentsize	= ft_e_hdr_get_shentsize_64;
	e_hdr->get_shnum		= ft_e_hdr_get_shnum_64;
	e_hdr->get_shstrndx		= ft_e_hdr_get_shstrndx_64;

	e_hdr->set_type			= ft_e_hdr_set_type_64;
	e_hdr->set_machine		= ft_e_hdr_set_machine_64;
	e_hdr->set_version		= ft_e_hdr_set_version_64;
	e_hdr->set_entry		= ft_e_hdr_set_entry_64;
	e_hdr->set_phoff		= ft_e_hdr_set_phoff_64;
	e_hdr->set_shoff		= ft_e_hdr_set_shoff_64;
	e_hdr->set_flags		= ft_e_hdr_set_flags_64;
	e_hdr->set_size			= ft_e_hdr_set_size_64;
	e_hdr->set_phentsize	= ft_e_hdr_set_phentsize_64;
	e_hdr->set_phnum		= ft_e_hdr_set_phnum_64;
	e_hdr->set_shentsize	= ft_e_hdr_set_shentsize_64;
	e_hdr->set_shnum		= ft_e_hdr_set_shnum_64;
	e_hdr->set_shstrndx		= ft_e_hdr_set_shstrndx_64;
}

t_elf_error	ft_make_e_hdr(char *file_ptr, t_e_hdr_view *e_hdr)
{
	if (NM_CLASS == ELFCLASSNONE)
	{
		ft_perr("unknown class\n");
		return (ERR_CAST_HDR);
	}
	if (NM_CLASS == ELFCLASS64)
	{
		e_hdr->raw._64 = (Elf64_Ehdr *)file_ptr;
		ft_make_e_hdr_64(e_hdr);
	}
	else if (NM_CLASS == ELFCLASS32)
	{
		e_hdr->raw._32 = (Elf32_Ehdr *)file_ptr;
		ft_make_e_hdr_32(e_hdr);
	}
	return (SUCCESS);
}
