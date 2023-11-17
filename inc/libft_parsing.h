/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_parsing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/17 12:20:27 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PARSING_H
# define LIBFT_PARSING_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# include <unistd.h>
# include "libft_define.h"
# include "libft_memory.h"
# include "libft_print.h"

/* ########################################################################## */

/* ########################################################################## */
/* CONFIG */
/* ###### */

typedef enum e_flag_opt
{
	OPT_FLAG		= BIT_01,
	OPT_SINGLE		= BIT_02,
	OPT_MULTIPLE	= BIT_03,
}	t_flag_opt;

typedef enum e_err_opt
{
	ERR_ALLGOOD		= BIT_00,
	ERR_UNK_OPT		= BIT_01,
}	t_err_opt;

typedef struct s_opt_value
{
	char				*value;
	struct s_opt_value	*next;
}	t_opt_value;

typedef struct s_opt
{
	char			*name;
	char			opt_short;
	t_bool			is_present;
	t_bin			flag;
	t_opt_value		*value;
	struct s_opt	*next;
}	t_opt;

typedef enum e_opt_order_type
{
	OPT_ORD_OPT		= BIT_01,
	OPT_ORD_VAL		= BIT_02,
	OPT_ORD_END		= BIT_03,
}	t_opt_order_type;

typedef struct s_opt_order
{
	t_bin				type;
	t_opt				*opt;
	char				*value;
	struct s_opt_order	*next;
}	t_opt_order;

typedef struct s_opts
{
	t_opt		*opt;
	int			ac;
	char		**av;
	t_opt_value	*value;
	t_opt		*last_parsed_opt;
	int			parse_index;
	t_opt_order	*opt_order;
	t_bool		opt_finished;
	t_bin		err;
	char		*err_param_name;
	char		err_param_short;
}	t_opts;

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// parsing/ft_is_optpresent.c
t_bool		ft_is_optpresent(char *name);

// parsing/ft_opt.c
t_opts		*ft_get_opts(t_bool free);

// parsing/ft_opt_long.c
t_bool		ft_is_optlong(char *arg);
t_bool		ft_optlong_parse(char *arg);

// parsing/ft_opt_other.c
void		ft_optvalue_append(t_opt_value *dst, t_opt_value *src);
void		ft_optother_parse(char *arg);

// parsing/ft_opt_other_last_parsed.c
void		ft_optother_parse_flag(t_opt_value *src, t_opt_value *dst);
void		ft_opt_other_last_parsed(t_opt_value *src);

// parsing/ft_opt_short.c
t_bool		ft_is_optshort(char *arg);
t_bool		ft_optshort_parse(char *arg);

// parsing/ft_optadd.c
void		ft_optadd(char *name, char opt_short, t_uint8 flag);

// parsing/ft_optfree.c
void		ft_free_opt_value(t_opt_value *value);
void		ft_free_opt_order(t_opt_order *order);
void		ft_free_opt(t_opt *opt);
void		ft_free_opts(void);

// parsing/ft_optget.c
t_opt		*ft_optget(char *name);

// parsing/ft_optorder.c
void		ft_optorder_add(t_opt_order_type type, char *val);

// parsing/ft_optparse.c
void		ft_optparse(int ac, char **av);

// parsing/ft_optperr.c
void		ft_opt_perr(void);

// parsing/ft_optprint.c
void		ft_print_opt_value(t_opt_value *value);
void		ft_print_opt(t_opt opt);
void		ft_print_opts_order(t_opt_order *ptr);
void		ft_print_opts(void);

/* ########################################################################## */

#endif // LIBFT_PARSING_H
