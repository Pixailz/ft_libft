/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf_e_hdr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:07:47 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ELF_E_HDR_H
# define FT_ELF_E_HDR_H

# include "libft_define.h"
# include <elf.h>


typedef union	u_elf_ehdr
{
	Elf32_Ehdr			*_32;
	Elf64_Ehdr			*_64;
}	t_elf_e_hdr;

typedef struct	s_e_hdr_view	t_e_hdr_view;

typedef t_uint16		t_eh_type;
typedef t_uint16		t_eh_machine;
typedef t_uint32		t_eh_version;
typedef t_uint64		t_eh_entry;
typedef t_uint64		t_eh_phoff;
typedef t_uint64		t_eh_shoff;
typedef t_uint32		t_eh_flags;
typedef t_uint16		t_eh_size;
typedef t_uint16		t_eh_phentsize;
typedef t_uint16		t_eh_phnum;
typedef t_uint16		t_eh_shentsize;
typedef t_uint16		t_eh_shnum;
typedef t_uint16		t_eh_shstrndx;

typedef t_eh_type		(*f_get_e_hdr_type)(t_e_hdr_view *);
typedef t_eh_machine	(*f_get_e_hdr_machine)(t_e_hdr_view *);
typedef t_eh_version	(*f_get_e_hdr_version)(t_e_hdr_view *);
typedef t_eh_entry		(*f_get_e_hdr_entry)(t_e_hdr_view *);
typedef t_eh_phoff		(*f_get_e_hdr_phoff)(t_e_hdr_view *);
typedef t_eh_shoff		(*f_get_e_hdr_shoff)(t_e_hdr_view *);
typedef t_eh_flags		(*f_get_e_hdr_flags)(t_e_hdr_view *);
typedef t_eh_size		(*f_get_e_hdr_size)(t_e_hdr_view *);
typedef t_eh_phentsize	(*f_get_e_hdr_phentsize)(t_e_hdr_view *);
typedef t_eh_phnum		(*f_get_e_hdr_phnum)(t_e_hdr_view *);
typedef t_eh_shentsize	(*f_get_e_hdr_shentsize)(t_e_hdr_view *);
typedef t_eh_shnum		(*f_get_e_hdr_shnum)(t_e_hdr_view *);
typedef t_eh_shstrndx	(*f_get_e_hdr_shstrndx)(t_e_hdr_view *);

typedef void			(*f_set_e_hdr_type)(t_e_hdr_view *, t_eh_type);
typedef void			(*f_set_e_hdr_machine)(t_e_hdr_view *, t_eh_machine);
typedef void			(*f_set_e_hdr_version)(t_e_hdr_view *, t_eh_version);
typedef void			(*f_set_e_hdr_entry)(t_e_hdr_view *, t_eh_entry);
typedef void			(*f_set_e_hdr_phoff)(t_e_hdr_view *, t_eh_phoff);
typedef void			(*f_set_e_hdr_shoff)(t_e_hdr_view *, t_eh_shoff);
typedef void			(*f_set_e_hdr_flags)(t_e_hdr_view *, t_eh_flags);
typedef void			(*f_set_e_hdr_size)(t_e_hdr_view *, t_eh_size);
typedef void			(*f_set_e_hdr_phentsize)(t_e_hdr_view *, t_eh_phentsize);
typedef void			(*f_set_e_hdr_phnum)(t_e_hdr_view *, t_eh_phnum);
typedef void			(*f_set_e_hdr_shentsize)(t_e_hdr_view *, t_eh_phentsize);
typedef void			(*f_set_e_hdr_shnum)(t_e_hdr_view *, t_eh_shnum);
typedef void			(*f_set_e_hdr_shstrndx)(t_e_hdr_view *, t_eh_shstrndx);

typedef struct s_e_hdr_view
{
	t_elf_e_hdr				raw;

	f_get_e_hdr_type		get_type;
	f_get_e_hdr_machine		get_machine;
	f_get_e_hdr_version		get_version;
	f_get_e_hdr_entry		get_entry;
	f_get_e_hdr_phoff		get_phoff;
	f_get_e_hdr_shoff		get_shoff;
	f_get_e_hdr_flags		get_flags;
	f_get_e_hdr_size		get_size;
	f_get_e_hdr_phentsize	get_phentsize;
	f_get_e_hdr_phnum		get_phnum;
	f_get_e_hdr_shentsize	get_shentsize;
	f_get_e_hdr_shnum		get_shnum;
	f_get_e_hdr_shstrndx	get_shstrndx;

	f_set_e_hdr_type		set_type;
	f_set_e_hdr_machine		set_machine;
	f_set_e_hdr_version		set_version;
	f_set_e_hdr_entry		set_entry;
	f_set_e_hdr_phoff		set_phoff;
	f_set_e_hdr_shoff		set_shoff;
	f_set_e_hdr_flags		set_flags;
	f_set_e_hdr_size		set_size;
	f_set_e_hdr_phentsize	set_phentsize;
	f_set_e_hdr_phnum		set_phnum;
	f_set_e_hdr_shentsize	set_shentsize;
	f_set_e_hdr_shnum		set_shnum;
	f_set_e_hdr_shstrndx	set_shstrndx;
}	t_e_hdr_view;

#endif // FT_ELF_E_HDR_H
