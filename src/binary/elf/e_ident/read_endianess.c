/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_endianess.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 08:35:48 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 14:26:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

# define ELF_NB_ENDIANESS	2

t_id_str	DATA_ENDIANESS[ELF_NB_ENDIANESS] = {
	{ELFDATA2LSB,	"2's LSB"},
	{ELFDATA2MSB,	"2's MSB"},
};

t_elf_error ft_read_e_ident_endianess(char *file_ptr, t_elf_hdr_ident *e_ident)
{
	int		counter = 0;
	t_uint8	ptr;

	ptr = *(file_ptr + EI_DATA);
	counter = 0;
	while (counter < ELF_NB_ENDIANESS)
	{
		if (ptr == DATA_ENDIANESS[counter].id)
		{
			e_ident->endianess = DATA_ENDIANESS[counter].id;
			ft_pdeb(ELF_STR_EHDR_IDENT_ENDIANESS SEP "%s\n", DATA_ENDIANESS[counter].str);
			return (SUCCESS);
		}
		counter++;
	}
	ft_pdeb(ELF_STR_EHDR_IDENT_ENDIANESS SEP "Unknown\n");
	return (ERR_IDENT_ENDIANESS);
}
