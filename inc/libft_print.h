/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_print.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/01 10:38:06 by brda-sil         ###   ########.fr       */
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

# define FT_PRINTF_BUFF_BIG		0x400
# define FT_PRINTF_BUFF_MED		0x200
# define FT_PRINTF_BUFF_SMALL	0x100

# define FT_PRINTF_FMT_BEGIN	'%'

# define FT_PRINTF_FMT_TYPE		"%cspdiuxX"

# define FT_PRINTF_FLAG_MINUS	BIT_01
# define FT_PRINTF_FLAG_PLUS	BIT_02
# define FT_PRINTF_FLAG_SPACE	BIT_03
# define FT_PRINTF_FLAG_HASH	BIT_04
# define FT_PRINTF_FLAG_ZERO	BIT_05

typedef enum e_fmt_type
{
	FMT_UNKN = 0,
	FMT_PERC,
	FMT_CHAR,
	FMT_STRI,
	FMT_PTR,
	FMT_DIGI,
	FMT_INTE,
	FMT_UNSI,
	FMT_HEX,
	FMT_HEXA,
}	t_fmt_type;

typedef struct s_fmt_conf
{
	t_bin			flags;
	t_size			width;
	t_size			precision;
	t_fmt_type		fmt_type;
	char			cur_type[FT_PRINTF_BUFF_SMALL];
	int				*i_fmt;
	int				*i_buff;
	const char		*fmt;
}	t_fmt_conf;

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

// print/ft_printf/flag/hash.c
void		ft_printf_flag_hash(char type, t_bin *flags);

// print/ft_printf/flag/minus.c
void		ft_printf_flag_minus(char type, t_bin *flags);

// print/ft_printf/flag/plus.c
void		ft_printf_flag_plus(char type, t_bin *flags);

// print/ft_printf/flag/space.c
void		ft_printf_flag_space(char type, t_bin *flags);

// print/ft_printf/flag/zero.c
void		ft_printf_flag_zero(char type, t_bin *flags);

// print/ft_printf/fmt/addr.c
void		ft_printf_type_addr(t_fmt_conf *conf, va_list args);

// print/ft_printf/fmt/begin.c
void		ft_printf_type_begin(t_fmt_conf *conf, va_list args);

// print/ft_printf/fmt/char.c
void		ft_printf_type_char(t_fmt_conf *conf, va_list args);

// print/ft_printf/fmt/hexa.c
void		ft_printf_type_hex(t_fmt_conf *conf, va_list args);
void		ft_printf_type_hexa(t_fmt_conf *conf, va_list args);

// print/ft_printf/fmt/integer.c
void		ft_printf_type_integer(t_fmt_conf *conf, va_list args);

// print/ft_printf/fmt/string.c
void		ft_printf_type_string(t_fmt_conf *conf, va_list args);

// print/ft_printf/fmt/unsigned.c
void		ft_printf_type_unsigned(t_fmt_conf *conf, va_list args);

// print/ft_printf/ft_printf.c
void		ft_printf_fmt_parse(int *i_fmt, int *i_buff, \
											const char *format, va_list args);
void		ft_printf_2_parse(va_list args, const char *format);
t_size		ft_printf_2(const char *format, ...);

// print/ft_printf/ft_printf_buffer.c
void		ft_printf_buff_reset(void);
char		*ft_printf_buff_get(void);

// print/ft_printf/ft_printf_flags.c
t_bin		ft_printf_fmt_get_flags(int *i, const char *format);

// print/ft_printf/ft_printf_padding.c
void		ft_printf_type_padding_hex(t_fmt_conf *conf);
void		ft_printf_type_padding(t_fmt_conf *conf);

// print/ft_printf/ft_printf_precision.c
t_size		ft_printf_fmt_get_precision(int *i_fmt, const char *format);

// print/ft_printf/ft_printf_type.c
void		ft_printf_type_sign(t_fmt_conf *conf);
void		ft_printf_fmt_get_type(t_fmt_conf *conf, va_list args);

// print/ft_printf/ft_printf_width.c
t_size		ft_printf_fmt_get_width(int *i_fmt, const char *format);

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
