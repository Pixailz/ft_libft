/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:14:10 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_sh_name	ft_s_hdr_get_name_32(t_s_hdr_view *s_hdr)
{
	return (t_sh_name)s_hdr->raw._32->sh_name;
}

t_sh_name	ft_s_hdr_get_name_64(t_s_hdr_view *s_hdr)
{
	return (t_sh_name)s_hdr->raw._64->sh_name;
}

void	ft_s_hdr_set_name_32(t_s_hdr_view *s_hdr, t_sh_name value)
{
	s_hdr->raw._32->sh_name = value;
}

void	ft_s_hdr_set_name_64(t_s_hdr_view *s_hdr, t_sh_name value)
{
	s_hdr->raw._64->sh_name = value;
}

void	ft_check_s_hdr_name(t_sh_name value)
{
	ft_pdeb(ELF_STR_SHDR_NAME SEP ELF_FMT_NB "\n", value);
}
