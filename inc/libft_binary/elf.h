/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 00:48:48 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:40:49 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_ELF_H
# define LIBFT_ELF_H

/* ########################################################################## */
/* REQUIREMENTS */
/* ############ */

# include "libft_define.h"
# include "libft_print.h"
# include "libft_error.h"
# include "libft_network/ipv4.h"

# include <elf.h>

# include <sys/stat.h>
/* fstat()
 */
# include <sys/mman.h>
/* mmap()
 * munmap()
 */
# include <fcntl.h>
/* open()
 * O_RDONLY
 */

# include "elf_e_hdr.h"
# include "elf_s_hdr.h"
# include "elf_p_hdr.h"
# include "elf_sym.h"
# include "elf_fmt.h"

/* ########################################################################## */

/* ########################################################################## */
/* CONFIG */
/* ###### */

/* ########################################################################## */

/* ########################################################################## */
/* TYPEDEF */
/* ####### */

typedef enum	e_elf_error
{
	/** Init target */
	ERR_TARGET_OPEN = 1,
	ERR_TARGET_MAP,
	ERR_TARGET_STAT,
	ERR_TARGET_SIZE,
	/** Elf identification header parsing */
	ERR_IDENT_MAGIC_NUMBER,
	ERR_IDENT_KNOWN_NUMBER,
	ERR_IDENT_CLASS,
	ERR_IDENT_ENDIANESS,
	ERR_IDENT_VERSION,
	ERR_IDENT_ABI,
	ERR_IDENT_ABI_VERSION,
	/** Elf header parsing */
	ERR_CAST_HDR,
	ERR_HDR_TYPE,
	ERR_HDR_MACHINE,
	ERR_EHDR_VERSION,
	WRONG_SHNUM,
	WRONG_SHOFF,
	WRONG_SENT,
	WRONG_PHNUM,
	WRONG_PHOFF,
	WRONG_PENT,
	/** Elf Symbole parsing*/
	WARN_SYM_SKIPPED,
	NOT_FOUND_SYMTAB,
}	t_elf_error;

typedef struct	s_elf_hdr_ident
{
	t_bool	good_magic_number;
	t_uint8	endianess;
	t_uint8	version;
	t_uint8	abi;
	t_uint8	abi_version;
	t_bool	padding;
}	t_elf_hdr_ident;

typedef struct s_sym
{
	t_sym_view		view;
	t_sym_info		bind;
	t_sym_info		type;

	char			str_type;
	char*			name;

	t_s_hdr_view	shdr;
	char*			shdr_name;
	t_sh_flags		shdr_flags;
}	t_sym;

typedef struct	s_elf_bin
{
	char*				file_path;
	char*				file_ptr;
	struct stat			stat;
	t_elf_hdr_ident		e_ident;
	t_e_hdr_view		e_hdr;
	t_p_hdr_view*		p_hdrs;
	t_s_hdr_view*		s_hdrs;
	char**				s_hdrs_name;
	int					sym_nb;
	t_sym*				syms;
}	t_elfbin;


/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// binary/elf/e_hdr/attr/entry.c

t_eh_entry		ft_e_hdr_get_entry_32(t_e_hdr_view *e_hdr);
t_eh_entry		ft_e_hdr_get_entry_64(t_e_hdr_view *e_hdr);
void			ft_e_hdr_set_entry_32(t_e_hdr_view *e_hdr, t_eh_entry value);
void			ft_e_hdr_set_entry_64(t_e_hdr_view *e_hdr, t_eh_entry value);
void			ft_check_e_hdr_entry(t_eh_entry value);

// binary/elf/e_hdr/attr/flags.c

t_eh_flags		ft_e_hdr_get_flags_32(t_e_hdr_view *e_hdr);
t_eh_flags		ft_e_hdr_get_flags_64(t_e_hdr_view *e_hdr);
void			ft_e_hdr_set_flags_32(t_e_hdr_view *e_hdr, t_eh_flags value);
void			ft_e_hdr_set_flags_64(t_e_hdr_view *e_hdr, t_eh_flags value);
void			ft_check_e_hdr_flags(t_eh_flags value);

// binary/elf/e_hdr/attr/machine.c

t_eh_machine	ft_e_hdr_get_machine_32(t_e_hdr_view *e_hdr);
t_eh_machine	ft_e_hdr_get_machine_64(t_e_hdr_view *e_hdr);
void			ft_e_hdr_set_machine_32(t_e_hdr_view *e_hdr, t_eh_machine value);
void			ft_e_hdr_set_machine_64(t_e_hdr_view *e_hdr, t_eh_machine value);
t_elf_error		ft_check_e_hdr_machine(t_eh_machine value);

