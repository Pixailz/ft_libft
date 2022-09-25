/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 09:12:28 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/25 01:36:13 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"
#include "libft_print.h"

int	main(int argc, char **argv)
{
	unsigned long	n;
	int				has_overflow;

	if (argc != 2)
		return (ft_error("not enought args", 1));
	has_overflow = 0;
	n = ft_patou(argv[1], &has_overflow);
	if (has_overflow)
		ft_printf("error_occur [%d]\n", n);
	else
		ft_printf("[%s]->[%u]\n", argv[1], n);
	return (0);
}
