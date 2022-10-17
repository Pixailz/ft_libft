/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_check.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/17 09:29:20 by brda-sil         ###   ########.fr       */
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
t_bool	ft_isalnum(const char c);

// ft_isalpha.c
t_bool	ft_isalpha(const char c);

// ft_isascii.c
t_bool	ft_isascii(const char c);

// ft_isblank.c
t_bool	ft_isblank(const char c);

// ft_isdigit.c
t_bool	ft_isdigit(const char c);

// ft_isgoodi.c
int		ft_isgoodi(int n, int neg);

// ft_isgoodll.c
int		ft_isgoodll(t_int64 n, int neg);

// ft_isgoodu.c
t_bool	ft_isgoodu(t_uint32 n, int is_last);

// ft_isprint.c
t_bool	ft_isprint(const char c);

// ft_isspace.c
t_bool	ft_isspace(const char c);

// ft_sisprint.c
t_bool	ft_sisprint(const char *str);

// ft_sisspace.c
t_bool	ft_sisspace(const char *str);

// ft_sisalnum.c
t_bool	ft_sisalnum(const char *str);

// ft_sisalpha.c
t_bool	ft_sisalpha(const char *str);

// ft_sisascii.c
t_bool	ft_sisascii(const char *str);

// ft_sisblank.c
t_bool	ft_sisblank(const char *str);

// ft_sisdigit.c
t_bool	ft_sisdigit(const char *str);

/* ########################################################################## */

#endif
