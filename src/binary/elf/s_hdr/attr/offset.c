/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:14:10 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_sh_offset	ft_s_hdr_get_offset_32(t_s_hdr_view *s_hdr)
{
	return (t_sh_offset)s_hdr->raw._32->sh_offset;
}

t_sh_offset	ft_s_hdr_get_offset_64(t_s_hdr_view *s_hdr)
{
	return (t_sh_offset)s_hdr->raw._64->sh_offset;
}

void	ft_s_hdr_set_offset_32(t_s_hdr_view *s_hdr, t_sh_offset value)
{
	s_hdr->raw._32->sh_offset = value;
}

void	ft_s_hdr_set_offset_64(t_s_hdr_view *s_hdr, t_sh_offset value)
{
	s_hdr->raw._64->sh_offset = value;
}

void	ft_check_s_hdr_offset(t_sh_offset value)
{
	ft_pdeb(ELF_STR_SHDR_OFFSET SEP ELF_FMT_NB "\n", value);
}
