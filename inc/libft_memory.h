/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_memory.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2023/07/31 18:28:59 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MEMORY_H
# define LIBFT_MEMORY_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# include <stdlib.h>

# include "libft_define.h"
# include "libft_string.h"

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// memory/ft_bzero.c
void	ft_bzero(void *s, t_size n);

// memory/ft_calloc.c
void	*ft_calloc(t_size nmemb, t_size size);

// memory/ft_free_char_pp.c
void	ft_free_char_pp(char **str_str);

// memory/ft_memchr.c
char	*ft_memchr(char *buf, unsigned char c);

// memory/ft_memcmp.c
int		ft_memcmp(const void *s1, const void *s2, t_size n);

// memory/ft_memcpy.c
void	*ft_memcpy(void *dest, const void *src, t_size n);

// memory/ft_memjoin.c
char	*ft_memjoin(char *s1, char *s2);

// memory/ft_memmove.c
void	*ft_memmove(void *dest, const void *src, t_size n);

// memory/ft_memnchr.c
void	*ft_memnchr(const void *s, int c, t_size n);

// memory/ft_memset.c
void	*ft_memset(void *s, int c, t_size n);

/* ########################################################################## */

#endif
