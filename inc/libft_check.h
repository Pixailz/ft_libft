/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_check.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2022/11/09 03:30:32 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_CHECK_H
# define LIBFT_CHECK_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# include <limits.h>
# include <sys/stat.h>

/* ########################################################################## */

/* ########################################################################## */
/* REQUIREMENTS */
/* ############ */

# include "libft_define.h"

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// ft_is_str.c
t_bool	ft_is_str(const char *str, t_bool func(char));

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
t_bool	ft_isgoodi(int n, int neg);

// ft_isgoodll.c
int		ft_isgoodll(t_int64 n, int neg);

// ft_isgoodu.c
t_bool	ft_isgoodu(t_uint32 n, int is_last);

// ft_isprint.c
t_bool	ft_isprint(const char c);

// ft_isspace.c
t_bool	ft_isspace(const char c);

/* ########################################################################## */

#endif
