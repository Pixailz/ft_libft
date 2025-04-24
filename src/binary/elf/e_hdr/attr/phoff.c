/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:12:54 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_eh_phoff	ft_e_hdr_get_phoff_32(t_e_hdr_view *e_hdr)
{
	return (t_eh_phoff)e_hdr->raw._32->e_phoff;
}

t_eh_phoff	ft_e_hdr_get_phoff_64(t_e_hdr_view *e_hdr)
{
	return (t_eh_phoff)e_hdr->raw._64->e_phoff;
}

void	ft_e_hdr_set_phoff_32(t_e_hdr_view *e_hdr, t_eh_phoff value)
{
	e_hdr->raw._32->e_phoff = value;
}

void	ft_e_hdr_set_phoff_64(t_e_hdr_view *e_hdr, t_eh_phoff value)
{
	e_hdr->raw._64->e_phoff = value;
}

void	ft_check_e_hdr_phoff(t_eh_phoff value)
{
	ft_pdeb(ELF_STR_EHDR_PHOFF SEP ELF_FMT_NB "\n", value);
}