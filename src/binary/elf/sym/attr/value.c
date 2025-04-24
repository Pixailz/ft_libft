/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:14:22 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_sym_value	ft_sym_get_value_32(t_sym_view *sym)
{
	return (t_sym_value)sym->raw._32->st_value;
}

t_sym_value	ft_sym_get_value_64(t_sym_view *sym)
{
	return (t_sym_value)sym->raw._64->st_value;
}

void	ft_sym_set_value_32(t_sym_view *sym, t_sym_value value)
{
	sym->raw._32->st_value = value;
}

void	ft_sym_set_value_64(t_sym_view *sym, t_sym_value value)
{
	sym->raw._64->st_value = value;
}

void	ft_check_sym_value(t_sym_value value)
{
	ft_pdeb(ELF_STR_SYM_VALUE SEP ELF_FMT_NB "\n", value);
}