// binary/elf/e_hdr/attr/phentsize.c

t_eh_phentsize	ft_e_hdr_get_phentsize_32(t_e_hdr_view *e_hdr);
t_eh_phentsize	ft_e_hdr_get_phentsize_64(t_e_hdr_view *e_hdr);
void			ft_e_hdr_set_phentsize_32(t_e_hdr_view *e_hdr, t_eh_phentsize value);
void			ft_e_hdr_set_phentsize_64(t_e_hdr_view *e_hdr, t_eh_phentsize value);
void			ft_check_e_hdr_phentsize(t_eh_phentsize value);

// binary/elf/e_hdr/attr/phnum.c

t_eh_phnum		ft_e_hdr_get_phnum_32(t_e_hdr_view *e_hdr);
t_eh_phnum		ft_e_hdr_get_phnum_64(t_e_hdr_view *e_hdr);
void			ft_e_hdr_set_phnum_32(t_e_hdr_view *e_hdr, t_eh_phnum value);
void			ft_e_hdr_set_phnum_64(t_e_hdr_view *e_hdr, t_eh_phnum value);
void			ft_check_e_hdr_phnum(t_eh_phnum value);

// binary/elf/e_hdr/attr/phoff.c

t_eh_phoff		ft_e_hdr_get_phoff_32(t_e_hdr_view *e_hdr);
t_eh_phoff		ft_e_hdr_get_phoff_64(t_e_hdr_view *e_hdr);
void			ft_e_hdr_set_phoff_32(t_e_hdr_view *e_hdr, t_eh_phoff value);
void			ft_e_hdr_set_phoff_64(t_e_hdr_view *e_hdr, t_eh_phoff value);
void			ft_check_e_hdr_phoff(t_eh_phoff value);

// binary/elf/e_hdr/attr/shentsize.c

t_eh_shentsize	ft_e_hdr_get_shentsize_32(t_e_hdr_view *e_hdr);
t_eh_shentsize	ft_e_hdr_get_shentsize_64(t_e_hdr_view *e_hdr);
void			ft_e_hdr_set_shentsize_32(t_e_hdr_view *e_hdr, t_eh_shentsize value);
void			ft_e_hdr_set_shentsize_64(t_e_hdr_view *e_hdr, t_eh_shentsize value);
void			ft_check_e_hdr_shentsize(t_eh_shentsize value);

// binary/elf/e_hdr/attr/shnum.c

t_eh_shnum		ft_e_hdr_get_shnum_32(t_e_hdr_view *e_hdr);
t_eh_shnum		ft_e_hdr_get_shnum_64(t_e_hdr_view *e_hdr);
void			ft_e_hdr_set_shnum_32(t_e_hdr_view *e_hdr, t_eh_shnum value);
void			ft_e_hdr_set_shnum_64(t_e_hdr_view *e_hdr, t_eh_shnum value);
void			ft_check_e_hdr_shnum(t_eh_shnum value);

// binary/elf/e_hdr/attr/shoff.c

t_eh_shoff		ft_e_hdr_get_shoff_32(t_e_hdr_view *e_hdr);
t_eh_shoff		ft_e_hdr_get_shoff_64(t_e_hdr_view *e_hdr);
void			ft_e_hdr_set_shoff_32(t_e_hdr_view *e_hdr, t_eh_shoff value);
void			ft_e_hdr_set_shoff_64(t_e_hdr_view *e_hdr, t_eh_shoff value);
void			ft_check_e_hdr_shoff(t_eh_shoff value);

// binary/elf/e_hdr/attr/shstrndx.c

t_eh_shstrndx	ft_e_hdr_get_shstrndx_32(t_e_hdr_view *e_hdr);
t_eh_shstrndx	ft_e_hdr_get_shstrndx_64(t_e_hdr_view *e_hdr);
void			ft_e_hdr_set_shstrndx_32(t_e_hdr_view *e_hdr, t_eh_shstrndx value);
void			ft_e_hdr_set_shstrndx_64(t_e_hdr_view *e_hdr, t_eh_shstrndx value);
void			ft_check_e_hdr_shstrndx(t_eh_shstrndx value);

// binary/elf/e_hdr/attr/size.c

