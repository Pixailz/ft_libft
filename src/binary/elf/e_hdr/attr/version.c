/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   version.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:42:54 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:12:54 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

# define ELF_NB_EHDR_VERSION	1

t_id_str EHDR_VERSION[ELF_NB_EHDR_VERSION] = {
	{EV_CURRENT , "Current"},
};

t_eh_version	ft_e_hdr_get_version_32(t_e_hdr_view *e_hdr)
{
	return (t_eh_version)e_hdr->raw._32->e_version;
}

t_eh_version	ft_e_hdr_get_version_64(t_e_hdr_view *e_hdr)
{
	return (t_eh_version)e_hdr->raw._64->e_version;
}

void	ft_e_hdr_set_version_32(t_e_hdr_view *e_hdr, t_eh_version value)
{
	e_hdr->raw._32->e_version = value;
}

void	ft_e_hdr_set_version_64(t_e_hdr_view *e_hdr, t_eh_version value)
{
	e_hdr->raw._64->e_version = value;
}

t_elf_error	ft_check_e_hdr_version(t_eh_version value)
{
	int				counter;

	counter = 0;
	while (counter < ELF_NB_EHDR_VERSION)
	{
		if (value == (t_uint32)EHDR_VERSION[counter].id)
		{
			ft_pdeb(ELF_STR_EHDR_VERSION SEP "%s\n", EHDR_VERSION[counter].str);
			return (SUCCESS);
		}
		counter++;
	}
	ft_pdeb(ELF_STR_EHDR_VERSION SEP "Unknown\n");
	return (ERR_EHDR_VERSION);
}