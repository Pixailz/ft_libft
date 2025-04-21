/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:42:54 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 14:14:43 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

extern t_uint8	NM_CLASS;

t_elf_error ft_read_e_hdr(char *file_ptr, t_elf_ehdr *e_hdr)
{
	t_elf_error		retv;

	ft_bzero(e_hdr, sizeof(e_hdr));
	CHECK_RET(retv, ft_cast_e_hdr, file_ptr, e_hdr);
	CHECK_RET(retv, ft_check_e_hdr_type, e_hdr);
	CHECK_RET(retv, ft_check_e_hdr_machine, e_hdr);
	CHECK_RET(retv, ft_check_e_hdr_version, e_hdr);
	CHECK_RET(retv, ft_check_e_hdr_entry, e_hdr);
	CHECK_RET(retv, ft_check_e_hdr_phoff, e_hdr);
	CHECK_RET(retv, ft_check_e_hdr_shoff, e_hdr);
	CHECK_RET(retv, ft_check_e_hdr_flags, e_hdr);
	CHECK_RET(retv, ft_check_e_hdr_ehsize, e_hdr);
	CHECK_RET(retv, ft_check_e_hdr_phentsize, e_hdr);
	CHECK_RET(retv, ft_check_e_hdr_phnum, e_hdr);
	CHECK_RET(retv, ft_check_e_hdr_shentsize, e_hdr);
	CHECK_RET(retv, ft_check_e_hdr_shnum, e_hdr);
	CHECK_RET(retv, ft_check_e_hdr_shstrndx, e_hdr);
	return (SUCCESS);
}