t_eh_size		ft_e_hdr_get_size_32(t_e_hdr_view *e_hdr);
t_eh_size		ft_e_hdr_get_size_64(t_e_hdr_view *e_hdr);
void			ft_e_hdr_set_size_32(t_e_hdr_view *e_hdr, t_eh_size value);
void			ft_e_hdr_set_size_64(t_e_hdr_view *e_hdr, t_eh_size value);
void			ft_check_e_hdr_size(t_eh_size value);

// binary/elf/e_hdr/attr/type.c

t_eh_type		ft_e_hdr_get_type_32(t_e_hdr_view *e_hdr);
t_eh_type		ft_e_hdr_get_type_64(t_e_hdr_view *e_hdr);
void			ft_e_hdr_set_type_32(t_e_hdr_view *e_hdr, t_eh_type value);
void			ft_e_hdr_set_type_64(t_e_hdr_view *e_hdr, t_eh_type value);
t_elf_error		ft_check_e_hdr_type(t_eh_type value);

// binary/elf/e_hdr/attr/version.c

t_eh_version	ft_e_hdr_get_version_32(t_e_hdr_view *e_hdr);
t_eh_version	ft_e_hdr_get_version_64(t_e_hdr_view *e_hdr);
void			ft_e_hdr_set_version_32(t_e_hdr_view *e_hdr, t_eh_version value);
void			ft_e_hdr_set_version_64(t_e_hdr_view *e_hdr, t_eh_version value);
t_elf_error		ft_check_e_hdr_version(t_eh_version value);

// binary/elf/e_hdr/make.c

t_elf_error		ft_make_e_hdr(char *file_ptr, t_e_hdr_view *e_hdr);

// binary/elf/e_hdr/read.c

t_elf_error		ft_read_e_hdr(char *file_ptr, t_e_hdr_view *e_hdr);

// binary/elf/e_ident/check_padding.c

t_elf_error		ft_check_e_ident_padding(char *file_ptr, t_elf_hdr_ident *elf_hdr);

// binary/elf/e_ident/read.c

t_elf_error		ft_read_e_ident(char *file_ptr, t_elf_hdr_ident *e_ident);

// binary/elf/e_ident/read_abi.c

t_elf_error		ft_read_e_ident_abi(char *file_ptr, t_elf_hdr_ident *elf_hdr);

// binary/elf/e_ident/read_abi_version.c

t_elf_error		ft_read_e_ident_abi_version(char *file_ptr, t_elf_hdr_ident *elf_hdr);

// binary/elf/e_ident/read_class.c

t_elf_error		ft_read_e_ident_class(char *file_ptr);

// binary/elf/e_ident/read_endianess.c

t_elf_error		ft_read_e_ident_endianess(char *file_ptr, t_elf_hdr_ident *e_ident);

// binary/elf/e_ident/read_mag.c

t_elf_error		ft_read_e_ident_known_mag(int magic_number);
t_elf_error		ft_read_e_ident_mag(char *file_ptr, t_elf_hdr_ident *e_ident);

// binary/elf/e_ident/read_version.c

t_elf_error		ft_read_e_ident_version(char *file_ptr, t_elf_hdr_ident *e_ident);

// binary/elf/open.c

t_elf_error		ft_map_file(int fd, t_int32 size, char **ptr);
t_elf_error		ft_get_file_stat(int fd, struct stat *stat);
t_elf_error		ft_open_elfbin(char *path, t_elfbin *bin);

// binary/elf/p_hdr/attr/align.c

t_ph_align		ft_p_hdr_get_align_32(t_p_hdr_view *p_hdr);
t_ph_align		ft_p_hdr_get_align_64(t_p_hdr_view *p_hdr);
void			ft_p_hdr_set_align_32(t_p_hdr_view *p_hdr, t_ph_align value);
void			ft_p_hdr_set_align_64(t_p_hdr_view *p_hdr, t_ph_align value);
void			ft_check_p_hdr_align(t_ph_align value);

// binary/elf/p_hdr/attr/filesz.c

t_ph_filesz		ft_p_hdr_get_filesz_32(t_p_hdr_view *p_hdr);
t_ph_filesz		ft_p_hdr_get_filesz_64(t_p_hdr_view *p_hdr);
void			ft_p_hdr_set_filesz_32(t_p_hdr_view *p_hdr, t_ph_filesz value);
void			ft_p_hdr_set_filesz_64(t_p_hdr_view *p_hdr, t_ph_filesz value);
void			ft_check_p_hdr_filesz(t_ph_filesz value);

