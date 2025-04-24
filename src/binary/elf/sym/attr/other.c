/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:14:22 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_sym_other	ft_sym_get_other_32(t_sym_view *sym)
{
	return (t_sym_other)sym->raw._32->st_other;
}

t_sym_other	ft_sym_get_other_64(t_sym_view *sym)
{
	return (t_sym_other)sym->raw._64->st_other;
}

void	ft_sym_set_other_32(t_sym_view *sym, t_sym_other value)
{
	sym->raw._32->st_other = value;
}

void	ft_sym_set_other_64(t_sym_view *sym, t_sym_other value)
{
	sym->raw._64->st_other = value;
}

void	ft_check_sym_other(t_sym_other value)
{
	ft_pdeb(ELF_STR_SYM_OTHER SEP ELF_FMT_NB "\n", value);
}
