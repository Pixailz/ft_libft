/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 00:48:48 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/12 17:57:11 by brda-sil         ###   ########.fr       */
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

# define PACK_LEN_UDP					8

// PROTO
# ifndef IPPROTO_ICMP
#  define IPPROTO_ICMP					1
# endif // IPPROTO_ICMP
# ifndef IPPROTO_UDP
#  define IPPROTO_UDP					17
# endif // IPPROTO_UDP
// TYPE
# ifndef ICMP_ECHOREPLY
#  define ICMP_ECHOREPLY				0	/* Echo Reply				*/
# endif // ICMP_ECHOREPLY
# ifndef ICMP_DEST_UNREACH
#  define ICMP_DEST_UNREACH				3	/* Destination Unreachable	*/
# endif // ICMP_DEST_UNREACH
# ifndef ICMP_ECHO
#  define ICMP_ECHO						8	/* Echo Request				*/
# endif // ICMP_ECHO
# ifndef ICMP_TIME_EXCEEDED
#  define ICMP_TIME_EXCEEDED			11	/* Time Exceeded			*/
# endif // ICMP_TIME_EXCEEDED
// CODE
	/* Codes for UNREACH. */
# ifndef ICMP_NET_UNREACH
#  define ICMP_NET_UNREACH				0	/* Network Unreachable		*/
# endif // ICMP_NET_UNREACH
# ifndef ICMP_HOST_UNREACH
#  define ICMP_HOST_UNREACH				1	/* Host Unreachable			*/
# endif // ICMP_HOST_UNREACH
# ifndef ICMP_PROT_UNREACH
#  define ICMP_PROT_UNREACH				2	/* Protocol Unreachable		*/
# endif // ICMP_PROT_UNREACH
# ifndef ICMP_PORT_UNREACH
#  define ICMP_PORT_UNREACH				3	/* Port Unreachable			*/
# endif // ICMP_PORT_UNREACH

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

# define ICMP_HDR_PADDING				8

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

// UDP
typedef struct __attribute__((__packed__)) s_udphdr
{
	t_uint16	src_port;
	t_uint16	dst_port;

	t_uint16	length;
	t_uint16	checksum;
}	t_udphdr;

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

	// ICMP TIME EXCEED
typedef struct __attribute__((__packed__)) s_icmphdr_time_exceed
{
	t_uint8		type;
	t_uint8		code;
	t_uint16	checksum;

	t_uint32	unused;

	t_iphdr		ori_iphdr;
}	t_icmphdr_time_exceed;

/* ########################################################################## */


/* ########################################################################## */
/* FILES */
/* ##### */

// network/packet/checksum.c
t_uint16					ft_pkt_checksum(char *data, t_size size);

// network/packet/ft_packet_get.c
t_packet					ft_pkt_get(void);

// network/packet/icmp/checksum.c
void						ft_pkt_icmp_checksum(t_icmphdr_echo *packet, t_size size);

// network/packet/icmp/get.c
t_icmphdr_echo				*ft_pkt_get_icmp_echo(t_packet *packet);
t_icmphdr_time_exceed		*ft_pkt_get_icmp_time_exceed(t_packet *packet);

// network/packet/icmp/print.c
void						ft_pkt_print_icmp(int fd, t_icmphdr_echo *pkt);

// network/packet/icmp/set_seq.c
void						ft_pkt_icmp_set_seq(t_icmphdr_echo *packet, t_int32 seq);

// network/packet/ip/default.c
void						ft_pkt_fill_ip_default(t_iphdr *packet);

// network/packet/ip/fragment_offset.c
t_uint16					ft_pkt_fragment_offset(t_uint8 flags,
	t_uint16 get_fragment_off);

// network/packet/ip/get.c
t_iphdr						*ft_pkt_get_ip(t_packet *packet);

// network/packet/ip/print.c
void						ft_pkt_print_ip(int fd, t_iphdr *pkt);
void						ft_pkt_print_ip(int fd, t_iphdr *pkt);

// network/packet/print_raw.c
void						ft_pkt_print_raw(int fd, char *pkt, t_size size);

// network/packet/udp/get.c
t_udphdr					*ft_pkt_get_udp(t_packet *packet);

// network/packet/udp/print.c
void						ft_pkt_print_udp(int fd, t_udphdr *pkt);

/* ########################################################################## */

#endif /* PACKET_H */