// binary/elf/p_hdr/attr/flags.c

t_ph_flags		ft_p_hdr_get_flags_32(t_p_hdr_view *p_hdr);
t_ph_flags		ft_p_hdr_get_flags_64(t_p_hdr_view *p_hdr);
void			ft_p_hdr_set_flags_32(t_p_hdr_view *p_hdr, t_ph_flags value);
void			ft_p_hdr_set_flags_64(t_p_hdr_view *p_hdr, t_ph_flags value);
void			ft_check_p_hdr_flags(t_ph_flags value);

// binary/elf/p_hdr/attr/memsz.c

t_ph_memsz		ft_p_hdr_get_memsz_32(t_p_hdr_view *p_hdr);
t_ph_memsz		ft_p_hdr_get_memsz_64(t_p_hdr_view *p_hdr);
void			ft_p_hdr_set_memsz_32(t_p_hdr_view *p_hdr, t_ph_memsz value);
void			ft_p_hdr_set_memsz_64(t_p_hdr_view *p_hdr, t_ph_memsz value);
void			ft_check_p_hdr_memsz(t_ph_memsz value);

// binary/elf/p_hdr/attr/offset.c

t_ph_offset		ft_p_hdr_get_offset_32(t_p_hdr_view *p_hdr);
t_ph_offset		ft_p_hdr_get_offset_64(t_p_hdr_view *p_hdr);
void			ft_p_hdr_set_offset_32(t_p_hdr_view *p_hdr, t_ph_offset value);
void			ft_p_hdr_set_offset_64(t_p_hdr_view *p_hdr, t_ph_offset value);
void			ft_check_p_hdr_offset(t_ph_offset value);

// binary/elf/p_hdr/attr/paddr.c

t_ph_paddr		ft_p_hdr_get_paddr_32(t_p_hdr_view *p_hdr);
t_ph_paddr		ft_p_hdr_get_paddr_64(t_p_hdr_view *p_hdr);
void			ft_p_hdr_set_paddr_32(t_p_hdr_view *p_hdr, t_ph_paddr value);
void			ft_p_hdr_set_paddr_64(t_p_hdr_view *p_hdr, t_ph_paddr value);
void			ft_check_p_hdr_paddr(t_ph_paddr value);

// binary/elf/p_hdr/attr/type.c

t_ph_type		ft_p_hdr_get_type_32(t_p_hdr_view *p_hdr);
t_ph_type		ft_p_hdr_get_type_64(t_p_hdr_view *p_hdr);
void			ft_p_hdr_set_type_32(t_p_hdr_view *p_hdr, t_ph_type value);
void			ft_p_hdr_set_type_64(t_p_hdr_view *p_hdr, t_ph_type value);
t_elf_error		ft_check_p_hdr_type(t_ph_type value);

// binary/elf/p_hdr/attr/vaddr.c

t_ph_vaddr		ft_p_hdr_get_vaddr_32(t_p_hdr_view *p_hdr);
t_ph_vaddr		ft_p_hdr_get_vaddr_64(t_p_hdr_view *p_hdr);
void			ft_p_hdr_set_vaddr_32(t_p_hdr_view *p_hdr, t_ph_vaddr value);
void			ft_p_hdr_set_vaddr_64(t_p_hdr_view *p_hdr, t_ph_vaddr value);
void			ft_check_p_hdr_vaddr(t_ph_vaddr value);

// binary/elf/p_hdr/make.c

t_elf_error		ft_make_p_hdr(char *file_ptr, t_p_hdr_view *p_hdr);

// binary/elf/p_hdr/reads.c

t_elf_error		ft_read_p_hdrs_struct(t_elfbin *bin);
t_elf_error		ft_read_p_hdrs(t_elfbin *bin);

// binary/elf/read.c

void			ft_readelf_free(t_elfbin bin);
t_elf_error		ft_readelf(char *target, t_elfbin *bin);

// binary/elf/s_hdr/attr/addr.c

t_sh_addr		ft_s_hdr_get_addr_32(t_s_hdr_view *s_hdr);
t_sh_addr		ft_s_hdr_get_addr_64(t_s_hdr_view *s_hdr);
void			ft_s_hdr_set_addr_32(t_s_hdr_view *s_hdr, t_sh_addr value);
void			ft_s_hdr_set_addr_64(t_s_hdr_view *s_hdr, t_sh_addr value);
void			ft_check_s_hdr_addr(t_sh_addr value);

