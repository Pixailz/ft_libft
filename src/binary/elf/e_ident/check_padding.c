/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:07:52 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 14:26:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

# define ELF_LEN_PADDING	(EI_NIDENT - EI_PAD)

t_elf_error	ft_check_e_ident_padding(char *file_ptr, t_elf_hdr_ident *elf_hdr)
{
	int		counter;
	char	*ptr;
	t_uint8	c;

	counter = 0;
	ptr = file_ptr + EI_PAD;
	while (counter < ELF_LEN_PADDING)
	{
		c = *(ptr + counter);
		if (c != 0)
			break ;
		counter++;
	}
	if (counter == ELF_LEN_PADDING)
		elf_hdr->padding = TRUE;
	ft_pdeb(ELF_STR_EHDR_IDENT_PADDING SEP "%s\n", elf_hdr->padding ? "True" : "False");
	return (elf_hdr->padding != TRUE);
}
