/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_string.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/18 19:14:57 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRING_H
# define LIBFT_STRING_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# ifndef LIBFT_DEFINE_H
#  include "libft_define.h"
# endif

# include <stdlib.h>

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// ft_atoi_base.c
int			ft_atoi_base(char *nstr, const char *base);

// ft_atoi.c
int			ft_atoi(char *nstr);

// ft_atol.c
t_int64		ft_atol(char *nstr);

// ft_atol_base.c
t_int64		ft_atol_base(char *nstr, const char *base);

// ft_atou.c
t_uint64	ft_atou_base(char *nstr, const char *base);

// ft_atou_base.c
t_uint64	ft_atou_base(char *nstr, const char *base);

// ft_get_words.c
int			ft_get_words(char *str, char c);

// ft_split.c
char		**ft_split(char *s, char c);

// ft_strcat.c
char		*ft_strcat(char *dest, char *src);

// ft_strcchr.c
int			ft_strcchr(char *str, char c);

// ft_strchr.c
char		*ft_strchr(const char *s, int c);

// ft_strclr.c
void		ft_strclr(char *s);

// ft_strcmp.c
int			ft_strcmp(char *s1, char *s2);

// ft_strcpy.c
char		*ft_strcpy(char *dest, char *src);

// ft_strcspn.c
t_size		ft_strcspn(char *s, const char *rejects);

// ft_strdel.c
void		ft_strdel(char **as);

// ft_strdup.c
char		*ft_strdup(char *src);

// ft_striteri.c
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

// ft_strjoin.c
char		*ft_strjoin(char const *s1, char const *s2);

// ft_strlcat.c
t_uint32	ft_strlcat(char *dest, char *src, t_size size);

// ft_strlcpy.c
t_uint32	ft_strlcpy(char *dest, char *src, t_size size);

// ft_strlen.c
int			ft_strlen(char *str);

// ft_strmapi.c
char		*ft_strmapi(char const *s1, char (*f)(unsigned int, char));

// ft_strncat.c
char		*ft_strncat(char *dest, char *src, t_size n);

// ft_strncmp.c
int			ft_strncmp(char *s1, char *s2, t_size n);

// ft_strncpy.c
char		*ft_strncpy(char *dest, char *src, t_size n);

// ft_strnstr.c
char		*ft_strnstr(char *str, char *to_find, int n);

// ft_strrchr.c
char		*ft_strrchr(const char *s, int c);

// ft_strspn.c
size_t		ft_strspn(char *s, const char *accepts);

// ft_strtok.c
char		*ft_strtok(char *str, char *token);

// ft_strtrim.c
char		*ft_strtrim(char const *s1, char const *set);

// ft_substr.c
char		*ft_substr(char const *s, unsigned int start, t_size len);

// ft_tolower.c
int			ft_tolower(int c);

// ft_toupper.c
int			ft_toupper(int c);

/* ########################################################################## */

/* ########################################################################## */
/* REQUIREMENTS */
/* ############ */

# ifndef LIBFT_INTEGER
// ft_strlen.c
t_size		ft_nbrlen_base(const void *void_nbr, const char *base);

// ft_nbrlen.c
t_size		ft_nbrlen(const void *void_nbr);
# endif

# ifndef LIBFT_MEMORY
// ft_calloc.c
void		*ft_calloc(t_size nmemb, t_size size);

// ft_memset.c
void		*ft_memset(void *s, int c, t_size n);
# endif

/* ########################################################################## */

#endif
