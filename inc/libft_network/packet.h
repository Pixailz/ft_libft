/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 00:48:48 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/06 23:54:56 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PACKET_H
# define PACKET_H

/* ########################################################################## */
/* REQUIREMENTS */
/* ############ */

# include "libft_define.h"
# include "libft_memory.h"
# include "libft_network/ipv4.h"
# include "libft_fmt/packet.h"

/* ########################################################################## */

/* ########################################################################## */
/* CONFIG */
/* ###### */

# define	PACK_MAX_IP_LEN				0xffff
# if PACK_USE_IP_OPTS == 1
#  define PACK_LEN_IP					24
# else
#  define PACK_LEN_IP					20
# endif // PACK_USE_IP_OPTS == 1

# define PACK_LEN_ICMP_ECHO				8

# ifndef IPPROTO_ICMP
#  define IPPROTO_ICMP					1
# endif // IPPROTO_ICMP

// MASK
# define IPHDR_M_IHL					0x0F
# define IPHDR_M_VERSION				0xF0
# define IPHDR_M_FRAG_OFF				0x1FFF
# define IPHDR_M_FLAGS					0xE000
# define IPHDR_M_OPTIONS				0xF000
# define IPHDR_M_PADDING				0x000F

// IPHDR OPTIONS
# define IPHDR_F_DONT_FRAG				0x2
# define IPHDR_F_MORE_FRAG				0x1

/* ########################################################################## */

/* ########################################################################## */
/* STRUCT */
/* ###### */

// A PACKET
typedef struct __attribute__((__packed__)) s_packet
{
	unsigned char	data[PACK_MAX_IP_LEN];
}	t_packet;

// IP
typedef struct __attribute__((__packed__)) s_iphdr
{
# if __BYTE_ORDER == __LITTLE_ENDIAN
	t_uint8		ihl:4;
	t_uint8		version:4;
# elif __BYTE_ORDER == __BIG_ENDIAN

	t_uint8		version:4;
	t_uint8		ihl:4;
# endif // __BYTE_ORDER == __LITTLE_ENDIAN
	t_uint8		tos;
	t_uint16	total_len;

	t_uint16	identification;
	t_uint16	fragment_off;

	t_uint8		ttl;
	t_uint8		protocol;
	t_uint16	checksum;

	t_uint32	src_addr;
	t_uint32	dst_addr;

# if FT_PING_USE_IP_OPTS == 1
#  if __BYTE_ORDER == __LITTLE_ENDIAN

	t_uint32	options:24;
	t_uint32	padding:8;
#  elif __BYTE_ORDER == __BIG_ENDIAN
	t_uint32	padding:8;
	t_uint32	options:24;

#  endif // __BYTE_ORDER == __LITTLE_ENDIAN
# endif // FT_PING_USE_IP_OPTS == 1

}	t_iphdr;

// ICMP
	// ICMP ECHO
typedef struct __attribute__((__packed__)) s_icmphdr_echo
{
	t_uint8		type;
	t_uint8		code;
	t_uint16	checksum;

	t_uint16	identifier;
	t_uint16	sequence;

}	t_icmphdr_echo;

/* ########################################################################## */


/* ########################################################################## */
/* FILES */
/* ##### */

// network/packet/checksum.c
t_uint16			ft_pkt_checksum(char *data, t_size size);

// network/packet/ft_packet_get.c
t_packet			ft_pkt_get(void);
t_iphdr				*ft_pkt_get_ip(t_packet *packet);
t_icmphdr_echo		*ft_pkt_get_icmp_echo(t_packet *packet);

// network/packet/icmp/checksum.c
void				ft_pkt_icmp_checksum(t_icmphdr_echo *packet, t_size size);

// network/packet/icmp/print.c
void				ft_pkt_print_icmp(int fd, t_icmphdr_echo *pkt);

// network/packet/icmp/set_seq.c
void				ft_pkt_icmp_set_seq(t_icmphdr_echo *packet, t_int32 seq);

// network/packet/ip/default.c
void				ft_pkt_fill_ip_default(t_iphdr *packet);

// network/packet/ip/fragment_offset.c
t_uint16			ft_pkt_fragment_offset(t_uint8 flags,
	t_uint16 get_fragment_off);

// network/packet/ip/print.c
void				ft_pkt_print_ip(int fd, t_iphdr *pkt);
void				ft_pkt_print_ip(int fd, t_iphdr *pkt);

// network/packet/print_raw.c
void				ft_pkt_print_raw(int fd, char *pkt, t_size size);

/* ########################################################################## */

#endif /* PACKET_H */
