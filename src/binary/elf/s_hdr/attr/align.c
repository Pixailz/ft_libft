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

t_sh_align	ft_s_hdr_get_align_32(t_s_hdr_view *s_hdr)
{
	return (t_sh_align)s_hdr->raw._32->sh_addralign;
}

t_sh_align	ft_s_hdr_get_align_64(t_s_hdr_view *s_hdr)
{
	return (t_sh_align)s_hdr->raw._64->sh_addralign;
}

void	ft_s_hdr_set_align_32(t_s_hdr_view *s_hdr, t_sh_align value)
{
	s_hdr->raw._32->sh_addralign = value;
}

void	ft_s_hdr_set_align_64(t_s_hdr_view *s_hdr, t_sh_align value)
{
	s_hdr->raw._64->sh_addralign = value;
}

void	ft_check_s_hdr_align(t_sh_align value)
{
	ft_pdeb(ELF_STR_SHDR_ALIGN SEP ELF_FMT_NB "\n", value);
}
