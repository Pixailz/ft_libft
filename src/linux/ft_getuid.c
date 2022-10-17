/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getuid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:12:24 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/15 11:55:27 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_linux.h"

int	ft_getuid_file(char *file_path)
{
	struct stat	tmp;

	if (stat(file_path, &tmp))
		return (-1);
	if (!S_ISREG(tmp.st_mode))
		return (-1);
	return (tmp.st_uid);
}

int	ft_getuid_dir(char *file_path)
{
	struct stat	tmp;

	if (stat(file_path, &tmp))
		return (-1);
	if (!S_ISDIR(tmp.st_mode))
		return (-1);
	return (tmp.st_uid);
}

int	ft_getuid(void)
{
	char	*file_path;
	int		uid;

	file_path = ft_tmpfile(1);
	open(file_path, O_CREAT);
	uid = ft_getuid_file(file_path);
	unlink(file_path);
	free(file_path);
	return (uid);
}
