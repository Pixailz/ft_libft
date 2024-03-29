/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:01:17 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/01 11:05:51 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

void	ft_printf_buff_reset(void)
{
	ft_bzero(ft_printf_buff_get(), FT_PRINTF_BUFF_BIG);
}

char	*ft_printf_buff_get(void)
{
	static char	buffer[FT_PRINTF_BUFF_BIG] = {0};

	return (buffer);
}
