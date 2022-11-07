/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nb_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 03:09:08 by brda-sil          #+#    #+#             */
/*   Updated: 2022/11/07 03:21:34 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_print.h>
#include <libft_string.h>

int	main(int argc, char **argv)
{
	t_int64	n;

	if (argc != 3)
		return (write(2, "args\n", 5));
	n = ft_atoll(argv[1]);
	ft_printf("n : [%d]\n", n);
	ft_putnbr_base_fd(n, argv[2], 1);
	ft_putendl_fd("", 1);
	return (0);
}
