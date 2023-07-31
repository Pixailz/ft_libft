/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:34:10 by brda-sil          #+#    #+#             */
/*   Updated: 2023/07/31 18:32:52 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#include "libft_input.h"
#include "libft_print.h"
#include "libft_error.h"

int	main(int argc, char **argv)
{
	int		file;
	char	*line;
	t_size	counter;

	if (argc != 2)
		return (ft_perror("args error"));
	file = open(argv[1], O_RDONLY);
	if (file < 0)
		return (ft_perror(argv[1]));
	line = ft_get_next_line(file);
	counter = 0;
	ft_printf("line[%u] \t[%s", counter++, line);
	while (TRUE)
	{
		free(line);
		line = ft_get_next_line(file);
		if (!*line)
		{
			free(line);
			break ;
		}
		ft_printf("line[%u] \t[%s", counter++, line);
	}
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	int		fd_1;
// 	int		fd_2;
// 	char	*line_1;
// 	char	*line_2;
// 	int		counter[2];

// 	if (argc != 3)
// 		return (ft_error("args", 1));
// 	fd_1 = open(argv[1], O_RDONLY);
// 	fd_2 = open(argv[2], O_RDONLY);
// 	line_1 = ft_get_next_line(fd_1);
// 	line_2 = ft_get_next_line(fd_2);
// 	counter[0] = 0;
// 	counter[1] = 0;
// 	ft_printf("line_1[%d] [%s]", counter[0]++, line_1);
// 	ft_printf("line_2[%d] [%s]", counter[1]++, line_2);
// 	free(line_1);
// 	free(line_2);
// 	line_1 = ft_get_next_line(fd_1);
// 	line_2 = ft_get_next_line(fd_2);
// 	ft_printf("line_1[%d] [%s]", counter[0]++, line_1);
// 	ft_printf("line_2[%d] [%s]", counter[1]++, line_2);
// 	free(line_1);
// 	free(line_2);
// 	return (0);
// }
