/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   version.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:42:54 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 14:14:43 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

# define ELF_NB_EHDR_VERSION	1

extern t_uint8	NM_CLASS;

t_id_str EHDR_VERSION[ELF_NB_EHDR_VERSION] = {
	{EV_CURRENT , "Current"},
};

t_eh_type	ft_get_e_hdr_version(t_elf_ehdr *e_hdr)
{
	t_eh_version	version;

	if (ft_is_good_e_hdr(e_hdr))
		return (0);
	if (NM_CLASS == ELFCLASS64)
		version = e_hdr->_64->e_version;
	else if (NM_CLASS == ELFCLASS32)
		version = e_hdr->_32->e_version;
	return (version);
}

t_elf_error	ft_check_e_hdr_version(t_elf_ehdr *e_hdr)
{
	int				counter;
	t_eh_version	version;

	version = ft_get_e_hdr_version(e_hdr);
	counter = 0;
	while (counter < ELF_NB_EHDR_VERSION)
	{
		if (version == (t_uint32)EHDR_VERSION[counter].id)
		{
			ft_pdeb(ELF_STR_EHDR_VERSION SEP "%s\n", EHDR_VERSION[counter].str);
			return (SUCCESS);
		}
		counter++;
	}
	ft_pdeb(ELF_STR_EHDR_VERSION SEP "Unknown\n");
	return (ERR_EHDR_VERSION);
}