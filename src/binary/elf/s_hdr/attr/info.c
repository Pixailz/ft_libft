/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/07 16:03:42 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_sh_info	ft_s_hdr_get_info_32(t_s_hdr_view *s_hdr)
{
	return (t_sh_info)s_hdr->raw._32->sh_info;
}

t_sh_info	ft_s_hdr_get_info_64(t_s_hdr_view *s_hdr)
{
	return (t_sh_info)s_hdr->raw._64->sh_info;
}

void	ft_s_hdr_set_info_32(t_s_hdr_view *s_hdr, t_sh_info value)
{
	s_hdr->raw._32->sh_info = value;
}

void	ft_s_hdr_set_info_64(t_s_hdr_view *s_hdr, t_sh_info value)
{
	s_hdr->raw._64->sh_info = value;
}

void	ft_check_s_hdr_info(t_sh_info value)
{
	ft_pdeb(ELF_STR_SHDR_INFO SEP ELF_FMT_NB "\n", value);
}
