/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf_s_hdr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 13:55:52 by brda-sil         ###   ########.fr       */
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
}	t_elf_shdr;

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

#endif // FT_ELF_S_HDR_H
