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

t_ph_align	ft_p_hdr_get_align_32(t_p_hdr_view *p_hdr)
{
	return (t_ph_align)p_hdr->raw._32->p_align;
}

t_ph_align	ft_p_hdr_get_align_64(t_p_hdr_view *p_hdr)
{
	return (t_ph_align)p_hdr->raw._64->p_align;
}

void	ft_p_hdr_set_align_32(t_p_hdr_view *p_hdr, t_ph_align value)
{
	p_hdr->raw._32->p_align = value;
}

void	ft_p_hdr_set_align_64(t_p_hdr_view *p_hdr, t_ph_align value)
{
	p_hdr->raw._64->p_align = value;
}

void	ft_check_p_hdr_align(t_ph_align value)
{
	ft_pdeb(ELF_STR_PHDR_ALIGN SEP ELF_FMT_NB "\n", value);
}
