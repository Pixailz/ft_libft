/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_random.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2022/11/09 03:33:51 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_RANDOM_H
# define LIBFT_RANDOM_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# ifndef LIBFT_DEFINE_H
#  include "libft_define.h"
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

/* ########################################################################## */

/* ########################################################################## */
/* CONFIG */
/* ###### */

# define TMP_ST "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

/* ########################################################################## */

/* ########################################################################## */
/* REQUIREMENTS */
/* ############ */

# include "libft_define.h"
# include "libft_string.h"
# include "libft_memory.h"

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// ft_randint.c
t_int64		ft_randint(int start, int end);

// ft_tmpfile.c
char		*ft_tmpfile(int in_tmp);

/* ########################################################################## */

#endif
