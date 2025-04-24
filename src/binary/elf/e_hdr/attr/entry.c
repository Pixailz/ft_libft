/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:12:31 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_eh_entry	ft_e_hdr_get_entry_32(t_e_hdr_view *e_hdr)
{
	return (t_eh_entry)e_hdr->raw._32->e_entry;
}

t_eh_entry	ft_e_hdr_get_entry_64(t_e_hdr_view *e_hdr)
{
	return (t_eh_entry)e_hdr->raw._64->e_entry;
}

void	ft_e_hdr_set_entry_32(t_e_hdr_view *e_hdr, t_eh_entry value)
{
	e_hdr->raw._32->e_entry = value;
}

void	ft_e_hdr_set_entry_64(t_e_hdr_view *e_hdr, t_eh_entry value)
{
	e_hdr->raw._64->e_entry = value;
}

void	ft_check_e_hdr_entry(t_eh_entry value)
{
	ft_pdeb(ELF_STR_EHDR_ENTRY SEP ELF_FMT_NB "\n", value);
}
