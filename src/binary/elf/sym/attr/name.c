/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:14:22 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_sym_name	ft_sym_get_name_32(t_sym_view *sym)
{
	return (t_sym_name)sym->raw._32->st_name;
}

t_sym_name	ft_sym_get_name_64(t_sym_view *sym)
{
	return (t_sym_name)sym->raw._64->st_name;
}

void	ft_sym_set_name_32(t_sym_view *sym, t_sym_name value)
{
	sym->raw._32->st_name = value;
}

void	ft_sym_set_name_64(t_sym_view *sym, t_sym_name value)
{
	sym->raw._64->st_name = value;
}

void	ft_check_sym_name(t_sym_name value)
{
	ft_pdeb(ELF_STR_SYM_NAME SEP ELF_FMT_NB "\n", value);
}
