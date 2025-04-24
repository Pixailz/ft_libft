/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:42:54 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:12:54 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_eh_flags	ft_e_hdr_get_flags_32(t_e_hdr_view *e_hdr)
{
	return (t_eh_flags)e_hdr->raw._32->e_flags;
}

t_eh_flags	ft_e_hdr_get_flags_64(t_e_hdr_view *e_hdr)
{
	return (t_eh_flags)e_hdr->raw._64->e_flags;
}

void	ft_e_hdr_set_flags_32(t_e_hdr_view *e_hdr, t_eh_flags value)
{
	e_hdr->raw._32->e_flags = value;
}

void	ft_e_hdr_set_flags_64(t_e_hdr_view *e_hdr, t_eh_flags value)
{
	e_hdr->raw._64->e_flags = value;
}

void	ft_check_e_hdr_flags(t_eh_flags value)
{
	ft_pdeb(ELF_STR_EHDR_FLAGS SEP ELF_FMT_NB "\n", value);
}
