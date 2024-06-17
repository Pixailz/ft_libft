
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
# define __ANSI_C_E(C)		CSI C "m"
# define __ANSI_C_D(C)		""

# ifdef ANSI_NO_COLOR
#  define	_ANSI_C(C)				__ANSI_C_D(C)
#  define	_ANSI_M(C)				__ANSI_C_D(C)
# else
#  define	_ANSI_C(C)				__ANSI_C_E(C)
#  ifdef ANSI_NO_MODIFIER
#   define	_ANSI_M(C)				__ANSI_C_D(C)
#  else
#   define	_ANSI_M(C)				__ANSI_C_E(C)
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
# define DIM			_ANSI_M("2")			// DIMMED
# define ITA			_ANSI_M("3")			// ITALIC
# define UND			_ANSI_M("4")			// UNDERLINE
# define BLI			_ANSI_M("5")			// BLINKING

/* MODIFIER RESET */
# define RBOL			_ANSI_M("22")			// RESET BOLD
# define RDIM			_ANSI_M("22")			// RESET DIMMED
# define RITA			_ANSI_M("23")			// RESET ITALIC
# define RUND			_ANSI_M("24")			// RESET UNDERLINE
# define RBLI			_ANSI_M("25")			// RESET BLINKING

/* RESET AND MODIFIER RESET */
# define RSTBOL			_ANSI_M("0;21")			// RESET AND RESET BOLD
# define RSTDIM			_ANSI_M("0;22")			// RESET AND RESET DIMMED
# define RSTITA			_ANSI_M("0;23")			// RESET AND RESET ITALIC
# define RSTUND			_ANSI_M("0;24")			// RESET AND RESET UNDERLINE
# define RSTBLI			_ANSI_M("0;25")			// RESET AND RESET BLINKING

/* CURSOR */
# define CUR_COL(C)		CSI C "G"

/* COMPOSITE */
# define SEP			" → "					// UNICODE ARROW

# define P_ERRO			"[" RED "ERRO" RST "]" SEP
# define P_FAIL			"[" RED "FAIL" RST "]" SEP
# define P_PASS			"[" GRE "PASS" RST "]" SEP
# define P_DEBG			"[" BLU "DEBG" RST "]" SEP
# define P_INFO			"[" CYA "INFO " RST "]" SEP

/* ########################################################################## */

#endif /* LIBFT_ANSI_H */
