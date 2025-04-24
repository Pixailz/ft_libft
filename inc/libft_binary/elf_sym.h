/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf_sym.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:18:37 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ELF_SYM_H
# define FT_ELF_SYM_H

# include "libft_define.h"
# include <elf.h>

# define ELF_ST_BIND(i)		(i >> 4)
# define ELF_ST_TYPE(i)		(i & 0xf)
# define ELF_ST_INFO(b, t)	((b << 4) + (t & 0xf))

typedef union	u_elf_sym
{
	Elf32_Sym			*_32;
	Elf64_Sym			*_64;
}	t_elf_sym;

typedef struct	s_sym_view	t_sym_view;

typedef t_uint32		t_sym_name;
typedef t_uint64		t_sym_value;
typedef t_uint64		t_sym_size;
typedef t_uint8			t_sym_info;
typedef t_uint8			t_sym_other;
typedef t_uint16		t_sym_shndx;

typedef t_sym_name		(*f_get_sym_name)(t_sym_view *);
typedef t_sym_value		(*f_get_sym_value)(t_sym_view *);
typedef t_sym_size		(*f_get_sym_size)(t_sym_view *);
typedef t_sym_info		(*f_get_sym_info)(t_sym_view *);
typedef t_sym_other		(*f_get_sym_other)(t_sym_view *);
typedef t_sym_shndx		(*f_get_sym_shndx)(t_sym_view *);

typedef void			(*f_set_sym_name)(t_sym_view *, t_sym_name);
typedef void			(*f_set_sym_value)(t_sym_view *, t_sym_value);
typedef void			(*f_set_sym_size)(t_sym_view *, t_sym_size);
typedef void			(*f_set_sym_info)(t_sym_view *, t_sym_info);
typedef void			(*f_set_sym_other)(t_sym_view *, t_sym_other);
typedef void			(*f_set_sym_shndx)(t_sym_view *, t_sym_shndx);

typedef struct s_sym_view
{
	t_elf_sym				raw;

	f_get_sym_name			get_name;
	f_get_sym_value			get_value;
	f_get_sym_size			get_size;
	f_get_sym_info			get_info;
	f_get_sym_other			get_other;
	f_get_sym_shndx			get_shndx;

	f_set_sym_name			set_name;
	f_set_sym_value			set_value;
	f_set_sym_size			set_size;
	f_set_sym_info			set_info;
	f_set_sym_other			set_other;
	f_set_sym_shndx			set_shndx;
}	t_sym_view;

#endif // FT_ELF_SYM_H
