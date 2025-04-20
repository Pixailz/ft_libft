/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_check.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/21 11:16:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_CHECK_H
# define LIBFT_CHECK_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# include <limits.h>
# include <sys/stat.h>

# include "libft_define.h"

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// check/ft_is_str.c

t_bool	ft_is_str(const char *str, t_bool func(char));

// check/ft_isalnum.c

t_bool	ft_isalnum(const char c);

// check/ft_isalpha.c

t_bool	ft_isalpha(const char c);

// check/ft_isascii.c

t_bool	ft_isascii(const char c);

// check/ft_isblank.c

t_bool	ft_isblank(const char c);

// check/ft_isdigit.c

t_bool	ft_isdigit(const char c);

// check/ft_isgoodi.c

int		ft_isgoodi(int n, int neg);

// check/ft_isgoodll.c

int		ft_isgoodll(t_int64 n, int neg);

// check/ft_isgoodu.c

t_bool	ft_isgoodu(t_uint32 n, int is_last);

// check/ft_islower.c

t_bool	ft_islower(char c);

// check/ft_isprint.c

t_bool	ft_isprint(const char c);

// check/ft_isspace.c

t_bool	ft_isspace(const char c);

// check/ft_isupper.c

t_bool	ft_isupper(char c);

/* ########################################################################## */

#endif /* LIBFT_CHECK_H */
