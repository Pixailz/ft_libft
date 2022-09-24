/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_integer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/24 21:50:41 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_INTEGER_H
# define LIBFT_INTEGER_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# ifndef LIBFT_DEFINE_H
#  include "libft_define.h"
# endif

# include <limits.h>

/* ########################################################################## */

/* ########################################################################## */
/* DEFINE */
/* ###### */

/* ########################################################################## */

/* ########################################################################## */
/* REQUIREMENTS */
/* ############ */

# ifndef LIBFT_STRING
// ft_strlen.c
int		ft_strlen(char *str);
# endif

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// ft_get_base.c
int		ft_get_base(int c, const char *base);

// ft_itoa.c
char	*ft_itoa(const int const_nb);

// ft_itoa_base.c
char	*ft_itoa_base(const t_int64 const_nb, const char *base);

// ft_ltoa.c
char	*ft_ltoa(const t_int64 const_nb);

// ft_ltoa_base.c
char	*ft_ltoa_base(const t_int64 const_nb, const char *base);

// ft_nbrlen.c
t_size	ft_nbrlen(const void *void_nbr);

// ft_nbrlen_base.c
t_size	ft_nbrlen_base(const void *void_nbr, const char *base);

// ft_rev_int.c
int		ft_rev_int(int nb);

// ft_utoa.c
char	*ft_utoa(const t_uint64 const_nb);

// ft_utoa_base.c
char	*ft_utoa_base(const t_uint64 const_nb, const char *base);

/* ########################################################################## */

#endif
