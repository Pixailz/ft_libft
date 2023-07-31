/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 02:45:23 by brda-sil          #+#    #+#             */
/*   Updated: 2023/07/31 18:30:53 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"
#include "libft_check.h"
#include "libft_error.h"

int	main(int argc, char **argv)
{
	t_bool	return_value;

	if (argc != 2)
		return (ft_perror("args"));
	return_value = ft_is_str(argv[1], ft_isblank);
	if (return_value)
		ft_printf("pass   ft_isblank(%s)\n", argv[1]);
	else
		ft_printf("failed ft_isblank(%s)\n", argv[1]);
	return (0);
}
