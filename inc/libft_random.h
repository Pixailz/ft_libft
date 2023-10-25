/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_random.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/24 14:30:06 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_RANDOM_H
# define LIBFT_RANDOM_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft_define.h"
# include "libft_string.h"
# include "libft_memory.h"

/* ########################################################################## */

/* ########################################################################## */
/* CONFIG */
/* ###### */

# define TMP_ST "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// random/ft_randint.c
t_int64		ft_randint(int start, int end);

// random/ft_tmpfile.c
char		*ft_tmpfile(int in_tmp);

/* ########################################################################## */

#endif // LIBFT_RANDOM_H
