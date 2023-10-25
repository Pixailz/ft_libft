/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_parsing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/25 12:23:44 by brda-sil         ###   ########.fr       */
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
	OPT_FLAG,
	OPT_SINGLE		= 1 << 0,
	OPT_MULTIPLE	= 1 << 1,
}	t_flag_opt;

typedef struct s_opt
{
	char			*opt_long;
	char			*opt_short;
	t_uint8			flag;
	char			**value;
	struct s_opt	*next;
}	t_opt;

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// parsing/ft_optadd.c
void		ft_optadd(char *opt_long, char *opt_short, t_uint8 flag);

// parsing/ft_optparse.c
void		ft_optparse(int ac, char **av);

// parsing/ft_sin_arg.c
t_opt		*ft_sin_arg(t_opt *opt);
void		ft_sin_free_arg(void);

/* ########################################################################## */

#endif // LIBFT_PARSING_H
