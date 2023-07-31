/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_string.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2023/07/31 19:09:35 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRING_H
# define LIBFT_STRING_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# include <stdlib.h>

# include "libft_define.h"
# include "libft_integer.h"
# include "libft_check.h"
# include "libft_memory.h"

/* ########################################################################## */

/* ########################################################################## */
/* DEFINE */
/* ####### */

// BASE
# define BUHEX		"0123456789ABCDEF"
# define BLHEX		"0123456789abcdef"
# define BDEC		"0123456789"
# define BBIN		"01"

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// string/ft_atoi.c
int			ft_atoi(const char *nstr);

// string/ft_atoi_base.c
int			ft_atoi_base(const char *nstr, const char *base);

// string/ft_atoll.c
t_int64		ft_atoll(const char *nstr);

// string/ft_atoll_base.c
t_int64		ft_atoll_base(char *nstr, const char *base);

// string/ft_atou.c
t_uint64	ft_atou(const char *nstr);

// string/ft_atou_base.c
t_uint64	ft_atou_base(const char *nstr, const char *base);

// string/ft_get_words.c
int			ft_get_words(char *str, char c);

// string/ft_patoi.c
int			ft_patoi(const char *nstr, int *has_flow);

// string/ft_patoi_base.c
int			ft_patoi_base(const char *nstr, const char *base, int *has_flow);

// string/ft_patoll.c
t_int64		ft_patoll(const char *nstr, int *has_flow);

// string/ft_patoll_base.c
t_int64		ft_patoll_base(const char *nstr, const char *base, int *has_flow);

// string/ft_patou.c
t_uint32	ft_patou(const char *nstr, int *has_overflow);

// string/ft_patou_base.c
t_uint32	ft_patou_base(const char *nstr, const char *base, int *has_overflow);

// string/ft_split.c
char		**ft_split(char *s, char c);

// string/ft_splitb.c
int			ft_splitb_get_word(char **str, char delim, char *encl);
int			ft_splitb_get_size(char *str, char delim, char *encl);
char		**ft_splitb_get_words(char *s, char delim, char *encl, int tab_size);
char		**ft_splitb(char *s, char delim, char *encl);

// string/ft_strcat.c
char		*ft_strcat(char *dest, char *src);

// string/ft_strcchr.c
int			ft_strcchr(char *str, char c);

// string/ft_strchr.c
char		*ft_strchr(const char *s, int c);

// string/ft_strclr.c
void		ft_strclr(char *s);

// string/ft_strcmp.c
int			ft_strcmp(char *s1, char *s2);

// string/ft_strcpy.c
char		*ft_strcpy(char *dest, char *src);

// string/ft_strcspn.c
t_size		ft_strcspn(char *s, const char *rejects);

// string/ft_strdel.c
void		ft_strdel(char **as);

// string/ft_strdup.c
char		*ft_strdup(char *src);

// string/ft_striteri.c
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

// string/ft_strjoin.c
char		*ft_strjoin(char const *s1, char const *s2);

// string/ft_strlcat.c
t_uint32	ft_strlcat(char *dest, char *src, t_size size);

// string/ft_strlcpy.c
t_uint32	ft_strlcpy(char *dest, char *src, t_size size);

// string/ft_strlen.c
int			ft_strlen(const char *str);

// string/ft_strmapi.c
char		*ft_strmapi(char const *s1, char (*f)(unsigned int, char));

// string/ft_strncat.c
char		*ft_strncat(char *dest, char *src, t_size n);

// string/ft_strncmp.c
int			ft_strncmp(char *s1, char *s2, t_size n);

// string/ft_strncpy.c
char		*ft_strncpy(char *dest, char *src, t_size n);

// string/ft_strnstr.c
char		*ft_strnstr(char *str, char *to_find, int n);

// string/ft_strrchr.c
char		*ft_strrchr(const char *s, int c);

// string/ft_strspn.c
size_t		ft_strspn(char *s, const char *accepts);

// string/ft_strtok.c
char		*ft_strtok(char *str, char *token);

// string/ft_strtrim.c
char		*ft_strtrim(char const *s1, char const *set);

// string/ft_substr.c
char		*ft_substr(char const *s, unsigned int start, t_size len);

// string/ft_tolower.c
int			ft_tolower(int c);

// string/ft_toupper.c
int			ft_toupper(int c);

/* ########################################################################## */

#endif
