/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_check.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/01 18:36:13 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_CHECK_H
# define LIBFT_CHECK_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# ifndef LIBFT_DEFINE_H
#  include "libft_define.h"
# endif

# include <limits.h>
# include <sys/stat.h>

/* ########################################################################## */

/* ########################################################################## */
/* CONFIG */
/* ###### */

/* ########################################################################## */

/* ########################################################################## */
/* TYPEDEF */
/* ####### */

/* ########################################################################## */

/* ########################################################################## */
/* STRUCT */
/* ###### */

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// ft_isalnum.c
int		ft_isalnum(const char c);

// ft_isalpha.c
int		ft_isalpha(const char c);

// ft_isascii.c
int		ft_isascii(const char c);

// ft_isblank.c
int		ft_isblank(const char c);

// ft_isdigit.c
int		ft_isdigit(const char c);

// ft_isdir.c
int		ft_isdir(char *dir_name, int mode);

// ft_isfile.c
int		ft_isfile(char *file_path, int mode);

// ft_isgoodi.c
t_bool	ft_isgoodi(int n, int neg);

// ft_isgoodll.c
t_bool	ft_isgoodll(t_int64 n, int neg);

// ft_isgoodu.c
t_bool	ft_isgoodu(t_uint32 n, int is_last);

// ft_isprint.c
int		ft_isprint(const char c);

// ft_isspace.c
int		ft_isspace(const char c);

/* ########################################################################## */

#endif
