/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:12:54 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_eh_shoff	ft_e_hdr_get_shoff_32(t_e_hdr_view *e_hdr)
{
	return (t_eh_shoff)e_hdr->raw._32->e_shoff;
}

t_eh_shoff	ft_e_hdr_get_shoff_64(t_e_hdr_view *e_hdr)
{
	return (t_eh_shoff)e_hdr->raw._64->e_shoff;
}

void	ft_e_hdr_set_shoff_32(t_e_hdr_view *e_hdr, t_eh_shoff value)
{
	e_hdr->raw._32->e_shoff = value;
}

void	ft_e_hdr_set_shoff_64(t_e_hdr_view *e_hdr, t_eh_shoff value)
{
	e_hdr->raw._64->e_shoff = value;
}

void	ft_check_e_hdr_shoff(t_eh_shoff value)
{
	ft_pdeb(ELF_STR_EHDR_SHOFF SEP ELF_FMT_NB "\n", value);
}