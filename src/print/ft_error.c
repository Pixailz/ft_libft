/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:43:45 by brda-sil          #+#    #+#             */
/*   Updated: 2022/07/06 16:08:23 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

int	ft_error(char *msg, int return_code)
{
	if (!errno)
		ft_putendl_fd("Error", 2);
	else
		ft_printf_fd(2, "Error (%d)\n", errno);
	ft_putendl_fd(msg, 2);
	return (return_code);
}
