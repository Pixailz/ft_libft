/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipv4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 00:48:48 by brda-sil          #+#    #+#             */
/*   Updated: 2024/02/24 00:50:19 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IPV4_H
# define IPV4_H

/* ########################################################################## */
/* REQUIREMENTS */
/* ############ */

# include <netdb.h>
/*
 getaddrinfo()
 freeaddrinfo()
 */

# include "libft_define.h"
# include "libft_print.h"
# include "libft_integer.h"
# include "libft_check.h"
# include "libft_string.h"
# include "libft_memory.h"

/* ########################################################################## */

/* ########################################################################## */
/* CONFIG */
/* ###### */

# define CLASS_A_MIN			0b00000000
# define CLASS_A_MAX			0b01111110
# define CLASS_B_MIN			0b10000000
# define CLASS_B_MAX			0b10111111
# define CLASS_C_MIN			0b11000000
# define CLASS_C_MAX			0b11011111
# define CLASS_D_MIN			0b11100000
# define CLASS_D_MAX			0b11101111
# define CLASS_E_MIN			0b11110000
# define CLASS_E_MAX			0b11111111

/* ########################################################################## */

/* ########################################################################## */
/* TYPEDEF */
/* ####### */

typedef struct s_ip
{
	char		ip_class;
	t_int4		ip_int;
	t_int4		netmask_int;
	t_int4		wildcard_int;
	t_int4		network_int;
	t_int4		network_int_min;
	t_int4		network_int_max;
	t_int4		broadcast_int;
	int			netmask_n;
}				t_ip;

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// network/ipv4/ft_htoi4.c
t_int4				ft_htoi4(char *hostname, char *service);

// network/ipv4/ft_htonl.c
t_uint32			ft_htonl(t_uint32 h);

// network/ipv4/ft_htons.c
t_uint16			ft_htons(t_uint16 h);

// network/ipv4/ft_ipstr.c
int					ft_ip_check_part(char *splitted);
char				**ft_ip_check(char *str);
t_int4				ft_ipstr(char *str);

// network/ipv4/ft_is_goodhost.c
t_bool				ft_is_goodchar_host(char c);
t_bool				ft_host_check(char *fqnd);
t_bool				ft_is_goodhost(char *fqnd);

// network/ipv4/ft_ltoaddr.c
struct sockaddr		ft_ltoaddr(t_int4 ip);

// network/ipv4/ft_ntohl.c
t_uint32			ft_ntohl(t_uint32 h);

// network/ipv4/ft_ntohs.c
t_uint16			ft_ntohs(t_uint16 n);

// network/ipv4/ft_ntop.c
void				ft_ntop(t_bin pf, t_int4 ip, char *ip_str);

// network/ipv4/ft_putip_fd.c
t_size				ft_putip_fd(t_int4 n, int fd);

/* ########################################################################## */

#endif /* IPV4_H */
