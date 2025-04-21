/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shndx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 14:33:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

extern t_uint8	NM_CLASS;

t_sym_shndx	ft_get_sym_shndx(t_elf_sym *sym)
{
	t_sym_shndx	shndx;

	if (is_good_sym(sym))
		return (0);
	if (NM_CLASS == ELFCLASS64)
		shndx = sym->_64->st_shndx;
	else if (NM_CLASS == ELFCLASS32)
		shndx = sym->_32->st_shndx;
	return (shndx);
}

t_elf_error	ft_check_sym_shndx(t_elf_sym *sym)
{
	t_sym_shndx	shndx;
	char		*fmt;

	shndx = ft_get_sym_shndx(sym);
	fmt = ELF_STR_SYM_SHNDX SEP ELF_FMT_NB "\n";
	ft_pdeb(fmt, shndx);
	return (SUCCESS);
}
