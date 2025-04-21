/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 14:33:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

extern t_uint8	NM_CLASS;

t_sym_value	ft_get_sym_value(t_elf_sym *sym)
{
	t_sym_value	value;

	if (is_good_sym(sym))
		return (0);
	if (NM_CLASS == ELFCLASS64)
		value = sym->_64->st_value;
	else if (NM_CLASS == ELFCLASS32)
		value = sym->_32->st_value;
	return (value);
}

t_elf_error	ft_check_sym_value(t_elf_sym *sym)
{
	t_sym_value	value;
	char		*fmt;

	value = ft_get_sym_value(sym);
	fmt = ELF_STR_SYM_VALUE SEP ELF_FMT_NB "\n";
	ft_pdeb(fmt, value);
	return (SUCCESS);
}