// binary/elf/s_hdr/attr/align.c

t_sh_align		ft_s_hdr_get_align_32(t_s_hdr_view *s_hdr);
t_sh_align		ft_s_hdr_get_align_64(t_s_hdr_view *s_hdr);
void			ft_s_hdr_set_align_32(t_s_hdr_view *s_hdr, t_sh_align value);
void			ft_s_hdr_set_align_64(t_s_hdr_view *s_hdr, t_sh_align value);
void			ft_check_s_hdr_align(t_sh_align value);

// binary/elf/s_hdr/attr/entsize.c

t_sh_entsize	ft_s_hdr_get_entsize_32(t_s_hdr_view *s_hdr);
t_sh_entsize	ft_s_hdr_get_entsize_64(t_s_hdr_view *s_hdr);
void			ft_s_hdr_set_entsize_32(t_s_hdr_view *s_hdr, t_sh_entsize value);
void			ft_s_hdr_set_entsize_64(t_s_hdr_view *s_hdr, t_sh_entsize value);
void			ft_check_s_hdr_entsize(t_sh_entsize value);

// binary/elf/s_hdr/attr/flags.c

t_sh_flags		ft_s_hdr_get_flags_32(t_s_hdr_view *s_hdr);
t_sh_flags		ft_s_hdr_get_flags_64(t_s_hdr_view *s_hdr);
void			ft_s_hdr_set_flags_32(t_s_hdr_view *s_hdr, t_sh_flags value);
void			ft_s_hdr_set_flags_64(t_s_hdr_view *s_hdr, t_sh_flags value);
void			ft_check_s_hdr_flags(t_sh_flags value);

// binary/elf/s_hdr/attr/info.c

t_sh_info		ft_s_hdr_get_info_32(t_s_hdr_view *s_hdr);
t_sh_info		ft_s_hdr_get_info_64(t_s_hdr_view *s_hdr);
void			ft_s_hdr_set_info_32(t_s_hdr_view *s_hdr, t_sh_info value);
void			ft_s_hdr_set_info_64(t_s_hdr_view *s_hdr, t_sh_info value);
void			ft_check_s_hdr_info(t_sh_info value);

// binary/elf/s_hdr/attr/link.c

t_sh_link		ft_s_hdr_get_link_32(t_s_hdr_view *s_hdr);
t_sh_link		ft_s_hdr_get_link_64(t_s_hdr_view *s_hdr);
void			ft_s_hdr_set_link_32(t_s_hdr_view *s_hdr, t_sh_link value);
void			ft_s_hdr_set_link_64(t_s_hdr_view *s_hdr, t_sh_link value);
void			ft_check_s_hdr_link(t_sh_link value);

// binary/elf/s_hdr/attr/name.c

t_sh_name		ft_s_hdr_get_name_32(t_s_hdr_view *s_hdr);
t_sh_name		ft_s_hdr_get_name_64(t_s_hdr_view *s_hdr);
void			ft_s_hdr_set_name_32(t_s_hdr_view *s_hdr, t_sh_name value);
void			ft_s_hdr_set_name_64(t_s_hdr_view *s_hdr, t_sh_name value);
void			ft_check_s_hdr_name(t_sh_name value);

// binary/elf/s_hdr/attr/offset.c

t_sh_offset		ft_s_hdr_get_offset_32(t_s_hdr_view *s_hdr);
t_sh_offset		ft_s_hdr_get_offset_64(t_s_hdr_view *s_hdr);
void			ft_s_hdr_set_offset_32(t_s_hdr_view *s_hdr, t_sh_offset value);
void			ft_s_hdr_set_offset_64(t_s_hdr_view *s_hdr, t_sh_offset value);
void			ft_check_s_hdr_offset(t_sh_offset value);

// binary/elf/s_hdr/attr/size.c

t_sh_size		ft_s_hdr_get_size_32(t_s_hdr_view *s_hdr);
t_sh_size		ft_s_hdr_get_size_64(t_s_hdr_view *s_hdr);
void			ft_s_hdr_set_size_32(t_s_hdr_view *s_hdr, t_sh_size value);
void			ft_s_hdr_set_size_64(t_s_hdr_view *s_hdr, t_sh_size value);
void			ft_check_s_hdr_size(t_sh_size value);

// binary/elf/s_hdr/attr/type.c

