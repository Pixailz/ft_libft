/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 14:33:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

extern t_uint8	NM_CLASS;

t_sym_info	ft_get_sym_info(t_elf_sym *sym)
{
	t_sym_info	info;

	if (is_good_sym(sym))
		return (0);
	if (NM_CLASS == ELFCLASS64)
		info = sym->_64->st_info;
	else if (NM_CLASS == ELFCLASS32)
		info = sym->_32->st_info;
	return (info);
}

t_elf_error	ft_check_sym_info(t_elf_sym *sym)
{
	t_sym_info	info;
	char		*fmt;

	info = ft_get_sym_info(sym);
	fmt = ELF_STR_SYM_INFO SEP ELF_FMT_NB "\n";
	ft_pdeb(fmt, info);
	return (SUCCESS);
}
