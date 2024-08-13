/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipv4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 00:48:48 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/12 16:50:48 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_NETWORK_IPV4_H
# define LIBFT_NETWORK_IPV4_H

/* ########################################################################## */
/* REQUIREMENTS */
/* ############ */

# include <arpa/inet.h>
/* sockaddr_in
 */

# include <netdb.h>
/*
 * getaddrinfo()
 * freeaddrinfo()
 */

# include "libft_define.h"
# include "libft_print.h"
# include "libft_integer.h"
# include "libft_check.h"
# include "libft_string.h"
# include "libft_memory.h"
# include "libft_network.h"

/* ########################################################################## */

/* ########################################################################## */
/* CONFIG */
/* ###### */

# ifndef NI_MAXHOST
#  define NI_MAXHOST			0x401
# endif // NI_MAXHOST

# define HTOI4_USE_SOCKET		1
# define I4TOH_USE_SOCKET		1

# define		DNS_TYPE_A		1
// # define		DNS_TYPE_NS		2
# define		DNS_TYPE_CNAME	5
// # define		DNS_TYPE_SOA	6
# define		DNS_TYPE_PTR	12
// # define		DNS_TYPE_MX		15
// # define		DNS_TYPE_TXT	16
// # define		DNS_TYPE_AAAA	28
// # define		DNS_TYPE_SRV	33
// # define		DNS_TYPE_ANY	255

# define		DNS_CLASS_IN	1
// # define		DNS_CLASS_CS	2
// # define		DNS_CLASS_CH	3
// # define		DNS_CLASS_HS	4

# define DNS_DEFAULT_ADDR		0x08080808
# define DNS_DST_PORT			53
# define DNS_SRC_PORT			0x1234
# define DNS_TTL				64
# define DNS_TIMEOUT			500000

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

// network/ipv4/ft_getip_str.c
char				*ft_getip_str(t_int4 n);

// network/ipv4/ft_htoi4.c
t_int4				ft_htoi4_getaddrinfo(char *hostname, char *service);
t_int4				ft_htoi4(char *hostname, char *service);

// network/ipv4/ft_htonl.c
t_uint32			ft_htonl(t_uint32 h);

// network/ipv4/ft_htons.c
t_uint16			ft_htons(t_uint16 h);

// network/ipv4/ft_i4toh.c
char				*ft_i4toh_getnameinfo(t_int4 ip);
char				*ft_i4toh(t_int4 ip);

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

// network/ipv4/get_nameserver.c
t_int4				get_dns_nameserver(void);

// network/ipv4/htoi4_socket/init_packet.c
t_packet			ft_htoi4_init_packet(char *domain);

// network/ipv4/htoi4_socket/init_socket.c
int					ft_htoi4_init_socket(void);

// network/ipv4/htoi4_socket/main.c
t_int4				ft_htoi4_socket(char *domain);

// network/ipv4/htoi4_socket/recv_packet.c
t_int4				ft_htoi4_recv_packet(int sock);

// network/ipv4/htoi4_socket/send_packet.c
int					ft_htoi4_send_packet(int socket, t_packet pkt);

// network/ipv4/i4toh_socket/init_packet.c
t_packet			ft_i4toh_init_packet(t_int4 ip);

// network/ipv4/i4toh_socket/init_socket.c
int					ft_i4toh_init_socket(void);

// network/ipv4/i4toh_socket/main.c
char				*ft_i4toh_socket(t_int4 ip);

// network/ipv4/i4toh_socket/recv_packet.c
char				*ft_i4toh_recv_packet(int sock);

// network/ipv4/i4toh_socket/send_packet.c
int					ft_i4toh_send_packet(int socket, t_packet pkt);

/* ########################################################################## */

#endif /* LIBFT_NETWORK_IPV4_H */
