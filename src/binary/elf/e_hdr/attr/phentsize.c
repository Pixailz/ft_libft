/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phentsize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:42:54 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:12:54 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_eh_phentsize	ft_e_hdr_get_phentsize_32(t_e_hdr_view *e_hdr)
{
	return (t_eh_phentsize)e_hdr->raw._32->e_phentsize;
}

t_eh_phentsize	ft_e_hdr_get_phentsize_64(t_e_hdr_view *e_hdr)
{
	return (t_eh_phentsize)e_hdr->raw._64->e_phentsize;
}

void	ft_e_hdr_set_phentsize_32(t_e_hdr_view *e_hdr, t_eh_phentsize value)
{
	e_hdr->raw._32->e_phentsize = value;
}

void	ft_e_hdr_set_phentsize_64(t_e_hdr_view *e_hdr, t_eh_phentsize value)
{
	e_hdr->raw._64->e_phentsize = value;
}

void	ft_check_e_hdr_phentsize(t_eh_phentsize value)
{
	ft_pdeb(ELF_STR_EHDR_PROG_HDR_SIZE SEP ELF_FMT_NB "\n", value);
}
