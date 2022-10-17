/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isexec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:30:22 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/17 07:44:10 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_linux.h"

/**
 * @brief			check if path, absolute or not is executable
 *
 * @param file_path	path of the dir to test
 * @param mode
 * @note
 * 	Needed lib
 * 		sys/stat.h
 * @return (int)	TRUE if file_path is executable by the user, checking for
 * 					uid first and then by gid.
 * @note			executable = must have read and execute permission
 */
t_bool	ft_isexec(char *file_path)
{
	int	uid;
	int	uid_file;
	int	gid;
	int	gid_file;

	uid = ft_getuid();
	uid_file = ft_getuid_file(file_path);
	if (uid == uid_file)
	{
		if (ft_isfile(file_path, S_IXUSR | S_IRUSR) == 1)
			return (TRUE);
		else
			return (FALSE);
	}
	gid = ft_getgid();
	gid_file = ft_getgid_file(file_path);
	if (gid == gid_file)
	{
		if (ft_isfile(file_path, S_IXGRP | S_IRGRP) == 1)
			return (TRUE);
	}
	if (ft_isfile(file_path, S_IXOTH | S_IROTH) == 1)
		return (TRUE);
	return (FALSE);
}
