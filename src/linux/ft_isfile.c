/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 03:26:51 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/15 12:26:22 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_check.h"

/**
 * @brief			check if path, absolute or not is a file, therefor check if
 * 					have persmission
 *
 * @param file_path	path of the file to test
 * @param mode
 * @note
 * 	Needed lib
 * 		sys/stat.h
 * @return (int)	1 if, file_path, is a file and have permission,
 * 					2 if not a file, otherwise return 0
 */
int	ft_isfile(char *file_path, int mode)
{
	struct stat	tmp;
	int			error_code;

	if (stat(file_path, &tmp))
		return (0);
	if (!S_ISREG(tmp.st_mode))
		return (2);
	error_code = tmp.st_mode & mode;
	return (error_code == mode);
}
