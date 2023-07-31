/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 02:45:23 by brda-sil          #+#    #+#             */
/*   Updated: 2023/07/31 20:11:44 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"
#include "libft_check.h"
#include "libft_error.h"

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
	t_bool	return_value;

	if (ac != 2)
		return (ft_perror("args\n"));
	return_value = ft_is_str(av[1], ft_isblank);
	if (return_value)
		ft_printf("pass   ft_isblank(%s)\n", av[1]);
	else
		ft_printf("failed ft_isblank(%s)\n", av[1]);
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
