
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_ANSI.h                                      :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/24 14:41:50 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_ANSI_H
# define LIBFT_ANSI_H

/* ########################################################################## */
/* ANSI CODE */
/* ###### */

# define	ESC			"\x1b"
# define	CSI			ESC "["

// Needed when wanting len of string without ansi escaped code
# define	ANSI_BEG	"\001"
# define	ANSI_END	"\002"

/* DEFINE */
# ifdef ANSI_NO_COLOR
#  define	_ANSI_C(C)				""
# else
#  define	_ANSI_C(C)				CSI C "m"
#  ifdef ANSI_NO_MODIFIER
#   define	_ANSI_M(C)				""
#  else
#   define	_ANSI_M(C)				CSI C "m"
#  endif /* NO_MODIFIER */
# endif /* NO_COLOR */

/* COLOR / MODIFIER */

# define	BLA			_ANSI_C("30")			// BLACK
# define	RED			_ANSI_C("31")			// RED
# define	GRE			_ANSI_C("32")			// GREEN
# define	YEL			_ANSI_C("33")			// YELLOW
# define	BLU			_ANSI_C("34")			// BLUE
# define	PUR			_ANSI_C("35")			// PURPLE
# define	CYA			_ANSI_C("36")			// CYAN
# define	WHI			_ANSI_C("37")			// WHITE
# define	ORA			_ANSI_C("38;5;208")		// ORANGE
# define	PIN			_ANSI_C("38;5;218")		// PINK

/* MODIFIER */
# define RST			_ANSI_M("0")			// RESET
# define BOL			_ANSI_M("1")			// BOLD
# define ITA			_ANSI_M("3")			// ITALIC
# define UND			_ANSI_M("4")			// UNDERLINE
# define BLI			_ANSI_M("5")			// BLINKING

/* COMPOSITE */
# define SEP			" → "					// UNICODE ARROW

# define P_ERRO			"[" RED "ERRO" RST "]" SEP
# define P_FAIL			"[" RED "FAIL" RST "]" SEP
# define P_PASS			"[" GRE "PASS" RST "]" SEP
# define P_DEBG			"[" BLU "DEBG" RST "]" SEP
# define P_INFO			"[" CYA "INFO " RST "]" SEP

/* ########################################################################## */

#endif /* LIBFT_ANSI_H */
