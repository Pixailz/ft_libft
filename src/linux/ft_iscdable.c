/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscdable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:13:57 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/14 01:40:32 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_linux.h"

t_bool	ft_iscdable(char *dir_name)
{
	int	uid;
	int	gid;
	int	uid_dir;
	int	gid_dir;

	uid = ft_getuid();
	gid = ft_getgid();
	uid_dir = ft_getuid_dir(dir_name);
	gid_dir = ft_getgid_dir(dir_name);
	if (uid == uid_dir)
	{
		if (ft_isdir(dir_name, S_IXUSR) == 1)
			return (TRUE);
		else
			return (FALSE);
	}
	if (gid == gid_dir)
		if (ft_isdir(dir_name, S_IXGRP) == 1)
			return (TRUE);
	if (ft_isdir(dir_name, S_IXOTH) == 1)
		return (TRUE);
	return (FALSE);
}
