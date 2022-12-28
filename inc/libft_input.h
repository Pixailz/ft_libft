/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2022/11/09 03:36:15 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_INPUT_H
# define LIBFT_INPUT_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

/* ########################################################################## */

/* ########################################################################## */
/* REQUIREMENTS */
/* ############ */

# include "libft_define.h"
# include "libft_string.h"
# include "libft_memory.h"

/* ########################################################################## */

/* ########################################################################## */
/* CONFIG */
/* ###### */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0x2a
# endif
# ifndef MAX_FD
#  define MAX_FD 0x400
# endif

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// ft_get_next_line.c
char	*ft_get_next_line(int fd);

/* ########################################################################## */

#endif
