/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:57:07 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:56:01 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

char	ft_get_sym_type(t_sym *symbole)
{
	char		retv;
	t_sh_type	h_type;
	t_sh_flags	h_flags;
	t_sym_shndx	shndx;

	h_type = 0;
	h_flags = 0;
	if (symbole->shdr_name)
	{
		h_type = symbole->shdr.get_type(&symbole->shdr);
		h_flags = symbole->shdr.get_flags(&symbole->shdr);
	}
	shndx = symbole->view.get_shndx(&symbole->view);
	retv = '?';

	if (!ft_strncmp(symbole->name, ".debug", 6))
		return ('N');
	if (symbole->bind == STB_GNU_UNIQUE)
		retv = 'u';
	else if (symbole->bind == STB_WEAK)
	{
		retv = 'W';
		if (symbole->type == STT_OBJECT)
			retv = 'V';

		if (shndx == SHN_UNDEF)
			retv = ft_tolower(retv);
	}
	else if (shndx == SHN_UNDEF)
		retv = 'U';
	else if (shndx == SHN_ABS)
		retv = 'A';
	else if (shndx == SHN_COMMON)
		retv = 'C';
	else if (h_type == SHT_NOBITS)
		retv = 'B';
	else if (h_type == SHT_PROGBITS)
	{
		if (h_flags & SHF_ALLOC)
		{
			if (h_flags & SHF_WRITE)
				retv = 'D';
			else if (h_flags & SHF_EXECINSTR)
				retv = 'T';
			else
				retv = 'R';
		}
		else
			retv = 'N';
	}
	else if (
		h_type == SHT_FINI_ARRAY	||
		h_type == SHT_INIT_ARRAY	||
		h_type == SHT_PREINIT_ARRAY	||
		h_type == SHT_DYNAMIC
	)
		retv = 'D';
	else if (h_flags & SHF_ALLOC && !(h_flags & SHF_WRITE))
		retv = 'R';
	else if (h_type == SHT_GROUP)
		retv = 'N';
	else if (symbole->type == STT_SECTION)
		retv = 'n';
	if (retv != '?' && symbole->bind == STB_LOCAL)
		retv = ft_tolower(retv);
	return (retv);
}
