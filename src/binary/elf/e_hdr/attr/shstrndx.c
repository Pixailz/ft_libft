/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shstrndx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:42:54 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:12:54 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_eh_shstrndx	ft_e_hdr_get_shstrndx_32(t_e_hdr_view *e_hdr)
{
	return (t_eh_shstrndx)e_hdr->raw._32->e_shstrndx;
}

t_eh_shstrndx	ft_e_hdr_get_shstrndx_64(t_e_hdr_view *e_hdr)
{
	return (t_eh_shstrndx)e_hdr->raw._64->e_shstrndx;
}

void	ft_e_hdr_set_shstrndx_32(t_e_hdr_view *e_hdr, t_eh_shstrndx value)
{
	e_hdr->raw._32->e_shstrndx = value;
}

void	ft_e_hdr_set_shstrndx_64(t_e_hdr_view *e_hdr, t_eh_shstrndx value)
{
	e_hdr->raw._64->e_shstrndx = value;
}

void	ft_check_e_hdr_shstrndx(t_eh_shstrndx value)
{
	ft_pdeb(ELF_STR_EHDR_SECT_TXT_INDEX SEP ELF_FMT_NB "\n", value);
}
