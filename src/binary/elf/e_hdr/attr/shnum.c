/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shnum.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:42:54 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:12:54 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_eh_shnum	ft_e_hdr_get_shnum_32(t_e_hdr_view *e_hdr)
{
	return (t_eh_shnum)e_hdr->raw._32->e_shnum;
}

t_eh_shnum	ft_e_hdr_get_shnum_64(t_e_hdr_view *e_hdr)
{
	return (t_eh_shnum)e_hdr->raw._64->e_shnum;
}

void	ft_e_hdr_set_shnum_32(t_e_hdr_view *e_hdr, t_eh_shnum value)
{
	e_hdr->raw._32->e_shnum = value;
}

void	ft_e_hdr_set_shnum_64(t_e_hdr_view *e_hdr, t_eh_shnum value)
{
	e_hdr->raw._64->e_shnum = value;
}

void	ft_check_e_hdr_shnum(t_eh_shnum value)
{
	ft_pdeb(ELF_STR_EHDR_SECT_HDR_NUM SEP ELF_FMT_NB "\n", value);
}
