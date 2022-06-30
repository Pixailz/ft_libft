/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_int.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2022/06/30 21:49:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_INT_H
# define LIBFT_INT_H

/* ########################################################################## */
/* DEFINE */
/* ###### */

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define LONG_MAX 2147483647
# define LONG_MIN -2147483648
# define LLONG_MAX 9223372036854775807L
# define LLONG_MAX -9223372036854775808L
# define UINT_MAX 0xffffffffU
# define ULONG_MAX 0xffffffffU
# define ULLONG_MAX 0xffffffffffffffffUL

/* ########################################################################## */

/* ########################################################################## */
/* TYPEDEF */
/* ####### */

typedef unsigned char		t_uint8;
typedef unsigned int		t_uint32;
typedef long long			t_int64;
typedef unsigned long		t_size;

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// ft_atoi.c
int			ft_atoi(char *nptr);

// ft_atol.c
long		ft_atol(char *nbr_str);

// ft_atoll.c
long long	ft_atoll(char *nbr_str);

// ft_nbrlen.c
int			ft_nbrlen(long int nb);

// ft_rev_int.c
int			ft_rev_int(int nb);

/* ########################################################################## */

#endif
