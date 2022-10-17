/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getgid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:12:24 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/15 11:55:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_linux.h"

int	ft_getgid_file(char *file_path)
{
	struct stat	tmp;

	if (stat(file_path, &tmp))
		return (-1);
	if (!S_ISREG(tmp.st_mode))
		return (-1);
	return (tmp.st_gid);
}

int	ft_getgid_dir(char *file_path)
{
	struct stat	tmp;

	if (stat(file_path, &tmp))
		return (-1);
	if (!S_ISDIR(tmp.st_mode))
		return (-1);
	return (tmp.st_gid);
}

int	ft_getgid(void)
{
	char	*file_path;
	int		gid;

	file_path = ft_tmpfile(1);
	open(file_path, O_CREAT);
	gid = ft_getgid_file(file_path);
	unlink(file_path);
	free(file_path);
	return (gid);
}
