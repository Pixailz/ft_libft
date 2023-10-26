/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:42:07 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/26 23:00:31 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

#ifndef CI_TEST
# define CI_TEST FALSE
#endif

int	ci_parsing_normal(void)
{
	char	**av;

	ft_optadd("mutl", 'm', OPT_VALUE);
	ft_optadd("single", 's', OPT_VALUE);
	av = (char **)ft_calloc(sizeof(char *), 7);
	av[0] = ft_strdup("-m");
	av[1] = ft_strdup("mult_1");
	av[2] = ft_strdup("mult_2");
	av[3] = ft_strdup("mult_3");
	av[4] = ft_strdup("--single");
	av[5] = ft_strdup("single_3");
	ft_optconf(6, av);
	ft_optparse();
	ft_print_sin_opts();
	ft_sin_free_opts();
	ft_free_char_pp(av);
	return (0);
}

int	ci_parsing_wrong(void)
{
	char	**av;

	ft_optadd("first", 'f', OPT_FLAG);
	ft_optadd("single", 's', OPT_FLAG);
	ft_optadd("multiple", 'm', OPT_VALUE);
	av = (char **)ft_calloc(sizeof(char *), 7);
	av[0] = ft_strdup("-f");
	av[1] = ft_strdup("-t");
	av[2] = ft_strdup("--t");
	av[3] = ft_strdup("-asd");
	av[4] = ft_strdup("");
	av[5] = ft_strdup("single_3");
	ft_optconf(6, av);
	ft_optparse();
	ft_print_sin_opts();
	ft_sin_free_opts();
	ft_free_char_pp(av);
	return (0);
}

int	ci_test(void)
{
	ci_parsing_normal();
	ci_parsing_wrong();
	return (0);
}

/*
-f, --force
-d, --dry-run
-h, --help
-p, --part


f ! d
fdh flag
p arg
*/
int	interactive(int ac, char **av)
{
	int	counter;

	ft_pdeb("ac %d\n", ac);
	counter = 0;
	while (av[counter + 1])
	{
		ft_pdeb("av[%d] %s\n", counter + 1, av[counter + 1]);
		counter++;
	}
	ft_optadd("force", 'f', OPT_FLAG);
	ft_optadd("dry-run", 0, OPT_FLAG);
	ft_optadd("help", 'h', OPT_FLAG);
	ft_optadd("part", 'p', OPT_VALUE);
	ft_optadd("module", 'm', OPT_VALUE);
	ft_optconf(ac - 1, av + 1);
	ft_optparse();
	ft_print_sin_opts();
	ft_sin_free_opts();
	return (0);
}

int	main(int ac, char **av)
{
	if (CI_TEST)
		return (ci_test());
	else if (ac != 1)
		return (interactive(ac, av));
	return (0);
}
