/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_print.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/26 22:45:27 by brda-sil         ###   ########.fr       */
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

# define FT_PRINTF_PARAMS_LIST	"cspdiuxX%"

# define DEBUG_FD				420

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

# define P_FAIL			"[" RED "-" RST "]" SEP
# define P_PASS			"[" GREEN "+" RST "]" SEP
# define P_DEBG			"[" BLUE "*" RST "]" SEP
# define P_INFO			"[" CYAN "+" RST "]" SEP

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// print/ft_dprintf.c
int			ft_dprintf_parse(int fd, va_list args, const char *format);
size_t		ft_dprintf(int fd, const char *format, ...);

// print/ft_pdeb.c
t_size		ft_pdeb(const char *format, ...);

// print/ft_perr.c
int			ft_perr(const char *format, ...);

// print/ft_printf.c
int			ft_printf_parse(va_list args, const char *format);
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

// print/ft_vdprintf.c
size_t		ft_vdprintf(int fd, const char *format, va_list args);

// print/ft_vprintf.c
size_t		ft_vprintf(const char *format, va_list args);

/* ########################################################################## */

#endif // LIBFT_PRINT_H
