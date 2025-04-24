/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:42:54 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/25 00:51:26 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_elf_error ft_read_e_hdr(char *file_ptr, t_e_hdr_view *e_hdr)
{
	t_elf_error		retv;

	CHECK_RET(retv, ft_make_e_hdr, file_ptr, e_hdr);
	CHECK_RET(retv, ft_check_e_hdr_type, e_hdr->get_type(e_hdr));
	CHECK_RET(retv, ft_check_e_hdr_machine, e_hdr->get_machine(e_hdr));
	CHECK_RET(retv, ft_check_e_hdr_version, e_hdr->get_version(e_hdr));
	ft_check_e_hdr_entry(e_hdr->get_entry(e_hdr));
	ft_check_e_hdr_phoff(e_hdr->get_phoff(e_hdr));
	ft_check_e_hdr_shoff(e_hdr->get_shoff(e_hdr));
	ft_check_e_hdr_flags(e_hdr->get_flags(e_hdr));
	ft_check_e_hdr_size(e_hdr->get_size(e_hdr));
	ft_check_e_hdr_phentsize(e_hdr->get_phentsize(e_hdr));
	ft_check_e_hdr_phnum(e_hdr->get_phnum(e_hdr));
	ft_check_e_hdr_shentsize(e_hdr->get_shentsize(e_hdr));
	ft_check_e_hdr_shnum(e_hdr->get_shnum(e_hdr));
	ft_check_e_hdr_shstrndx(e_hdr->get_shstrndx(e_hdr));
	return (SUCCESS);
}
