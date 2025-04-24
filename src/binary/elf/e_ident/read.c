/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:42:54 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/25 00:27:04 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_elf_error ft_read_e_ident(char *file_ptr, t_elf_hdr_ident *e_ident)
{
	t_elf_error	retv;

	ft_pdeb(ELF_STR_EHDR_IDENT "\n");
	CHECK_RET(retv, ft_read_e_ident_mag, file_ptr, e_ident);
	CHECK_RET(retv, ft_read_e_ident_class, file_ptr);
	CHECK_RET(retv, ft_read_e_ident_endianess, file_ptr, e_ident);
	CHECK_RET(retv, ft_read_e_ident_version, file_ptr, e_ident);
	CHECK_RET(retv, ft_read_e_ident_abi, file_ptr, e_ident);
	CHECK_RET(retv, ft_read_e_ident_abi_version, file_ptr, e_ident);
	CHECK_RET(retv, ft_check_e_ident_padding, file_ptr, e_ident);
	return (retv);
}
