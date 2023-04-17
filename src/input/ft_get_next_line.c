/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:18:23 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/28 12:47:38 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_input.h"

static void	fill_buff(int fd, char **buff)
{
	char	*joined_tmp;
	char	*buff_tmp;
	t_size	readed;

	buff_tmp = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buff_tmp)
		return ;
	readed = 1;
	while (readed && !ft_strcchr(buff_tmp, '\n'))
	{
		readed = read(fd, buff_tmp, BUFFER_SIZE);
		buff_tmp[readed] = 0;
		joined_tmp = ft_strjoin(*buff, buff_tmp);
		free(*buff);
		*buff = joined_tmp;
	}
	free(buff_tmp);
}

static void	push_buff(char **buff, t_size len_line)
{
	t_size	len_buff;
	t_size	len_new_buff;
	char	*new_buff;

	len_buff = ft_strlen(*buff);
	if (len_buff == len_line)
	{
		free(*buff);
		*buff = FT_NULL;
		return ;
	}
	len_new_buff = len_buff - len_line;
	new_buff = (char *)ft_calloc(sizeof(char), len_new_buff + 1);
	ft_strncpy(new_buff, *buff + len_line, len_new_buff);
	free(*buff);
	*buff = new_buff;
}

static void	get_line(char **line, char **buff)
{
	char	*newline_ptr;
	t_size	len_line;

	newline_ptr = ft_strchr(*buff, '\n');
	if (!newline_ptr)
		len_line = ft_strlen(*buff);
	else
		len_line = (newline_ptr - *buff) + 1;
	*line = ft_calloc(sizeof(char), len_line + 1);
	if (!line)
		return ;
	ft_strncpy(*line, *buff, len_line);
	push_buff(buff, len_line);
}

char	*ft_get_next_line(int fd)
{
	static char	*buff[MAX_FD] = {FT_NULL};
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (FT_NULL);
	if (buff[fd] == FT_NULL)
		buff[fd] = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	fill_buff(fd, &buff[fd]);
	get_line(&line, &buff[fd]);
	return (line);
}
