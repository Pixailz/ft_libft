/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_str.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2022/06/30 21:49:03 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STR_H
# define LIBFT_STR_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# include "libft_int.h"

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// ft_get_words.c
int			ft_get_words(char *str, char c);

// ft_itoa.c
char		*ft_itoa(int nb);

// ft_ltoa.c
long		ft_atol(char *nbr_str);

// ft_split.c
char		**ft_split(char *s, char c);
char		*init_str(char *s, char c);

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

// ft_strtrim.c
char		*ft_strtrim(char const *s1, char const *set);

// ft_substr.c
char		*ft_substr(char const *s, unsigned int start, t_size len);

// ft_tolower.c
int			ft_tolower(int c);

// ft_toupper.c
int			ft_toupper(int c);

/* ########################################################################## */

#endif