t_sh_type		ft_s_hdr_get_type_32(t_s_hdr_view *s_hdr);
t_sh_type		ft_s_hdr_get_type_64(t_s_hdr_view *s_hdr);
void			ft_s_hdr_set_type_32(t_s_hdr_view *s_hdr, t_sh_type value);
void			ft_s_hdr_set_type_64(t_s_hdr_view *s_hdr, t_sh_type value);
void			ft_check_s_hdr_type(t_sh_type value);

// binary/elf/s_hdr/get_section.c

int				ft_get_section_index_byname(t_elfbin *bin, char *name);
t_s_hdr_view	*ft_get_section_header_byname(t_elfbin *bin, char *name);
t_s_hdr_view	*ft_get_section_header_byndx(t_elfbin *bin, t_eh_shstrndx ndx);
char			*ft_get_section_str(t_elfbin *bin, char *name, int at);
char			*ft_get_section_name_byndx(t_elfbin *bin, t_eh_shstrndx ndx);

// binary/elf/s_hdr/make.c

t_elf_error		ft_make_s_hdr(char *file_ptr, t_s_hdr_view *s_hdr);

// binary/elf/s_hdr/reads.c

void			ft_check_s_hdrs(t_elfbin *bin);
t_elf_error		ft_read_s_hdrs_struct(t_elfbin *bin);
t_elf_error		ft_read_s_hdrs_name(t_elfbin *bin);
t_elf_error		ft_read_s_hdrs(t_elfbin *bin);

// binary/elf/sym/attr/info.c

t_sym_info		ft_sym_get_info_32(t_sym_view *sym);
t_sym_info		ft_sym_get_info_64(t_sym_view *sym);
void			ft_sym_set_info_32(t_sym_view *sym, t_sym_info value);
void			ft_sym_set_info_64(t_sym_view *sym, t_sym_info value);
void			ft_check_sym_info(t_sym_info value);

// binary/elf/sym/attr/name.c

t_sym_name		ft_sym_get_name_32(t_sym_view *sym);
t_sym_name		ft_sym_get_name_64(t_sym_view *sym);
void			ft_sym_set_name_32(t_sym_view *sym, t_sym_name value);
void			ft_sym_set_name_64(t_sym_view *sym, t_sym_name value);
void			ft_check_sym_name(t_sym_name value);

// binary/elf/sym/attr/other.c

t_sym_other		ft_sym_get_other_32(t_sym_view *sym);
t_sym_other		ft_sym_get_other_64(t_sym_view *sym);
void			ft_sym_set_other_32(t_sym_view *sym, t_sym_other value);
void			ft_sym_set_other_64(t_sym_view *sym, t_sym_other value);
void			ft_check_sym_other(t_sym_other value);

// binary/elf/sym/attr/shndx.c

t_sym_shndx		ft_sym_get_shndx_32(t_sym_view *sym);
t_sym_shndx		ft_sym_get_shndx_64(t_sym_view *sym);
void			ft_sym_set_shndx_32(t_sym_view *sym, t_sym_shndx value);
void			ft_sym_set_shndx_64(t_sym_view *sym, t_sym_shndx value);
void			ft_check_sym_shndx(t_sym_shndx value);

// binary/elf/sym/attr/size.c

t_sym_size		ft_sym_get_size_32(t_sym_view *sym);
t_sym_size		ft_sym_get_size_64(t_sym_view *sym);
void			ft_sym_set_size_32(t_sym_view *sym, t_sym_size value);
void			ft_sym_set_size_64(t_sym_view *sym, t_sym_size value);
void			ft_check_sym_size(t_sym_size value);

// binary/elf/sym/attr/value.c

t_sym_value		ft_sym_get_value_32(t_sym_view *sym);
t_sym_value		ft_sym_get_value_64(t_sym_view *sym);
void			ft_sym_set_value_32(t_sym_view *sym, t_sym_value value);
void			ft_sym_set_value_64(t_sym_view *sym, t_sym_value value);
void			ft_check_sym_value(t_sym_value value);

// binary/elf/sym/make.c

t_elf_error		ft_make_sym(char *file_ptr, t_sym_view *sym);

// binary/elf/sym/read.c

void			ft_check_sym(t_sym_view *sym);
t_elf_error		ft_read_sym(t_elfbin *bin, t_sym *symbole);
t_elf_error		ft_read_syms_loop(t_elfbin *bin);
t_elf_error		ft_read_syms(t_elfbin *bin);

// binary/elf/sym/type.c

char			ft_get_sym_type(t_sym *symbole);

/* ########################################################################## */

#endif /* LIBFT_ELF_H */
