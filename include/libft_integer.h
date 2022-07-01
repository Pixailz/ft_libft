/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_integer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2022/07/01 12:26:39 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_INTEGER_H
# define LIBFT_INTEGER_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# include "libft.h"
# include <limits.h>

/* ########################################################################## */

/* ########################################################################## */
/* DEFINE */
/* ###### */

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

# ifndef LIBFT_STRING
// ft_strlen.c
int		ft_strlen(char *str);
# endif

// ft_atoi_base.c
int		ft_atoi_base(char *nstr, const char *base);

// ft_atoi.c
int		ft_atoi(char *nstr);

// ft_atol.c
t_int64	ft_atol(char *nstr);

// ft_nbrlen_base.c
t_size	ft_nbrlen_base(const void *void_nbr, const char *base);

// ft_nbrlen.c
t_size	ft_nbrlen(const void *void_nbr);

// ft_rev_int.c
int		ft_rev_int(int nb);

/* ########################################################################## */

#endif
