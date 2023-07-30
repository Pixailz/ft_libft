/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_print.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2023/07/30 05:31:23 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINT_H
# define LIBFT_PRINT_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# ifndef LIBFT_DEFINE_H
#  include "libft_define.h"
# endif

# include <unistd.h>
/* write()
 **/

# include <stdarg.h>
/* va_arg()
 * va_list()
 * va_start()
 * va_end()
 **/

/* ########################################################################## */

/* ########################################################################## */
/* CONFIG */
/* ###### */

# define FT_PRINTF_PARAMS_LIST "cspdiuxX%"

/* ########################################################################## */

/* ########################################################################## */
/* ANSI CODE */
/* ###### */

# define	ESC			"\x1b"
# define	BLACK		ESC "[30m"
# define	RED			ESC "[31m"
# define	GREEN		ESC "[32m"
# define	YELLOW		ESC "[33m"
# define	BLUE		ESC "[34m"
# define	PURPLE		ESC "[35m"
# define	CYAN		ESC "[36m"
# define	WHITE		ESC "[37m"
# define	RST			ESC "[00m"

# define	SEP		" → "

/* ########################################################################## */

/* ########################################################################## */
/* REQUIREMENTS */
/* ############ */

# include "libft_define.h"
# include "libft_integer.h"
# include "libft_memory.h"
# include "libft_string.h"

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// ft_printf.c
size_t	ft_printf(const char *format, ...);

// ft_dprintf.c
size_t	ft_dprintf(int fd, const char *format, ...);

// ft_putchar_fd.c
size_t	ft_putchar_fd(char c, int fd);

// ft_putendl_fd.c
size_t	ft_putendl_fd(char const *s, int fd);

// ft_putnbr_base_fd.c
size_t	ft_putnbr_base_fd(t_int64 n, const char *base, int fd);

// ft_putnbr_fd.c
size_t	ft_putnbr_fd(int n, int fd);

// ft_putstr_fd.c
size_t	ft_putstr_fd(char const *s, int fd);

// ft_putunbr_fd.c
size_t	ft_putunbr_fd(unsigned long n, int fd);

/* ########################################################################## */

#endif
