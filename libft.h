/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by stales            #+#    #+#             */
/*   Updated: 2022/04/04 17:51:15 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define LIBFT_NULL (void *)0

typedef unsigned char		t_uint8;
typedef unsigned int		t_uint32;
typedef unsigned long		t_size;
typedef long long			t_int64;

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	void			*content;
	t_size			size;
}	t_list;

/////////////////////////////////////
//
//	FUNCTION BONUS
//
/////////////////////////////////////

t_list			*ft_lstnew(void *content);
t_list			*ft_lstadd_back(t_list **lst, t_list *new);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
int				ft_lstsize(t_list *lst);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));

t_list			*ft_list_create_void(void);
t_list			*ft_list_create(void *content, t_size size);
t_list			*ft_list_insert(t_list **list, t_list *new, t_uint32 index);
t_list			*ft_list_get(t_list *list, t_uint32 index);
unsigned char	*ft_hex_encode(unsigned char *dst, char *src, t_size size);
unsigned char	*ft_hex_decode(unsigned char *dst, char *src, t_size size);
char			**ft_split(char *s, char c);
void			*ft_calloc(t_size nmemb, t_size size);
void			*ft_memccpy(void *dest, const void *src, int c, t_size n);
void			*ft_memchr(const void *s, int c, t_size n);
void			*ft_memcpy(void *dest, const void *src, t_size n);
void			*ft_memmove(void *dest, const void *src, t_size n);
void			*ft_memset(void *s, int c, t_size n);
void			*ft_memalloc(t_size size);
char			*ft_strcat(char *dest, char *src);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strdup(char *src);
char			*ft_strlowcase(char *str);
char			*ft_strncat(char *dest, char *src, t_size n);
char			*ft_strncpy(char *dest, char *src, t_size n);
char			*ft_strndup(char *src, int n);
char			*ft_strnstr(char *str, char *to_find, int n);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(char *str, char *to_find);
char			*ft_strupcase(char *str);
char			*ft_strrev(char *str);
char			*ft_itoa(int nb);
char			*ft_strnew(t_size size);
char			*ft_strtok(char *str, char *token);
char			*ft_substr(char const *s, unsigned int start, t_size len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmapi(char const *s1, char (*f)(unsigned int, char));
char			*ft_strrem(char *ptr, char const *s1, char const *set);
char			*ft_strtrim(char const *s1, char const *set);
t_size			ft_strcspn(char *s, const char *reject);
t_uint32		ft_strlcat(char *dest, char *src, t_size size);
t_uint32		ft_strlcpy(char *dest, char *src, t_size size);
t_uint32		ft_list_len(t_list *list);
int				ft_atoi(char *str);
int				ft_get_words(char *str, char c);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isblank(int c);
int				ft_iscntrl(int c);
int				ft_isdigit(int c);
int				ft_isgraph(int c);
int				ft_islower(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_isupper(int c);
int				ft_isxdigit(int c);
int				ft_memcmp(const void *s1, const void *s2, t_size n);
int				ft_nbrlen(long int nb);
int				ft_str_is_alpha(char *s);
int				ft_str_is_lowercase(char *s);
int				ft_str_is_numeric(char *s);
int				ft_str_is_printable(char *s);
int				ft_str_is_uppercase(char *s);
int				ft_strcmp(char *s1, char *s2);
int				ft_strlen(char *str);
int				ft_strncmp(char *s1, char *s2, t_size n);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_rev_int(int nb);
int				ft_strcchr(char *str, char c);
int				ft_strspn(char *s, const char *accept);
unsigned char	ft_hex_nibble(char c);
void			ft_bzero(void *s, t_size n);
void			ft_putchar(char c);
void			ft_putnbr(int nb);
void			ft_putstr(char const *s);
void			ft_strclr(char *s);
void			ft_putchar_fd(char c, int fd);
void			ft_swap(int *a, int *b);
void			ft_memdel(void **ap);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putendl(char const *s);
void			ft_putnbr_fd(int n, int fd);
void			ft_strdel(char **as);
void			ft_list_free(t_list **list);
void			ft_list_push(t_list **list, t_list *new);
void			ft_list_pop(t_list **list);
void			ft_list_push_back(t_list **list, t_list *new);
void			ft_list_pop_back(t_list **list);
void			ft_list_remove(t_list **list, int index);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));

#endif
