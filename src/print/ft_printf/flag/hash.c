/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:16:44 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/28 22:21:33 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

void	ft_printf_flag_hash(char type, t_bin *flags)
{
	if (type == '#')
		*flags |= FT_PRINTF_FLAG_HASH;
}
