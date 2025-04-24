/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:42:54 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:14:22 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

extern t_uint8	NM_CLASS;

static void	make_view_32(t_sym_view *sym)
{
	sym->get_name			= ft_sym_get_name_32;
	sym->get_value			= ft_sym_get_value_32;
	sym->get_size			= ft_sym_get_size_32;
	sym->get_info			= ft_sym_get_info_32;
	sym->get_other			= ft_sym_get_other_32;
	sym->get_shndx			= ft_sym_get_shndx_32;

	sym->set_name			= ft_sym_set_name_32;
	sym->set_value			= ft_sym_set_value_32;
	sym->set_size			= ft_sym_set_size_32;
	sym->set_info			= ft_sym_set_info_32;
	sym->set_other			= ft_sym_set_other_32;
	sym->set_shndx			= ft_sym_set_shndx_32;
}

static void	make_view_64(t_sym_view *sym)
{
	sym->get_name			= ft_sym_get_name_64;
	sym->get_value			= ft_sym_get_value_64;
	sym->get_size			= ft_sym_get_size_64;
	sym->get_info			= ft_sym_get_info_64;
	sym->get_other			= ft_sym_get_other_64;
	sym->get_shndx			= ft_sym_get_shndx_64;

	sym->set_name			= ft_sym_set_name_64;
	sym->set_value			= ft_sym_set_value_64;
	sym->set_size			= ft_sym_set_size_64;
	sym->set_info			= ft_sym_set_info_64;
	sym->set_other			= ft_sym_set_other_64;
	sym->set_shndx			= ft_sym_set_shndx_64;
}

t_elf_error	ft_make_sym(char *file_ptr, t_sym_view *sym)
{
	if (NM_CLASS == ELFCLASSNONE)
	{
		ft_perr("unknown class\n");
		return (ERR_CAST_HDR);
	}
	if (NM_CLASS == ELFCLASS64)
	{
		sym->raw._64 = (Elf64_Sym *)file_ptr;
		make_view_64(sym);
	}
	else if (NM_CLASS == ELFCLASS32)
	{
		sym->raw._32 = (Elf32_Sym *)file_ptr;
		make_view_32(sym);
	}
	return (SUCCESS);
}
