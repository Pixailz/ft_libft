/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/24 15:13:44 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIST_H
# define LIBFT_LIST_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# include <stdlib.h>

# include "libft_define.h"

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

// list/ft_lstadd_back.c
t_list		*ft_lstadd_back(t_list **lst, t_list *new);

// list/ft_lstadd_front.c
void		ft_lstadd_front(t_list **lst, t_list *new);

// list/ft_lstclear.c
void		ft_lstclear(t_list **lst, void (*del)(void *));

// list/ft_lstdelone.c
void		ft_lstdelone(t_list *lst, void (*del)(void *));

// list/ft_lstiter.c
void		ft_lstiter(t_list *lst, void (*f)(void *));

// list/ft_lstlast.c
t_list		*ft_lstlast(t_list *lst);

// list/ft_lstmap.c
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// list/ft_lstnew.c
t_list		*ft_lstnew(void *content);

// list/ft_lstsize.c
int			ft_lstsize(t_list *lst);

/* ########################################################################## */

#endif // LIBFT_LIST_H
