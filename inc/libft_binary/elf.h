/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 00:48:48 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 15:14:06 by brda-sil         ###   ########.fr       */
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
	/** Elf Symbole parsing*/
	WARN_SYM_SKIPPED,
	WRONG_SHNUM,
	WRONG_SHOFF,
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
	t_sym_value		value;
	t_sym_size		size;
	t_sym_shndx		shndx;
	t_sym_info		info;
	t_sym_info		bind;
	t_sym_info		type;
	t_elf_shdr		*shdr;
	t_eh_flags		shdr_flags;
	char			*shdr_name;
	char			str_type;
	char			*name;
}	t_sym;

typedef struct	s_elf_bin
{
	char*				file_path;
	char*				file_ptr;
	struct stat			stat;
	t_elf_hdr_ident		e_ident;
	t_elf_ehdr			e_hdr;
	t_elf_shdr*			s_hdrs;
	char**				s_hdrs_name;
	int					sym_nb;
	t_sym*				syms;
}	t_elfbin;


/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// binary/elf/e_hdr/attr/entry.c

t_eh_entry		ft_get_e_hdr_entry(t_elf_ehdr *e_hdr);
t_elf_error		ft_check_e_hdr_entry(t_elf_ehdr *e_hdr);

// binary/elf/e_hdr/attr/flags.c

t_eh_flags		ft_get_e_hdr_flags(t_elf_ehdr *e_hdr);
t_elf_error		ft_check_e_hdr_flags(t_elf_ehdr *e_hdr);

// binary/elf/e_hdr/attr/header_size.c

t_eh_ehsize		ft_get_e_hdr_ehsize(t_elf_ehdr *e_hdr);
t_elf_error		ft_check_e_hdr_ehsize(t_elf_ehdr *e_hdr);

// binary/elf/e_hdr/attr/machine.c

t_eh_machine	ft_get_e_hdr_machine(t_elf_ehdr *e_hdr);
t_elf_error		ft_check_e_hdr_machine(t_elf_ehdr *e_hdr);

// binary/elf/e_hdr/attr/phoff.c

t_eh_entry		ft_get_e_hdr_phoff(t_elf_ehdr *e_hdr);
t_elf_error		ft_check_e_hdr_phoff(t_elf_ehdr *e_hdr);

// binary/elf/e_hdr/attr/prog_header_num.c

t_eh_phentsize	ft_get_e_hdr_phentsize(t_elf_ehdr *e_hdr);
t_elf_error		ft_check_e_hdr_phentsize(t_elf_ehdr *e_hdr);

// binary/elf/e_hdr/attr/prog_header_size.c

t_eh_phnum		ft_get_e_hdr_phnum(t_elf_ehdr *e_hdr);
t_elf_error		ft_check_e_hdr_phnum(t_elf_ehdr *e_hdr);

// binary/elf/e_hdr/attr/sect_header_num.c

t_eh_shnum		ft_get_e_hdr_shnum(t_elf_ehdr *e_hdr);
t_elf_error		ft_check_e_hdr_shnum(t_elf_ehdr *e_hdr);

// binary/elf/e_hdr/attr/sect_header_size.c

t_eh_shentsize	ft_get_e_hdr_shentsize(t_elf_ehdr *e_hdr);
t_elf_error		ft_check_e_hdr_shentsize(t_elf_ehdr *e_hdr);

// binary/elf/e_hdr/attr/sect_header_txt_index.c

t_eh_shstrndx	ft_get_e_hdr_shstrndx(t_elf_ehdr *e_hdr);
t_elf_error		ft_check_e_hdr_shstrndx(t_elf_ehdr *e_hdr);

// binary/elf/e_hdr/attr/shoff.c

t_eh_shoff		ft_get_e_hdr_shoff(t_elf_ehdr *e_hdr);
t_elf_error		ft_check_e_hdr_shoff(t_elf_ehdr *e_hdr);

// binary/elf/e_hdr/attr/type.c

t_eh_type		ft_get_e_hdr_type(t_elf_ehdr *e_hdr);
t_elf_error		ft_check_e_hdr_type(t_elf_ehdr *e_hdr);

// binary/elf/e_hdr/attr/version.c

t_eh_type		ft_get_e_hdr_version(t_elf_ehdr *e_hdr);
t_elf_error		ft_check_e_hdr_version(t_elf_ehdr *e_hdr);

// binary/elf/e_hdr/cast.c

t_elf_error		ft_cast_e_hdr(char *file_ptr, t_elf_ehdr *e_hdr);

// binary/elf/e_hdr/check.c

t_bool			ft_is_good_e_hdr(t_elf_ehdr *e_hdr);

// binary/elf/e_hdr/read.c

t_elf_error		ft_read_e_hdr(char *file_ptr, t_elf_ehdr *e_hdr);

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

// binary/elf/error.c

t_elf_error		ft_nm_error(t_elf_error retv, char *target);

// binary/elf/open.c

t_elf_error		ft_map_file(int fd, t_int32 size, char **ptr);
t_elf_error		ft_get_file_stat(int fd, struct stat *stat);
t_elf_error		ft_open_elfbin(char *path, t_elfbin *bin);

// binary/elf/s_hdr/attr/addr.c

