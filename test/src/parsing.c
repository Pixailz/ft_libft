/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:42:07 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/25 12:22:01 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

void	print_opt(void)
{
	t_opt	*opts;
	t_opt	*tmp;
	int		counter;

	opts = ft_sin_arg(FT_NULL);
	while (opts)
	{
		tmp = opts->next;
		ft_printf("opt_long  %s\n", opts->opt_long);
		ft_printf("opt_short %s\n", opts->opt_short);
		ft_printf("flag      %d\n", opts->flag);
		if (opts->value)
		{
			counter = -1;
			while (opts->value[++counter])
				ft_printf("value[%d] %s\n", counter, opts->value[counter]);
		}
		else
		{
			ft_printf("value     NULL\n");
		}
		ft_printf("\n");
		opts = tmp;
	}
}

// typedef struct s_opt
// {
// 	char	*name;
// 	char	*short_opt;
// 	char	*short_long;
// 	t_bool	flag;
// 	char	**value;
// }		t_opt;

/*
-f, --force
-d, --dry-run
-h, --help
-p, --part


f ! d
fdh flag
p arg
*/

int	main(int ac, char **av)
{
	t_opt	*opt;

	ft_optadd("force", "f", OPT_FLAG);
	ft_optadd("dry-run", FT_NULL, OPT_FLAG);
	ft_optadd("help", "h", OPT_FLAG);
	ft_optadd("part", "p", OPT_MULTIPLE);
	print_opt();
	ft_optparse(ac, av);
	ft_sin_free_arg();
	return (0);
}
