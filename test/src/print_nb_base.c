/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nb_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 03:09:08 by brda-sil          #+#    #+#             */
/*   Updated: 2023/07/31 20:36:04 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"
#include "libft_string.h"

#ifndef CI_TEST
# define CI_TEST FALSE
#endif

int	ci_test(void)
{
	// TODO: add more stuff
	return (0);
}

int	interactive(int ac, char **av)
{
	t_int64	n;

	if (ac != 3)
		return (write(2, "args\n", 5));
	n = ft_atoll(av[1]);
	ft_printf("n : [%d]\n", n);
	ft_putnbr_base_fd(n, av[2], 1);
	ft_putendl_fd("", 1);
	return (0);
}

int	main(int ac, char **av)
{
	if (CI_TEST)
		return (ci_test());
	else
		return (interactive(ac, av));
	return (0);
}
