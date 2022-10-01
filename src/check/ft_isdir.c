/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 03:26:51 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/01 02:23:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_check.h"

/**
 * @brief			check if path, absolute or not is a directory, therefor
 * 					check if have persmission
 *
 * @param dir_path	path of the dir to test
 * @param mode
 * @note
 * 	Needed lib
 * 		sys/stat.h
 * @return (int)	1 if, dir_path, is a directory and have permission,
 * 					2 if not a directory, otherwise return 0
 */
int	ft_isdir(char *dir_name, int mode)
{
	struct stat	tmp;
	int			error_code;

	if (stat(dir_name, &tmp))
		return (0);
	if (!S_ISDIR(tmp.st_mode))
		return (2);
	error_code = tmp.st_mode & mode;
	return (error_code == mode);
}
