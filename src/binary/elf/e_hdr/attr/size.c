/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:42:54 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:12:54 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_eh_size	ft_e_hdr_get_size_32(t_e_hdr_view *e_hdr)
{
	return (t_eh_size)e_hdr->raw._32->e_ehsize;
}

t_eh_size	ft_e_hdr_get_size_64(t_e_hdr_view *e_hdr)
{
	return (t_eh_size)e_hdr->raw._64->e_ehsize;
}

void	ft_e_hdr_set_size_32(t_e_hdr_view *e_hdr, t_eh_size value)
{
	e_hdr->raw._32->e_ehsize = value;
}

void	ft_e_hdr_set_size_64(t_e_hdr_view *e_hdr, t_eh_size value)
{
	e_hdr->raw._64->e_ehsize = value;
}

void	ft_check_e_hdr_size(t_eh_size value)
{
	ft_pdeb(ELF_STR_EHDR_SIZE SEP ELF_FMT_NB "\n", value);
}
