/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:42:54 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:14:10 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

extern t_uint8	NM_CLASS;

static void	make_view_32(t_s_hdr_view *s_hdr)
{
	s_hdr->get_name			= ft_s_hdr_get_name_32;
	s_hdr->get_type			= ft_s_hdr_get_type_32;
	s_hdr->get_flags		= ft_s_hdr_get_flags_32;
	s_hdr->get_addr			= ft_s_hdr_get_addr_32;
	s_hdr->get_offset		= ft_s_hdr_get_offset_32;
	s_hdr->get_size			= ft_s_hdr_get_size_32;
	s_hdr->get_link			= ft_s_hdr_get_link_32;
	s_hdr->get_info			= ft_s_hdr_get_info_32;
	s_hdr->get_align		= ft_s_hdr_get_align_32;
	s_hdr->get_entsize		= ft_s_hdr_get_entsize_32;

	s_hdr->set_name			= ft_s_hdr_set_name_32;
	s_hdr->set_type			= ft_s_hdr_set_type_32;
	s_hdr->set_flags		= ft_s_hdr_set_flags_32;
	s_hdr->set_addr			= ft_s_hdr_set_addr_32;
	s_hdr->set_offset		= ft_s_hdr_set_offset_32;
	s_hdr->set_size			= ft_s_hdr_set_size_32;
	s_hdr->set_link			= ft_s_hdr_set_link_32;
	s_hdr->set_info			= ft_s_hdr_set_info_32;
	s_hdr->set_align		= ft_s_hdr_set_align_32;
	s_hdr->set_entsize		= ft_s_hdr_set_entsize_32;
}

static void	make_view_64(t_s_hdr_view *s_hdr)
{
	s_hdr->get_name			= ft_s_hdr_get_name_64;
	s_hdr->get_type			= ft_s_hdr_get_type_64;
	s_hdr->get_flags		= ft_s_hdr_get_flags_64;
	s_hdr->get_addr			= ft_s_hdr_get_addr_64;
	s_hdr->get_offset		= ft_s_hdr_get_offset_64;
	s_hdr->get_size			= ft_s_hdr_get_size_64;
	s_hdr->get_link			= ft_s_hdr_get_link_64;
	s_hdr->get_info			= ft_s_hdr_get_info_64;
	s_hdr->get_align		= ft_s_hdr_get_align_64;
	s_hdr->get_entsize		= ft_s_hdr_get_entsize_64;

	s_hdr->set_name			= ft_s_hdr_set_name_64;
	s_hdr->set_type			= ft_s_hdr_set_type_64;
	s_hdr->set_flags		= ft_s_hdr_set_flags_64;
	s_hdr->set_addr			= ft_s_hdr_set_addr_64;
	s_hdr->set_offset		= ft_s_hdr_set_offset_64;
	s_hdr->set_size			= ft_s_hdr_set_size_64;
	s_hdr->set_link			= ft_s_hdr_set_link_64;
	s_hdr->set_info			= ft_s_hdr_set_info_64;
	s_hdr->set_align		= ft_s_hdr_set_align_64;
	s_hdr->set_entsize		= ft_s_hdr_set_entsize_64;
}

t_elf_error	ft_make_s_hdr(char *file_ptr, t_s_hdr_view *s_hdr)
{
	if (NM_CLASS == ELFCLASSNONE)
	{
		ft_perr("unknown class\n");
		return (ERR_CAST_HDR);
	}
	if (NM_CLASS == ELFCLASS64)
	{
		s_hdr->raw._64 = (Elf64_Shdr *)file_ptr;
		make_view_64(s_hdr);
	}
	else if (NM_CLASS == ELFCLASS32)
	{
		s_hdr->raw._32 = (Elf32_Shdr *)file_ptr;
		make_view_32(s_hdr);
	}
	return (SUCCESS);
}
