/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_print.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/12 19:48:32 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINT_H
# define LIBFT_PRINT_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# include <unistd.h>
/* write()
 **/

# include <stdarg.h>
/* va_arg()
 * va_list()
 * va_start()
 * va_end()
 **/

# include "libft_define.h"
# include "libft_integer.h"
# include "libft_memory.h"
# include "libft_string.h"

/* ########################################################################## */

/* ########################################################################## */
/* CONFIG */
/* ###### */

# define FT_PRINTF_PARAMS_LIST "cspdiuxX%"

/* ########################################################################## */

/* ########################################################################## */
/* ANSI CODE */
/* ###### */

# define ESC			"\x1b"
# define END			"\007"
# define BLACK			ESC "[30m" END
# define RED			ESC "[31m" END
# define GREEN			ESC "[32m" END
# define YELLOW			ESC "[33m" END
# define BLUE			ESC "[34m" END
# define PURPLE			ESC "[35m" END
# define CYAN			ESC "[36m" END
# define WHITE			ESC "[37m" END
# define RST			ESC "[00m" END

# define SEP			" → "

# define P_ERR			"[" RED "ERROR" RST "]" SEP

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// print/ft_dprintf.c
size_t		ft_dprintf(int fd, const char *format, ...);

// print/ft_perr.c
int			ft_perr(char *msg, int r_value);

// print/ft_printf.c
size_t		ft_printf(const char *format, ...);

// print/ft_putchar_fd.c
size_t		ft_putchar_fd(char c, int fd);

// print/ft_putendl_fd.c
size_t		ft_putendl_fd(char const *s, int fd);

// print/ft_putnbr_base_fd.c
size_t		ft_putnbr_base_fd(t_int64 n, const char *base, int fd);

// print/ft_putnbr_fd.c
size_t		ft_putnbr_fd(int n, int fd);

// print/ft_putstr_fd.c
size_t		ft_putstr_fd(char const *s, int fd);

// print/ft_putunbr_fd.c
size_t		ft_putunbr_fd(unsigned long n, int fd);

/* ########################################################################## */

#endif
