/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_print.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2024/03/31 21:25:59 by brda-sil         ###   ########.fr       */
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
# include "libft_ansi.h"

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
	FMT_UNKN = -1,
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

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// print/ft_dprintf.c

t_size	ft_dprintf(int fd, const char *format, ...);

// print/ft_pdeb.c

t_size	ft_pdeb(const char *format, ...);

// print/ft_perr.c

int		ft_perr(const char *format, ...);

// print/ft_printf.c

t_size	ft_printf(const char *format, ...);

// print/ft_printf/flag/hash.c

void	ft_printf_flag_hash(char type, t_bin *flags);

// print/ft_printf/flag/minus.c

void	ft_printf_flag_minus(char type, t_bin *flags);

// print/ft_printf/flag/plus.c

void	ft_printf_flag_plus(char type, t_bin *flags);

// print/ft_printf/flag/space.c

void	ft_printf_flag_space(char type, t_bin *flags);

// print/ft_printf/flag/zero.c

void	ft_printf_flag_zero(char type, t_bin *flags);

// print/ft_printf/fmt/addr.c

void	ft_printf_type_addr(t_fmt_conf *conf, va_list args);

// print/ft_printf/fmt/begin.c

void	ft_printf_type_begin(t_fmt_conf *conf, va_list args);

// print/ft_printf/fmt/char.c

void	ft_printf_type_char(t_fmt_conf *conf, va_list args);

// print/ft_printf/fmt/hexa.c

void	ft_printf_type_hex(t_fmt_conf *conf, va_list args);
void	ft_printf_type_hexa(t_fmt_conf *conf, va_list args);

// print/ft_printf/fmt/integer.c

void	ft_printf_type_integer(t_fmt_conf *conf, va_list args);

// print/ft_printf/fmt/string.c

void	ft_printf_type_string(t_fmt_conf *conf, va_list args);

// print/ft_printf/fmt/unsigned.c

void	ft_printf_type_unsigned(t_fmt_conf *conf, va_list args);

// print/ft_printf/ft_printf_buffer.c

void	ft_printf_buff_reset(void);
char	*ft_printf_buff_get(void);

// print/ft_printf/ft_printf_flags.c

t_bin	ft_printf_fmt_get_flags(int *i, const char *format);

// print/ft_printf/ft_printf_main.c

void	ft_printf_fmt_setup(t_fmt_conf *conf, int *i_fmt, \
												const char *format);
void	ft_printf_fmt_parse(int *i_fmt, int *i_buff, \
											const char *format, va_list args);
t_size	ft_printf_parse(va_list args, const char *format);

// print/ft_printf/ft_printf_padding.c

char	ft_printf_type_padding_remove_sign(char *str);
void	ft_printf_type_padding(t_fmt_conf *conf);

// print/ft_printf/ft_printf_precision.c

t_size	ft_printf_fmt_get_precision(int *i_fmt, const char *format);

// print/ft_printf/ft_printf_type.c

void	ft_printf_type_sign(t_fmt_conf *conf);
void	ft_printf_fmt_get_type(t_fmt_conf *conf, va_list args);

// print/ft_printf/ft_printf_width.c

t_size	ft_printf_fmt_get_width(int *i_fmt, const char *format);

// print/ft_printf/padding/addr.c

void	ft_printf_type_padding_addr_short(t_fmt_conf *conf, char *buff, \
											t_size str_len);
void	ft_printf_type_padding_addr(t_fmt_conf *conf);

// print/ft_printf/padding/char.c

void	ft_printf_type_padding_char(t_fmt_conf *conf);

// print/ft_printf/padding/hex.c

void	ft_printf_type_padding_hex_hashtag(t_fmt_conf *conf, \
													t_size str_len);
void	ft_printf_type_padding_hex_post(t_fmt_conf *conf, char sign, \
																t_size str_len);
void	ft_printf_type_padding_hex_pad(t_fmt_conf *conf, t_size begin, \
																int to_pad);
void	ft_printf_type_padding_hex(t_fmt_conf *conf);

// print/ft_printf/padding/integer.c

void	ft_printf_type_padding_integer_post(t_fmt_conf *conf, char sign, \
											char *buff);
void	ft_printf_type_padding_integer_pad(t_fmt_conf *conf, t_size begin, \
																	int to_pad);
void	ft_printf_type_padding_integer(t_fmt_conf *conf);

// print/ft_printf/padding/string.c

void	ft_printf_type_padding_string(t_fmt_conf *conf);

// print/ft_putchar_fd.c

size_t	ft_putchar_fd(char c, int fd);

// print/ft_putendl_fd.c

size_t	ft_putendl_fd(char const *s, int fd);

// print/ft_putnbr_base_fd.c

size_t	ft_putnbr_base_fd(t_int64 n, const char *base, int fd);

// print/ft_putnbr_fd.c

size_t	ft_putnbr_fd(int n, int fd);

// print/ft_putstr_fd.c

size_t	ft_putstr_fd(char const *s, int fd);
size_t	ft_putnstr_fd(char const *s, t_size n, int fd);

// print/ft_putunbr_fd.c

size_t	ft_putunbr_fd(unsigned long n, int fd);

// print/ft_rainbow_c.c

char	*RAINBOW_C(int i);

// print/ft_sprintf.c

t_size	ft_sprintf(char *buff, const char *format, ...);

// print/ft_vdprintf.c

t_size	ft_vdprintf(int fd, const char *format, va_list args);

// print/ft_vprintf.c

t_size	ft_vprintf(const char *format, va_list args);

// print/ft_vsprintf.c

t_size	ft_vsprintf(char *buff, const char *format, va_list args);

/* ########################################################################## */

#endif /* LIBFT_PRINT_H */
