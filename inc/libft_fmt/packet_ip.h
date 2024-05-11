/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet_ip.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 06:49:35 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/11 22:43:30 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FMT_PACKET_IP_H
# define FMT_PACKET_IP_H

# if FT_PING_USE_IP_OPTS == 1
#  define FMT_IPHDR \
"Internet Protocol Header Format\n" \
FMT_PKT_LINE \
"|" PKT_4 "|" PKT_4 "|" PKT_8 "|" PKT_16 "|\n" \
FMT_PKT_LINE \
"|" PKT_16 "|" PKT_3 "|" PKT_13 "|\n" \
FMT_PKT_LINE \
"|" PKT_8 "|" PKT_8 "|" PKT_16 "|\n" \
FMT_PKT_LINE \
"|" PKT_32 "|\n" \
FMT_PKT_LINE \
"|" PKT_32 "|\n" \
FMT_PKT_LINE \
"|" PKT_24 "|" PKT_8 "|\n" \
FMT_PKT_LINE
# else
#  define FMT_IPHDR \
"Internet Header Format\n" \
FMT_PKT_LINE \
"|" PKT_4 "|" PKT_4 "|" PKT_8 "|" PKT_16 "|\n" \
FMT_PKT_LINE \
"|" PKT_16 "|" PKT_3 "|" PKT_13 "|\n" \
FMT_PKT_LINE \
"|" PKT_8 "|" PKT_8 "|" PKT_16 "|\n" \
FMT_PKT_LINE \
"|" PKT_32 "|\n" \
FMT_PKT_LINE \
"|" PKT_32 "|\n" \
FMT_PKT_LINE
# endif // FT_PING_USE_IP_OPTS == 1

#endif // FMT_PACKET_IP_H

