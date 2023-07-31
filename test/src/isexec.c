/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isexec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:32:13 by brda-sil          #+#    #+#             */
/*   Updated: 2023/07/31 20:35:32 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef CI_TEST
# define CI_TEST FALSE
#endif

void	test_isexec(char *file_path)
{
	if (ft_isexec(file_path) == 1)
		ft_printf("[O] %s is exec\n", file_path);
	else
		ft_printf("[X] %s is not exec\n", file_path);
}

int	ci_test(void)
{
	// TODO: add more stuff
	return (0);
}

int	interactive(int ac, char **av)
{
	if (ac != 2)
		return (1);
	test_isexec(av[1]);
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
