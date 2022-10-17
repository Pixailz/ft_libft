/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscdable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:13:57 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/15 11:56:17 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_linux.h"

t_bool	ft_iscdable(char *dir_path)
{
	int	uid;
	int	uid_dir;
	int	gid;
	int	gid_dir;

	uid = ft_getuid();
	uid_dir = ft_getuid_dir(dir_path);
	if (uid == uid_dir)
	{
		if (ft_isdir(dir_path, S_IXUSR) == 1)
			return (TRUE);
		else
			return (FALSE);
	}
	gid = ft_getgid();
	gid_dir = ft_getgid_dir(dir_path);
	if (gid == gid_dir)
		if (ft_isdir(dir_path, S_IXGRP) == 1)
			return (TRUE);
	if (ft_isdir(dir_path, S_IXOTH) == 1)
		return (TRUE);
	return (FALSE);
}
