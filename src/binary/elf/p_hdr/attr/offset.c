/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:14:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_ph_offset	ft_p_hdr_get_offset_32(t_p_hdr_view *p_hdr)
{
	return (t_ph_offset)p_hdr->raw._32->p_offset;
}

t_ph_offset	ft_p_hdr_get_offset_64(t_p_hdr_view *p_hdr)
{
	return (t_ph_offset)p_hdr->raw._64->p_offset;
}

void	ft_p_hdr_set_offset_32(t_p_hdr_view *p_hdr, t_ph_offset value)
{
	p_hdr->raw._32->p_offset = value;
}

void	ft_p_hdr_set_offset_64(t_p_hdr_view *p_hdr, t_ph_offset value)
{
	p_hdr->raw._64->p_offset = value;
}

void	ft_check_p_hdr_offset(t_ph_offset value)
{
	ft_pdeb(ELF_STR_PHDR_OFFSET SEP ELF_FMT_NB "\n", value);
}
