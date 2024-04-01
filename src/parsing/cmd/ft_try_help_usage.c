/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try_help_usage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 03:35:55 by brda-sil          #+#    #+#             */
/*   Updated: 2024/04/01 03:41:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

void	ft_try_help_usage(void)
{
	ft_dprintf(2, "Try '%s --help' or '%s --usage' for more informations.\n", \
		PROG_NAME, PROG_NAME);
}
