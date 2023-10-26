/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_define.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:13:22 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/27 00:56:40 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_DEFINE_H
# define LIBFT_DEFINE_H

/* ########################################################################## */
/* CONFIG */
/* ###### */

# define FT_NULL ((void *)0)

/* ########################################################################## */

/* ########################################################################## */
/* TYPEDEF */
/* ####### */

typedef unsigned char		t_uint8;
typedef unsigned int		t_uint32;
typedef long long			t_int64;
typedef unsigned long long	t_uint64;
typedef unsigned long		t_size;

typedef t_uint8				t_int4;
typedef t_uint32			t_int1;

typedef t_uint64			t_bin;

typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

typedef enum e_bit
{
	BIT_00 = 0ULL,
	BIT_01 = 1ULL << 0,
	BIT_02 = 1ULL << 1,
	BIT_03 = 1ULL << 2,
	BIT_04 = 1ULL << 3,
	BIT_05 = 1ULL << 4,
	BIT_06 = 1ULL << 5,
	BIT_07 = 1ULL << 6,
	BIT_08 = 1ULL << 7,
	BIT_09 = 1ULL << 8,
	BIT_0A = 1ULL << 9,
	BIT_0B = 1ULL << 10,
	BIT_0C = 1ULL << 11,
	BIT_0D = 1ULL << 12,
	BIT_0E = 1ULL << 13,
	BIT_0F = 1ULL << 14,
	BIT_10 = 1ULL << 15,
	BIT_11 = 1ULL << 16,
	BIT_12 = 1ULL << 17,
	BIT_13 = 1ULL << 18,
	BIT_14 = 1ULL << 19,
	BIT_15 = 1ULL << 20,
	BIT_16 = 1ULL << 21,
	BIT_17 = 1ULL << 22,
	BIT_18 = 1ULL << 23,
	BIT_19 = 1ULL << 24,
	BIT_1A = 1ULL << 25,
	BIT_1B = 1ULL << 26,
	BIT_1C = 1ULL << 27,
	BIT_1D = 1ULL << 28,
	BIT_1E = 1ULL << 29,
	BIT_1F = 1ULL << 30,
	BIT_20 = 1ULL << 31,
	BIT_21 = 1ULL << 32,
	BIT_22 = 1ULL << 33,
	BIT_23 = 1ULL << 34,
	BIT_24 = 1ULL << 35,
	BIT_25 = 1ULL << 36,
	BIT_26 = 1ULL << 37,
	BIT_27 = 1ULL << 38,
	BIT_28 = 1ULL << 39,
	BIT_29 = 1ULL << 40,
	BIT_2A = 1ULL << 41,
	BIT_2B = 1ULL << 42,
	BIT_2C = 1ULL << 43,
	BIT_2D = 1ULL << 44,
	BIT_2E = 1ULL << 45,
	BIT_2F = 1ULL << 46,
	BIT_30 = 1ULL << 47,
	BIT_31 = 1ULL << 48,
	BIT_32 = 1ULL << 49,
	BIT_33 = 1ULL << 50,
	BIT_34 = 1ULL << 51,
	BIT_35 = 1ULL << 52,
	BIT_36 = 1ULL << 53,
	BIT_37 = 1ULL << 54,
	BIT_38 = 1ULL << 55,
	BIT_39 = 1ULL << 56,
	BIT_3A = 1ULL << 57,
	BIT_3B = 1ULL << 58,
	BIT_3C = 1ULL << 59,
	BIT_3D = 1ULL << 60,
	BIT_3E = 1ULL << 61,
	BIT_3F = 1ULL << 62,
	BIT_40 = 1ULL << 63,
}	t_bit;

/* ########################################################################## */

#endif // LIBFT_DEFINE_H