t_sh_addr		ft_get_s_hdr_addr(t_elf_shdr *s_hdr);
t_elf_error		ft_check_s_hdr_addr(t_elf_shdr *s_hdr);

// binary/elf/s_hdr/attr/align.c

t_sh_align		ft_get_s_hdr_align(t_elf_shdr *s_hdr);
t_elf_error		ft_check_s_hdr_align(t_elf_shdr *s_hdr);

// binary/elf/s_hdr/attr/entsize.c

t_sh_entsize	ft_get_s_hdr_entsize(t_elf_shdr *s_hdr);
t_elf_error		ft_check_s_hdr_entsize(t_elf_shdr *s_hdr);

// binary/elf/s_hdr/attr/flags.c

t_sh_type		ft_get_s_hdr_flags(t_elf_shdr *s_hdr);
t_elf_error		ft_check_s_hdr_flags(t_elf_shdr *s_hdr);

// binary/elf/s_hdr/attr/info.c

t_sh_info		ft_get_s_hdr_info(t_elf_shdr *s_hdr);
t_elf_error		ft_check_s_hdr_info(t_elf_shdr *s_hdr);

// binary/elf/s_hdr/attr/link.c

t_sh_link		ft_get_s_hdr_link(t_elf_shdr *s_hdr);
t_elf_error		ft_check_s_hdr_link(t_elf_shdr *s_hdr);

// binary/elf/s_hdr/attr/name.c

t_sh_name		ft_get_s_hdr_name(t_elf_shdr *s_hdr);
t_elf_error		ft_check_s_hdr_name(t_elf_shdr *s_hdr);

// binary/elf/s_hdr/attr/offset.c

t_sh_offset		ft_get_s_hdr_offset(t_elf_shdr *s_hdr);
t_elf_error		ft_check_s_hdr_offset(t_elf_shdr *s_hdr);

// binary/elf/s_hdr/attr/size.c

t_sh_size		ft_get_s_hdr_size(t_elf_shdr *s_hdr);
t_elf_error		ft_check_s_hdr_size(t_elf_shdr *s_hdr);

// binary/elf/s_hdr/attr/type.c

t_sh_type		ft_get_s_hdr_type(t_elf_shdr *s_hdr);
t_elf_error		ft_check_s_hdr_type(t_elf_shdr *s_hdr);

// binary/elf/s_hdr/cast.c

t_elf_error		ft_cast_s_hdr(char *file_ptr, t_elf_shdr *s_hdr);

// binary/elf/s_hdr/check.c

t_bool			ft_is_good_s_hdr(t_elf_shdr *s_hdr);

// binary/elf/s_hdr/get_section.c

int				ft_get_section_index_byname(t_elfbin *bin, char *name);
t_elf_shdr		*ft_get_section_header_byname(t_elfbin *bin, char *name);
t_elf_shdr		*ft_get_section_header_byndx(t_elfbin *bin, t_eh_shstrndx ndx);
char			*ft_get_section_str(t_elfbin *bin, char *name, int at);
char			*ft_get_section_name_byndx(t_elfbin *bin, t_eh_shstrndx ndx);

// binary/elf/s_hdr/reads.c

t_elf_error		ft_check_s_hdrs(t_elfbin *bin);
t_elf_error		ft_read_s_hdrs_struct(t_elfbin *bin);
t_elf_error		ft_read_s_hdrs_name(t_elfbin *bin);
t_elf_error		ft_read_s_hdrs(t_elfbin *bin);

// binary/elf/sym/attr/info.c

t_sym_info		ft_get_sym_info(t_elf_sym *sym);
t_elf_error		ft_check_sym_info(t_elf_sym *sym);

// binary/elf/sym/attr/name.c

t_sym_name		ft_get_sym_name(t_elf_sym *sym);
t_elf_error		ft_check_sym_name(t_elf_sym *sym);

// binary/elf/sym/attr/other.c

t_sym_other		ft_get_sym_other(t_elf_sym *sym);
t_elf_error		ft_check_sym_other(t_elf_sym *sym);

// binary/elf/sym/attr/shndx.c

t_sym_shndx		ft_get_sym_shndx(t_elf_sym *sym);
t_elf_error		ft_check_sym_shndx(t_elf_sym *sym);

// binary/elf/sym/attr/size.c

t_sym_size		ft_get_sym_size(t_elf_sym *sym);
t_elf_error		ft_check_sym_size(t_elf_sym *sym);

// binary/elf/sym/attr/value.c

t_sym_value		ft_get_sym_value(t_elf_sym *sym);
t_elf_error		ft_check_sym_value(t_elf_sym *sym);

// binary/elf/sym/cast.c

t_elf_error		cast_sym(char *file_ptr, t_elf_sym *sym);

// binary/elf/sym/check.c

t_bool			is_good_sym(t_elf_sym *sym);

// binary/elf/sym/read.c

void			ft_check_sym(t_elf_sym sym);
t_elf_error		ft_read_sym(t_elfbin *bin, t_sym *symbole);
t_elf_error		ft_read_syms_loop(t_elfbin *bin);
t_elf_error		ft_read_syms(t_elfbin *bin);

// binary/elf/sym/type.c

char			ft_get_sym_type(t_sym *symbole);

/* ########################################################################## */

#endif /* LIBFT_ELF_H */
