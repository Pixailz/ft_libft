/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:14:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_ph_filesz	ft_p_hdr_get_filesz_32(t_p_hdr_view *p_hdr)
{
	return (t_ph_filesz)p_hdr->raw._32->p_filesz;
}

t_ph_filesz	ft_p_hdr_get_filesz_64(t_p_hdr_view *p_hdr)
{
	return (t_ph_filesz)p_hdr->raw._64->p_filesz;
}

void	ft_p_hdr_set_filesz_32(t_p_hdr_view *p_hdr, t_ph_filesz value)
{
	p_hdr->raw._32->p_filesz = value;
}

void	ft_p_hdr_set_filesz_64(t_p_hdr_view *p_hdr, t_ph_filesz value)
{
	p_hdr->raw._64->p_filesz = value;
}

void	ft_check_p_hdr_filesz(t_ph_filesz value)
{
	ft_pdeb(ELF_STR_PHDR_FILESZ SEP ELF_FMT_NB "\n", value);
}
