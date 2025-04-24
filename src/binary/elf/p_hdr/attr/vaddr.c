/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vaddr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/23 23:01:33 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_ph_vaddr	ft_p_hdr_get_vaddr_32(t_p_hdr_view *p_hdr)
{
	return (t_ph_vaddr)p_hdr->raw._32->p_vaddr;
}

t_ph_vaddr	ft_p_hdr_get_vaddr_64(t_p_hdr_view *p_hdr)
{
	return (t_ph_vaddr)p_hdr->raw._64->p_vaddr;
}

void	ft_p_hdr_set_vaddr_32(t_p_hdr_view *p_hdr, t_ph_vaddr value)
{
	p_hdr->raw._32->p_vaddr = value;
}

void	ft_p_hdr_set_vaddr_64(t_p_hdr_view *p_hdr, t_ph_vaddr value)
{
	p_hdr->raw._64->p_vaddr = value;
}

void	ft_check_p_hdr_vaddr(t_ph_vaddr value)
{
	ft_pdeb(ELF_STR_PHDR_VADDR SEP ELF_FMT_NB "\n", value);
}
