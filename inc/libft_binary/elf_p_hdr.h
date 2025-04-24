/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf_p_hdr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:13:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ELF_H_HDR_H
# define FT_ELF_H_HDR_H

# include "libft_define.h"
# include <elf.h>

typedef union	u_elf_phdr
{
	Elf32_Phdr			*_32;
	Elf64_Phdr			*_64;
}	t_elf_p_hdr;

typedef struct	s_p_hdr_view	t_p_hdr_view;

typedef t_uint32		t_ph_type;
typedef t_uint64		t_ph_offset;
typedef t_uint64		t_ph_vaddr;
typedef t_uint64		t_ph_paddr;
typedef t_uint64		t_ph_filesz;
typedef t_uint64		t_ph_memsz;
typedef t_uint32		t_ph_flags;
typedef t_uint64		t_ph_align;

typedef t_ph_type		(*f_get_p_hdr_type)(t_p_hdr_view *);
typedef t_ph_offset		(*f_get_p_hdr_offset)(t_p_hdr_view *);
typedef t_ph_vaddr		(*f_get_p_hdr_vaddr)(t_p_hdr_view *);
typedef t_ph_paddr		(*f_get_p_hdr_paddr)(t_p_hdr_view *);
typedef t_ph_filesz		(*f_get_p_hdr_filesz)(t_p_hdr_view *);
typedef t_ph_memsz		(*f_get_p_hdr_memsz)(t_p_hdr_view *);
typedef t_ph_flags		(*f_get_p_hdr_flags)(t_p_hdr_view *);
typedef t_ph_align		(*f_get_p_hdr_align)(t_p_hdr_view *);

typedef void			(*f_set_p_hdr_type)(t_p_hdr_view *, t_ph_type);
typedef void			(*f_set_p_hdr_offset)(t_p_hdr_view *, t_ph_offset);
typedef void			(*f_set_p_hdr_vaddr)(t_p_hdr_view *, t_ph_vaddr);
typedef void			(*f_set_p_hdr_paddr)(t_p_hdr_view *, t_ph_paddr);
typedef void			(*f_set_p_hdr_filesz)(t_p_hdr_view *, t_ph_filesz);
typedef void			(*f_set_p_hdr_memsz)(t_p_hdr_view *, t_ph_memsz);
typedef void			(*f_set_p_hdr_flags)(t_p_hdr_view *, t_ph_flags);
typedef void			(*f_set_p_hdr_align)(t_p_hdr_view *, t_ph_align);

typedef struct s_p_hdr_view
{
	t_elf_p_hdr			raw;

	f_get_p_hdr_type	get_type;
	f_get_p_hdr_offset	get_offset;
	f_get_p_hdr_vaddr	get_vaddr;
	f_get_p_hdr_paddr	get_paddr;
	f_get_p_hdr_filesz	get_filesz;
	f_get_p_hdr_memsz	get_memsz;
	f_get_p_hdr_flags	get_flags;
	f_get_p_hdr_align	get_align;

	f_set_p_hdr_type	set_type;
	f_set_p_hdr_offset	set_offset;
	f_set_p_hdr_vaddr	set_vaddr;
	f_set_p_hdr_paddr	set_paddr;
	f_set_p_hdr_filesz	set_filesz;
	f_set_p_hdr_memsz	set_memsz;
	f_set_p_hdr_flags	set_flags;
	f_set_p_hdr_align	set_align;

}	t_p_hdr_view;

#endif // FT_ELF_H_HDR_H
