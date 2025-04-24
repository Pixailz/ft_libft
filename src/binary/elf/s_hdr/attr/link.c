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

t_sh_link	ft_s_hdr_get_link_32(t_s_hdr_view *s_hdr)
{
	return (t_sh_link)s_hdr->raw._32->sh_link;
}

t_sh_link	ft_s_hdr_get_link_64(t_s_hdr_view *s_hdr)
{
	return (t_sh_link)s_hdr->raw._64->sh_link;
}

void	ft_s_hdr_set_link_32(t_s_hdr_view *s_hdr, t_sh_link value)
{
	s_hdr->raw._32->sh_link = value;
}

void	ft_s_hdr_set_link_64(t_s_hdr_view *s_hdr, t_sh_link value)
{
	s_hdr->raw._64->sh_link = value;
}

void	ft_check_s_hdr_link(t_sh_link value)
{
	ft_pdeb(ELF_STR_SHDR_LINK SEP ELF_FMT_NB "\n", value);
}
