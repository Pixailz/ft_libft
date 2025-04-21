/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_class.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 08:25:12 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 14:26:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

# define ELF_NB_CLASS	2

t_uint8		NM_CLASS;

t_id_str	FILE_CLASS[ELF_NB_CLASS] = {
	{ELFCLASS32,	"32-bit"},
	{ELFCLASS64,	"64-bit"},
};

t_elf_error ft_read_e_ident_class(char *file_ptr)
{
	int		counter;
	t_uint8	ptr;

	ptr = *(file_ptr + EI_CLASS);
	counter = 0;
	while(counter < ELF_NB_CLASS)
	{
		if (ptr == FILE_CLASS[counter].id)
		{
			NM_CLASS = FILE_CLASS[counter].id;
			ft_pdeb(ELF_STR_EHDR_IDENT_CLASS SEP "%s\n", FILE_CLASS[counter].str);
			return (SUCCESS);
		}
		counter++;
	}
	ft_pdeb(ELF_STR_EHDR_IDENT_CLASS SEP "Unknown\n");
	return (ERR_IDENT_CLASS);
}
