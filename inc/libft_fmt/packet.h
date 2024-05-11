/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 06:49:35 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/11 22:44:37 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FMT_PACKET_H
# define FMT_PACKET_H

# define PKT_V_PREFIX "0x"
# define PKT_V_FMT "%0"

# define PKT_V_FMT_1 PKT_V_FMT "1x"
# define PKT_V_FMT_2 PKT_V_FMT "2x"
# define PKT_V_FMT_4 PKT_V_FMT "4x"
# define PKT_V_FMT_6 PKT_V_FMT "6x"
# define PKT_V_FMT_8 PKT_V_FMT "8x"

# define PKT_V_3 PKT_V_PREFIX BLU PKT_V_FMT_1 RST
# define PKT_V_4 PKT_V_PREFIX CYA PKT_V_FMT_1 RST
# define PKT_V_8 PKT_V_PREFIX GRE PKT_V_FMT_2 RST
# define PKT_V_13 PKT_V_PREFIX YEL PKT_V_FMT_4 RST
# define PKT_V_16 PKT_V_PREFIX ORA PKT_V_FMT_4 RST
# define PKT_V_24 PKT_V_PREFIX RED PKT_V_FMT_6 RST
# define PKT_V_32 PKT_V_PREFIX PUR PKT_V_FMT_8 RST

# define PKT_3 " " PKT_V_3 " "
# define PKT_4 "  " PKT_V_4 "  "
# define PKT_8 "     " PKT_V_8 "      "
# define PKT_13 "         " PKT_V_13 "          "
# define PKT_16 "            " PKT_V_16 "             "
# define PKT_24 "                   " PKT_V_24 "                    "
# define PKT_32 "                          " PKT_V_32 \
"                           "

# define FMT_BIN_BAR \
" 0                   1                   2                   3\n" \
" 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1\n"

# define FMT_PKT_LINE \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n"

# include "libft_fmt/packet_ip.h"
# include "libft_fmt/packet_icmp.h"
# include "libft_fmt/packet_udp.h"

#endif // FMT_PACKET_H
