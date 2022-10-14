/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:34:10 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/14 02:06:54 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		file;
	char	*line;
	t_size	counter;

	if (argc != 2)
		return (ft_error("args error", 1));
	file = open(argv[1], O_RDONLY);
	if (file < 0)
		return (ft_error(argv[1], 2));
	line = ft_get_next_line(file);
	counter = 0;
	ft_printf("line[%u] \t[%s", counter++, line);
	while (TRUE)
	{
		free(line);
		line = ft_get_next_line(file);
		if (!line)
		{
			free(line);
			break ;
		}
		ft_printf("line[%u] \t[%s", counter++, line);
	}
	return (0);
}
