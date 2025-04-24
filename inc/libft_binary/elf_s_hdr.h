/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf_s_hdr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:13:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ELF_S_HDR_H
# define FT_ELF_S_HDR_H

# include "libft_define.h"
# include <elf.h>

typedef union	u_elf_shdr
{
	Elf32_Shdr			*_32;
	Elf64_Shdr			*_64;
}	t_elf_s_hdr;

typedef struct	s_s_hdr_view	t_s_hdr_view;

typedef t_uint32		t_sh_name;
typedef t_uint32		t_sh_type;
typedef t_uint64		t_sh_flags;
typedef t_uint64		t_sh_addr;
typedef t_uint64		t_sh_offset;
typedef t_uint64		t_sh_size;
typedef t_uint32		t_sh_link;
typedef t_uint32		t_sh_info;
typedef t_uint64		t_sh_align;
typedef t_uint64		t_sh_entsize;

typedef t_sh_name		(*f_get_s_hdr_name)(t_s_hdr_view *);
typedef t_sh_type		(*f_get_s_hdr_type)(t_s_hdr_view *);
typedef t_sh_flags		(*f_get_s_hdr_flags)(t_s_hdr_view *);
typedef t_sh_addr		(*f_get_s_hdr_addr)(t_s_hdr_view *);
typedef t_sh_offset		(*f_get_s_hdr_offset)(t_s_hdr_view *);
typedef t_sh_size		(*f_get_s_hdr_size)(t_s_hdr_view *);
typedef t_sh_link		(*f_get_s_hdr_link)(t_s_hdr_view *);
typedef t_sh_info		(*f_get_s_hdr_info)(t_s_hdr_view *);
typedef t_sh_align		(*f_get_s_hdr_align)(t_s_hdr_view *);
typedef t_sh_entsize	(*f_get_s_hdr_entsize)(t_s_hdr_view *);

typedef void			(*f_set_s_hdr_name)(t_s_hdr_view *, t_sh_name);
typedef void			(*f_set_s_hdr_type)(t_s_hdr_view *, t_sh_type);
typedef void			(*f_set_s_hdr_flags)(t_s_hdr_view *, t_sh_flags);
typedef void			(*f_set_s_hdr_addr)(t_s_hdr_view *, t_sh_addr);
typedef void			(*f_set_s_hdr_offset)(t_s_hdr_view *, t_sh_offset);
typedef void			(*f_set_s_hdr_size)(t_s_hdr_view *, t_sh_size);
typedef void			(*f_set_s_hdr_link)(t_s_hdr_view *, t_sh_link);
typedef void			(*f_set_s_hdr_info)(t_s_hdr_view *, t_sh_info);
typedef void			(*f_set_s_hdr_align)(t_s_hdr_view *, t_sh_align);
typedef void			(*f_set_s_hdr_entsize)(t_s_hdr_view *, t_sh_entsize);

typedef struct s_s_hdr_view
{
	t_elf_s_hdr				raw;

	f_get_s_hdr_name		get_name;
	f_get_s_hdr_type		get_type;
	f_get_s_hdr_flags		get_flags;
	f_get_s_hdr_addr		get_addr;
	f_get_s_hdr_offset		get_offset;
	f_get_s_hdr_size		get_size;
	f_get_s_hdr_link		get_link;
	f_get_s_hdr_info		get_info;
	f_get_s_hdr_align		get_align;
	f_get_s_hdr_entsize		get_entsize;

	f_set_s_hdr_name		set_name;
	f_set_s_hdr_type		set_type;
	f_set_s_hdr_flags		set_flags;
	f_set_s_hdr_addr		set_addr;
	f_set_s_hdr_offset		set_offset;
	f_set_s_hdr_size		set_size;
	f_set_s_hdr_link		set_link;
	f_set_s_hdr_info		set_info;
	f_set_s_hdr_align		set_align;
	f_set_s_hdr_entsize		set_entsize;
}	t_s_hdr_view;

#endif // FT_ELF_S_HDR_H
