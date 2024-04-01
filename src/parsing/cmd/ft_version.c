/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_version.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 06:03:14 by brda-sil          #+#    #+#             */
/*   Updated: 2024/04/01 04:14:17 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

t_bin	ft_version(void)
{
	ft_printf("%s (ft_libft %s) %s\n\nWritten by %s\n", \
		PROG_NAME, VERSION_LIBFT, VERSION, AUTHOR);
	return (0);
}
