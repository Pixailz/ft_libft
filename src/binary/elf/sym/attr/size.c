/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:14:22 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_sym_size	ft_sym_get_size_32(t_sym_view *sym)
{
	return (t_sym_size)sym->raw._32->st_size;
}

t_sym_size	ft_sym_get_size_64(t_sym_view *sym)
{
	return (t_sym_size)sym->raw._64->st_size;
}

void	ft_sym_set_size_32(t_sym_view *sym, t_sym_size value)
{
	sym->raw._32->st_size = value;
}

void	ft_sym_set_size_64(t_sym_view *sym, t_sym_size value)
{
	sym->raw._64->st_size = value;
}

void	ft_check_sym_size(t_sym_size value)
{
	ft_pdeb(ELF_STR_SYM_SIZE SEP ELF_FMT_NB "\n", value);
}
