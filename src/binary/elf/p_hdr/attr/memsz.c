/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memsz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/23 23:09:24 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_ph_memsz	ft_p_hdr_get_memsz_32(t_p_hdr_view *p_hdr)
{
	return (t_ph_memsz)p_hdr->raw._32->p_memsz;
}

t_ph_memsz	ft_p_hdr_get_memsz_64(t_p_hdr_view *p_hdr)
{
	return (t_ph_memsz)p_hdr->raw._64->p_memsz;
}

void	ft_p_hdr_set_memsz_32(t_p_hdr_view *p_hdr, t_ph_memsz value)
{
	p_hdr->raw._32->p_memsz = value;
}

void	ft_p_hdr_set_memsz_64(t_p_hdr_view *p_hdr, t_ph_memsz value)
{
	p_hdr->raw._64->p_memsz = value;
}

void	ft_check_p_hdr_memsz(t_ph_memsz value)
{
	ft_pdeb(ELF_STR_PHDR_MEMSZ SEP ELF_FMT_NB "\n", value);
}
