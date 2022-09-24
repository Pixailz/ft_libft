/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/18 19:14:48 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIST_H
# define LIBFT_LIST_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# ifndef LIBFT_DEFINE_H
#  include "libft_define.h"
# endif

# include <stdlib.h>

/* ########################################################################## */

/* ########################################################################## */
/* CONFIG */
/* ###### */

/* ########################################################################## */

/* ########################################################################## */
/* TYPEDEF */
/* ####### */

/* ########################################################################## */

/* ########################################################################## */
/* STRUCT */
/* ###### */

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	t_uint64		*index;
	void			*content;
	t_size			size;
}					t_list;

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// ft_lstadd_back_bonus.c
t_list	*ft_lstadd_back(t_list **lst, t_list *new);

// ft_lstadd_front_bonus.c
void	ft_lstadd_front(t_list **lst, t_list *new);

// ft_lstclear_bonus.c
void	ft_lstclear(t_list **lst, void (*del)(void *));

// ft_lstdelone_bonus.c
void	ft_lstdelone(t_list *lst, void (*del)(void *));

// ft_lstiter_bonus.c
void	ft_lstiter(t_list *lst, void (*f)(void *));

// ft_lstlast_bonus.c
t_list	*ft_lstlast(t_list *lst);

// ft_lstmap_bonus.c
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// ft_lstnew_bonus.c
t_list	*ft_lstnew(void *content);

// ft_lstsize_bonus.c
int		ft_lstsize(t_list *lst);

/* ########################################################################## */

#endif
