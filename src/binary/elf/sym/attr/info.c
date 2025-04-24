/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:14:22 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_sym_info	ft_sym_get_info_32(t_sym_view *sym)
{
	return (t_sym_info)sym->raw._32->st_info;
}

t_sym_info	ft_sym_get_info_64(t_sym_view *sym)
{
	return (t_sym_info)sym->raw._64->st_info;
}

void	ft_sym_set_info_32(t_sym_view *sym, t_sym_info value)
{
	sym->raw._32->st_info = value;
}

void	ft_sym_set_info_64(t_sym_view *sym, t_sym_info value)
{
	sym->raw._64->st_info = value;
}

void	ft_check_sym_info(t_sym_info value)
{
	ft_pdeb(ELF_STR_SYM_INFO SEP ELF_FMT_NB "\n", value);
}
