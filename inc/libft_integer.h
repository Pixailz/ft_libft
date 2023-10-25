/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_integer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/24 14:29:42 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_INTEGER_H
# define LIBFT_INTEGER_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# include <limits.h>

# include "libft_define.h"
# include "libft_string.h"

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// integer/ft_get_base.c
int			ft_get_base(int c, const char *base);

// integer/ft_int4_chg.c
void		ft_int4_chg(t_int4 *n, int level, t_int1 change);

// integer/ft_int4_comp.c
t_int4		ft_int4_comp(t_int1 n1, t_int1 n2, t_int1 n3, t_int1 n4);

// integer/ft_int4_dcomp.c
t_int1		ft_int4_dcomp(t_int4 n, int level);

// integer/ft_int4_dec.c
void		ft_int4_dec(t_int4 *n, int level);

// integer/ft_int4_inc.c
void		ft_int4_inc(t_int4 *n, int level);

// integer/ft_itoa.c
char		*ft_itoa(const int const_nb);

// integer/ft_itoa_base.c
char		*ft_itoa_base(const t_int64 const_nb, const char *base);

// integer/ft_ltoa.c
char		*ft_ltoa(const t_int64 const_nb);

// integer/ft_ltoa_base.c
char		*ft_ltoa_base(const t_int64 const_nb, const char *base);

// integer/ft_nbrlen.c
t_size		ft_nbrlen(const void *void_nbr);

// integer/ft_nbrlen_base.c
t_size		ft_nbrlen_base(const void *void_nbr, const char *base);

// integer/ft_rev_int.c
int			ft_rev_int(int nb);

// integer/ft_utoa.c
char		*ft_utoa(const t_uint64 const_nb);

// integer/ft_utoa_base.c
char		*ft_utoa_base(const t_uint64 const_nb, const char *base);

/* ########################################################################## */

#endif // LIBFT_INTEGER_H
