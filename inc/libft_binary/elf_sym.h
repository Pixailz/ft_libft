/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf_sym.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 13:55:11 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ELF_SYM_H
# define FT_ELF_SYM_H

# include "libft_define.h"
# include <elf.h>

typedef union	u_elf_sym
{
	Elf32_Sym			*_32;
	Elf64_Sym			*_64;
}	t_elf_sym;

typedef t_uint32		t_sym_name;
typedef t_uint64		t_sym_value;
typedef t_uint64		t_sym_size;
typedef t_uint8			t_sym_info;
typedef t_uint8			t_sym_other;
typedef t_uint16		t_sym_shndx;

# define ELF_ST_BIND(i)		(i >> 4)
# define ELF_ST_TYPE(i)		(i & 0xf)
# define ELF_ST_INFO(b, t)	((b << 4) + (t & 0xf))

#endif // FT_ELF_SYM_H
