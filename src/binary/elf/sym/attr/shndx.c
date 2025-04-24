/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shndx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:14:22 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_sym_shndx	ft_sym_get_shndx_32(t_sym_view *sym)
{
	return (t_sym_shndx)sym->raw._32->st_shndx;
}

t_sym_shndx	ft_sym_get_shndx_64(t_sym_view *sym)
{
	return (t_sym_shndx)sym->raw._64->st_shndx;
}

void	ft_sym_set_shndx_32(t_sym_view *sym, t_sym_shndx value)
{
	sym->raw._32->st_shndx = value;
}

void	ft_sym_set_shndx_64(t_sym_view *sym, t_sym_shndx value)
{
	sym->raw._64->st_shndx = value;
}

void	ft_check_sym_shndx(t_sym_shndx value)
{
	ft_pdeb(ELF_STR_SYM_SHNDX SEP ELF_FMT_NB "\n", value);
}
