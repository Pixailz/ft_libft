/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isexec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:32:13 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/17 07:29:14 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	test_isexec(char *file_path)
{
	if (ft_isexec(file_path) == 1)
		ft_printf("[O] %s is exec\n", file_path);
	else
		ft_printf("[X] %s is not exec\n", file_path);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	test_isexec(argv[1]);
	return (0);
}
