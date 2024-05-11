/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet_udp.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 06:49:35 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/11 22:45:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FMT_PACKET_UDP_H
# define FMT_PACKET_UDP_H

# define FMT_UDPHDR \
"User Datagram Protocol\n" \
FMT_PKT_LINE \
"|" PKT_16 "|" PKT_16 "|\n" \
FMT_PKT_LINE \
"|" PKT_16 "|" PKT_16 "|\n" \
FMT_PKT_LINE

#endif // FMT_PACKET_UDP_H

