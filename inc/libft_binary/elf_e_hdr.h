/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf_e_hdr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 13:56:00 by brda-sil         ###   ########.fr       */
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
}	t_elf_ehdr;

typedef t_uint16		t_eh_type;
typedef t_uint16		t_eh_machine;
typedef t_uint32		t_eh_version;
typedef t_uint64		t_eh_entry;
typedef t_uint64		t_eh_phoff;
typedef t_uint64		t_eh_shoff;
typedef t_uint32		t_eh_flags;
typedef t_uint16		t_eh_ehsize;
typedef t_uint16		t_eh_phentsize;
typedef t_uint16		t_eh_phnum;
typedef t_uint16		t_eh_shentsize;
typedef t_uint16		t_eh_shnum;
typedef t_uint16		t_eh_shstrndx;

#endif // FT_ELF_E_HDR_H
