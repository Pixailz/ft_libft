/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:14:10 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_sh_entsize	ft_s_hdr_get_entsize_32(t_s_hdr_view *s_hdr)
{
	return (t_sh_entsize)s_hdr->raw._32->sh_entsize;
}

t_sh_entsize	ft_s_hdr_get_entsize_64(t_s_hdr_view *s_hdr)
{
	return (t_sh_entsize)s_hdr->raw._64->sh_entsize;
}

void	ft_s_hdr_set_entsize_32(t_s_hdr_view *s_hdr, t_sh_entsize value)
{
	s_hdr->raw._32->sh_entsize = value;
}

void	ft_s_hdr_set_entsize_64(t_s_hdr_view *s_hdr, t_sh_entsize value)
{
	s_hdr->raw._64->sh_entsize = value;
}

void	ft_check_s_hdr_entsize(t_sh_entsize value)
{
	ft_pdeb(ELF_STR_SHDR_ENTSIZE SEP ELF_FMT_NB "\n", value);
}
