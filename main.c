/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 09:12:28 by brda-sil          #+#    #+#             */
/*   Updated: 2022/07/05 03:45:03 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	int				i;
	unsigned long	n;

	i = 4294957604;
	ft_printf("addr u: %u\n", &i);
	printf("addr u: %u\n", &i);
	ft_printf("%%p: %p\n", &i);
	printf("%%p: %p\n", &i);
	printf("long long long: %lld\n", &i);
	printf("itoa_base(long long long): %s\n", ft_itoa_base(&i, "0123456789abcdef"));
	return (0);
}
