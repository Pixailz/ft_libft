/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 14:33:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

extern t_uint8	NM_CLASS;

t_sym_other	ft_get_sym_other(t_elf_sym *sym)
{
	t_sym_other	other;

	if (is_good_sym(sym))
		return (0);
	if (NM_CLASS == ELFCLASS64)
		other = sym->_64->st_other;
	else if (NM_CLASS == ELFCLASS32)
		other = sym->_32->st_other;
	return (other);
}

t_elf_error	ft_check_sym_other(t_elf_sym *sym)
{
	t_sym_other	other;
	char		*fmt;

	other = ft_get_sym_other(sym);
	fmt = ELF_STR_SYM_OTHER SEP ELF_FMT_NB "\n";
	ft_pdeb(fmt, other);
	return (SUCCESS);
}
