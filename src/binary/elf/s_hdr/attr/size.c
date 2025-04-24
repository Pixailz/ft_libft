/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/07 16:03:42 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_sh_size	ft_s_hdr_get_size_32(t_s_hdr_view *s_hdr)
{
	return (t_sh_size)s_hdr->raw._32->sh_size;
}

t_sh_size	ft_s_hdr_get_size_64(t_s_hdr_view *s_hdr)
{
	return (t_sh_size)s_hdr->raw._64->sh_size;
}

void	ft_s_hdr_set_size_32(t_s_hdr_view *s_hdr, t_sh_size value)
{
	s_hdr->raw._32->sh_size = value;
}

void	ft_s_hdr_set_size_64(t_s_hdr_view *s_hdr, t_sh_size value)
{
	s_hdr->raw._64->sh_size = value;
}

void	ft_check_s_hdr_size(t_sh_size value)
{
	ft_pdeb(ELF_STR_SHDR_SIZE SEP ELF_FMT_NB "\n", value);
}
