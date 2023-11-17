/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_print.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/17 08:38:06 by brda-sil         ###   ########.fr       */
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

# ifndef NO_ANSI

// BASE
#  define ESC			"\x1b"
#  define END			""

// COLOR
#  define BLA			ESC "[30m" END			// BLACK
#  define RED			ESC "[31m" END			// RED
#  define GRE			ESC "[32m" END			// GREEN
#  define YEL			ESC "[33m" END			// YELLOW
#  define BLU			ESC "[34m" END			// BLUE
#  define PUR			ESC "[35m" END			// PURPLE
#  define CYA			ESC "[36m" END			// CYAN
#  define WHI			ESC "[37m" END			// WHITE
#  define ORA			ESC "[38;5;208m" END	// ORANGE
#  define PIN			ESC "[38;5;218m" END	// PINK

// MODIFIER
#  define RST			ESC "[0m" END
#  define BOL			ESC "[1m" END
#  define ITA			ESC "[3m" END
#  define UND			ESC "[4m" END
#  define BLI			ESC "[5m" END

# else

// BASE
#  define ESC			""
#  define END			""

// COLOR
#  define BLA			""
#  define RED			""
#  define GRE			""
#  define YEL			""
#  define BLU			""
#  define PUR			""
#  define CYA			""
#  define WHI			""
#  define ORA			""
#  define PIN			""

// MODIFIER
#  define RST			""
#  define BOL			""
#  define ITA			""
#  define UND			""
#  define BLI			""

# endif // NO_ANSI

// COMPOSITE
# define SEP			" → "

# define P_ERRO			"[" RED "ERRO" RST "]" SEP
# define P_FAIL			"[" RED "FAIL" RST "]" SEP
# define P_PASS			"[" GRE "PASS" RST "]" SEP
# define P_DEBG			"[" BLU "DEBG" RST "]" SEP
# define P_INFO			"[" CYA "INFO " RST "]" SEP

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
