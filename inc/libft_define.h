/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_define.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:13:22 by brda-sil          #+#    #+#             */
/*   Updated: 2022/11/09 03:18:42 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_DEFINE_H
# define LIBFT_DEFINE_H

/* ########################################################################## */
/* CONFIG */
/* ###### */

# define FT_NULL ((void *)0)

/* ########################################################################## */

/* ########################################################################## */
/* TYPEDEF */
/* ####### */

typedef unsigned char		t_uint8;
typedef unsigned int		t_uint32;
typedef long long			t_int64;
typedef unsigned long long	t_uint64;
typedef unsigned long		t_size;

typedef unsigned int		t_int4;
typedef unsigned char		t_int1;

typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

/* ########################################################################## */

#endif
