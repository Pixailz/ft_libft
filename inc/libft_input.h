/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/24 21:23:59 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_INPUT_H
# define LIBFT_INPUT_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# ifndef LIBFT_DEFINE_H
#  include "libft_define.h"
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

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
/* REQUIREMENTS */
/* ############ */

# ifndef LIBFT_MEMORY_H
// ft_memchr.c
char	*ft_memchr(char *buf, unsigned char c);

// ft_memjoin.c
char	*ft_memjoin(char *s1, char *s2);
# endif

# ifndef LIBFT_STRING_H
// ft_strlen.c
int		ft_strlen(char *str);
# endif

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// ft_get_next_line.c
char	*ft_get_next_line(int fd);
char	*ft_line(char *buf);
char	*ft_read(int fd, char *buf);
char	*ft_stash(char *s);

/* ########################################################################## */

#endif
