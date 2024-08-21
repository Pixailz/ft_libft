/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 00:48:48 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/13 21:27:15 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_NETWORK_SOCKET_H
# define LIBFT_NETWORK_SOCKET_H

/* ########################################################################## */
/* REQUIREMENTS */
/* ############ */

# include "libft_define.h"

/* ########################################################################## */

/* ########################################################################## */
/* CONFIG */
/* ###### */

# define FT_SOCKET_MAX 0x80

/* ########################################################################## */

/* ########################################################################## */
/* STRUCT */
/* ###### */
typedef t_int32 t_socket_id;

/* ########################################################################## */


/* ########################################################################## */
/* FILES */
/* ##### */

// network/socket/ft_socket.c

int			ft_socket(int domain, int type, int protocol);

// network/socket/ft_socket_get.c

int			ft_socket_get(t_socket_id index);
int			*ft_socket_get_new();
t_socket_id	ft_socket_get_index(int sock);

// network/socket/ft_socket_singletone.c

int			*ft_socket_sing_get();
void		ft_socket_sing_free();

// network/socket/setsockopt/bind_interface.c

t_bool		ft_setsockopt_bind_interface(int sock, char *interface);

// network/socket/setsockopt/ipheader.c

t_bool		ft_setsockopt_ipheader(int sock);

// network/socket/setsockopt/timeout.c

t_bool		ft_setsockopt_timeout(int sock, int timeout);

/* ########################################################################## */

#endif /* LIBFT_NETWORK_SOCKET_H */
