/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nameserver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:06:04 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/13 10:10:19 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"
#include "libft_input.h"
#include <fcntl.h>

t_int4	get_dns_nameserver(void)
{
	int		fd;
	char*	line;
	char**	splitted;
	t_int4	ip;

	fd = open("/etc/resolv.conf", O_RDONLY);
	if (fd < 0)
		return (0);
	while (TRUE)
	{
		line = ft_get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		else if (ft_strncmp(line, "nameserver", 10))
		{
			free(line);
			continue ;
		}
		break;
	}
	ft_get_next_line(-2);
	close(fd);
	splitted = ft_split(line, ' ');
	free(line);
	splitted[1][ft_strlen(splitted[1]) - 1] = '\0';
	ip = ft_ipstr(splitted[1]);
	ft_free_char_pp(splitted);
	ip = ip? ip: DNS_DEFAULT_ADDR;
	return (ft_htonl(ip));
}
