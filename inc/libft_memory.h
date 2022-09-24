/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_memory.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/24 21:24:30 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MEMORY_H
# define LIBFT_MEMORY_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# ifndef LIBFT_DEFINE_H
#  include "libft_define.h"
# endif

# include <stdlib.h>

/* ########################################################################## */

/* ########################################################################## */
/* REQUIREMENTS */
/* ############ */

# ifndef LIBFT_STRING_H
// ft_strlen.c
int		ft_strlen(char *str);
# endif

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// ft_bzero.c
void	ft_bzero(void *s, t_size n);

// ft_calloc.c
void	*ft_calloc(t_size nmemb, t_size size);

// ft_memchr.c
char	*ft_memchr(char *buf, unsigned char c);

// ft_memcmp.c
int		ft_memcmp(const void *s1, const void *s2, t_size n);

// ft_memcpy.c
void	*ft_memcpy(void *dest, const void *src, t_size n);

// ft_memjoin.c
char	*ft_memjoin(char *s1, char *s2);

// ft_memmove.c
void	*ft_memmove(void *dest, const void *src, t_size n);

// ft_memnchr.c
void	*ft_memnchr(const void *s, int c, t_size n);

// ft_memset.c
void	*ft_memset(void *s, int c, t_size n);

/* ########################################################################## */

#endif
