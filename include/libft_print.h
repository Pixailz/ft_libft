/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_print.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2022/07/05 03:30:13 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINT_H
# define LIBFT_PRINT_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# include "libft.h"

# include <unistd.h>
# include <stdarg.h>

/* ########################################################################## */

/* ########################################################################## */
/* CONFIG */
/* ###### */

# define FT_PRINTF_PARAMS_LIST "cspdiuxX%"

/* ########################################################################## */

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

# ifndef LIBFT_STRING_H
// ft_itoa_base.c
char	*ft_itoa_base(const int const_nb, const char *base);
# endif

# ifndef LIBFT_INTEGER
// ft_strlen.c
t_size	ft_nbrlen_base(const void *void_nbr, const char *base);
# endif

# ifndef LIBFT_MEMORY
// ft_calloc.c
void	*ft_calloc(t_size nmemb, t_size size);

// ft_memset.c
void	*ft_memset(void *s, int c, t_size n);
# endif
// ft_putchar_fd.c
size_t	ft_putchar_fd(char c, int fd);

// ft_putendl_fd.c
size_t	ft_putendl_fd(char const *s, int fd);

// ft_putnbr_fd.c
size_t	ft_putnbr_fd(int n, int fd);

// ft_putunbr_fd.c
size_t	ft_putunbr_fd(unsigned long n, int fd);

// ft_putstr_fd.c
size_t	ft_putstr_fd(char const *s, int fd);

// ft_printf.c
size_t	ft_printf(const char *format, ...);

/* ########################################################################## */

#endif
