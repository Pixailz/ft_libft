/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_hashtable.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/21 11:17:03 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_HASHTABLE_H
# define LIBFT_HASHTABLE_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# include "libft_memory.h"

/* ########################################################################## */

/* ########################################################################## */
/* CONFIG */
/* ###### */

#define HT_SIZE		((1UL<<8) - 1)

/* ########################################################################## */

/* ########################################################################## */
/* STRUCT */
/* ###### */

typedef struct s_ht_item
{
	void				*value;
	char				*key;
	t_bool				is_deleted;
	struct s_ht_item	*next;
}	t_ht_item;

typedef struct s_ht
{
	t_ht_item	**item;
}	t_ht;

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// hashtable/ft_ht_free.c

void		ft_ht_free(t_ht *table);

// hashtable/ft_ht_get.c

void		*ft_ht_get(t_ht *table, char *key);

// hashtable/ft_ht_hash_key.c

t_uint32	ft_ht_hash_key(const char *k);

// hashtable/ft_ht_item.c

t_ht_item	*ft_ht_new_item(char *key, void *value);
t_ht_item	*ft_ht_add_item(t_ht_item **item, char *key, void *value);

// hashtable/ft_ht_len.c

t_size		ft_ht_len(t_ht table);

// hashtable/ft_ht_new.c

t_ht		*ft_ht_new();

// hashtable/ft_ht_set.c

t_bool		ft_ht_set(t_ht *table, char *key, void *value);

/* ########################################################################## */

#endif /* LIBFT_HASHTABLE_H */
