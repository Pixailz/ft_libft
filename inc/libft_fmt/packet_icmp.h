/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet_icmp.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 06:49:35 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/06 23:39:34 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FMT_PACKET_ICMP_H
# define FMT_PACKET_ICMP_H

# define FMT_ICMPHDR_ECHO \
"ICMP: Echo or Echo Reply Message\n" \
FMT_PKT_LINE \
"|" PKT_8 "|" PKT_8 "|" PKT_16 "|\n" \
FMT_PKT_LINE \
"|" PKT_16 "|" PKT_16 "|\n" \
FMT_PKT_LINE

#endif // FMT_PACKET_ICMP_H

