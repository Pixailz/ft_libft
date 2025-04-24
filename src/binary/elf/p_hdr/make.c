/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:42:54 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:14:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

extern t_uint8	NM_CLASS;

static void	make_view_32(t_p_hdr_view *p_hdr)
{
	p_hdr->get_type			= ft_p_hdr_get_type_32;
	p_hdr->get_offset		= ft_p_hdr_get_offset_32;
	p_hdr->get_vaddr		= ft_p_hdr_get_vaddr_32;
	p_hdr->get_paddr		= ft_p_hdr_get_paddr_32;
	p_hdr->get_filesz		= ft_p_hdr_get_filesz_32;
	p_hdr->get_memsz		= ft_p_hdr_get_memsz_32;
	p_hdr->get_flags		= ft_p_hdr_get_flags_32;
	p_hdr->get_align		= ft_p_hdr_get_align_32;

	p_hdr->set_type			= ft_p_hdr_set_type_32;
	p_hdr->set_offset		= ft_p_hdr_set_offset_32;
	p_hdr->set_vaddr		= ft_p_hdr_set_vaddr_32;
	p_hdr->set_paddr		= ft_p_hdr_set_paddr_32;
	p_hdr->set_filesz		= ft_p_hdr_set_filesz_32;
	p_hdr->set_memsz		= ft_p_hdr_set_memsz_32;
	p_hdr->set_flags		= ft_p_hdr_set_flags_32;
	p_hdr->set_align		= ft_p_hdr_set_align_32;
}

static void	make_view_64(t_p_hdr_view *p_hdr)
{
	p_hdr->get_type			= ft_p_hdr_get_type_64;
	p_hdr->get_offset		= ft_p_hdr_get_offset_64;
	p_hdr->get_vaddr		= ft_p_hdr_get_vaddr_64;
	p_hdr->get_paddr		= ft_p_hdr_get_paddr_64;
	p_hdr->get_filesz		= ft_p_hdr_get_filesz_64;
	p_hdr->get_memsz		= ft_p_hdr_get_memsz_64;
	p_hdr->get_flags		= ft_p_hdr_get_flags_64;
	p_hdr->get_align		= ft_p_hdr_get_align_64;

	p_hdr->set_type			= ft_p_hdr_set_type_64;
	p_hdr->set_offset		= ft_p_hdr_set_offset_64;
	p_hdr->set_vaddr		= ft_p_hdr_set_vaddr_64;
	p_hdr->set_paddr		= ft_p_hdr_set_paddr_64;
	p_hdr->set_filesz		= ft_p_hdr_set_filesz_64;
	p_hdr->set_memsz		= ft_p_hdr_set_memsz_64;
	p_hdr->set_flags		= ft_p_hdr_set_flags_64;
	p_hdr->set_align		= ft_p_hdr_set_align_64;
}

t_elf_error	ft_make_p_hdr(char *file_ptr, t_p_hdr_view *p_hdr)
{
	if (NM_CLASS == ELFCLASSNONE)
	{
		ft_perr("unknown class\n");
		return (ERR_CAST_HDR);
	}
	if (NM_CLASS == ELFCLASS64)
	{
		p_hdr->raw._64 = (Elf64_Phdr *)file_ptr;
		make_view_64(p_hdr);
	}
	else if (NM_CLASS == ELFCLASS32)
	{
		p_hdr->raw._32 = (Elf32_Phdr *)file_ptr;
		make_view_32(p_hdr);
	}
	return (SUCCESS);
}
