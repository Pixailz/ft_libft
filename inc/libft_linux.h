/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_linux.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2024/02/24 00:51:19 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LINUX_H
# define LIBFT_LINUX_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft_define.h"
# include "libft_random.h"
# include "libft_check.h"

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// linux/ft_getgid.c
int			ft_getgid_file(char *file_path);
int			ft_getgid_dir(char *file_path);
int			ft_getgid(void);

// linux/ft_getuid.c
int			ft_getuid_file(char *file_path);
int			ft_getuid_dir(char *file_path);
int			ft_getuid(void);

// linux/ft_iscdable.c
t_bool		ft_iscdable(char *dir_path);

// linux/ft_isdir.c
int			ft_isdir(char *dir_path, int mode);

// linux/ft_isexec.c
t_bool		ft_isexec(char *file_path);

// linux/ft_isfile.c
int			ft_isfile(char *file_path, int mode);

/* ########################################################################## */

#endif /* LIBFT_LINUX_H */
