/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getuid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:12:24 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/01 02:35:22 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_linux.h"

int	ft_getuid_file(char *file_name)
{
	struct stat	tmp;

	if (stat(file_name, &tmp))
		return (-1);
	if (!S_ISREG(tmp.st_mode))
		return (-1);
	return (tmp.st_uid);
}

int	ft_getuid_dir(char *file_name)
{
	struct stat	tmp;

	if (stat(file_name, &tmp))
		return (-1);
	if (!S_ISDIR(tmp.st_mode))
		return (-1);
	return (tmp.st_uid);
}

int	ft_getuid(void)
{
	char	*file_name;
	int		uid;

	file_name = ft_tmpfile(1);
	open(file_name, O_CREAT);
	uid = ft_getuid_file(file_name);
	unlink(file_name);
	free(file_name);
	return (uid);
}
