/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 00:48:48 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/26 02:08:11 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_NETWORK_PACKET_H
# define LIBFT_NETWORK_PACKET_H

/* ########################################################################## */
/* REQUIREMENTS */
/* ############ */

# include "libft_define.h"
# include "libft_memory.h"
# include "libft_fmt/packet.h"

/* ########################################################################## */

/* ########################################################################## */
/* CONFIG */
/* ###### */

# define	PACK_MAX_LEN				0xffff
# if PACK_USE_IP_OPTS == 1
#  define PACK_LEN_IP					24
# else
#  define PACK_LEN_IP					20
# endif // PACK_USE_IP_OPTS == 1

# define PACK_LEN_ICMP_ECHO				8
# define PACK_LEN_UDP					8
# define PACK_LEN_DNS					12

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

// IP
	//HEADER
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
	//HEADER
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
	t_uint8		ori_data[8];

}	t_icmphdr_time_exceed;

// DNS
	//HEADER
typedef struct __attribute__((__packed__)) s_dnshdr
{
	t_uint16	identification;

# if __BYTE_ORDER == __LITTLE_ENDIAN
	t_uint8		recursion_desired:1;
	t_uint8		truncation:1;
	t_uint8		authoritative_answer:1;
	t_uint8		opcode:4;
	t_uint8		is_response:1;

	t_uint8		response_code:4;
	t_uint8		reserved:3;
	t_uint8		recursion_available:1;

# elif __BYTE_ORDER == __BIG_ENDIAN
	t_uint8		is_response:1;
	t_uint8		opcode:4;
	t_uint8		authoritative_answer:1;
	t_uint8		truncation:1;
	t_uint8		recursion_desired:1;

	t_uint8		recursion_available:1;
	t_uint8		reserved:3;
	t_uint8		response_code:4;

# endif // __BYTE_ORDER == __LITTLE_ENDIAN

	t_uint16	question_count;
	t_uint16	response_count;
	t_uint16	authority_count;
	t_uint16	additional_count;

}	t_dnshdr;

	// DNS QUESTION
typedef struct s_dnsq
{
	char		*name;
	t_uint16	type;
	t_uint16	class;
}	t_dnsq;

typedef struct s_dnsr
{
	t_uint16	type;
	t_uint16	class;
	t_uint32	ttl;
	t_uint16	rdlength;
	void		*value;
}	t_dnsr;

/* ########################################################################## */


/* ########################################################################## */
/* FILES */
/* ##### */

// network/packet/checksum.c
t_uint16					ft_pkt_checksum(char *data, t_size size);

// network/packet/dns/dnsq_fill.c
void						ft_pkt_dnsq_fill(
		t_packet *pack,
		char *domain,
		t_uint16 type,
		t_uint16 class
	);

// network/packet/dns/dnsq_get.c
int							ft_pkt_dnsq_get(unsigned char *data, t_dnsq *dnsq);

// network/packet/dns/dnsq_len.c
t_size						ft_pkt_dnsq_len(t_packet pack);

// network/packet/dns/dnsr_get.c
int							ft_pkt_dnsr_get(
		unsigned char *data,
		t_uint16 rc,
		t_dnsr *dnsr
	);

// network/packet/dns/get.c
t_dnshdr					*ft_pkt_get_dns(t_packet *packet);
unsigned char				*ft_pkt_get_dns_data(t_packet *pack);

// network/packet/dns/get_domain_fmt.c
void						ft_dns_get_domain_fmt_loop(
		char *ret,
		t_size len_splitted_dom,
		char **splitted_dom
	);
char						*ft_dns_get_domain_fmt(char *domain);

// network/packet/dns/name_get.c
int							ft_pkt_get_dnsr_name(
		unsigned char *data,
		char **name
	);

// network/packet/dns/print.c

// network/packet/ft_packet_get.c
t_packet					ft_pkt_get(void);

// network/packet/icmp/checksum.c
void						ft_pkt_icmp_checksum(
		t_icmphdr_echo *packet,
		t_size size
	);

// network/packet/icmp/get.c
t_icmphdr_echo				*ft_pkt_get_icmp_echo(t_packet *packet);
t_icmphdr_time_exceed		*ft_pkt_get_icmp_time_exceed(t_packet *packet);

// network/packet/icmp/print.c
void						ft_pkt_print_icmp(int fd, t_icmphdr_echo *pkt);

// network/packet/icmp/set_seq.c
void						ft_pkt_icmp_set_seq(
		t_icmphdr_echo *packet,
		t_int32 seq
	);

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

#endif /* LIBFT_NETWORK_PACKET_H */
