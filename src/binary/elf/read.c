/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:28:13 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 00:25:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

void	ft_readelf_free(t_elfbin bin)
{
	if (bin.file_ptr)
		munmap(bin.file_ptr, bin.stat.st_size);
	if (bin.p_hdrs)
		free(bin.p_hdrs);
	if (bin.s_hdrs)
		free(bin.s_hdrs);
	if (bin.s_hdrs_name)
		free(bin.s_hdrs_name);
	if (bin.syms)
		free(bin.syms);
}

/**
 * 1. opening and mapping the file with init_target()
 * 2. reading the ELF header identification with ft_read_e_ident()
 * 3. reading the ELF header with ft_read_e_hdr()
 * 3. reading the ELF header with ft_read_p_hdr()
 * 4. reading section headers
 * 5. read symbols
 * 6. read program headers
 */
t_elf_error	ft_readelf(char *target, t_elfbin *bin)
{
	t_elf_error	retv;

	ft_pdeb(ELF_STR_EHDR SEP "%s\n", target);
	ft_bzero(bin, sizeof(t_elfbin));
	CHECK_RET(retv, ft_open_elfbin, target, bin);
	CHECK_RET(retv, ft_read_e_ident, bin->file_ptr, &bin->e_ident);
	if (bin->stat.st_size <= 0x80)
		return (ERR_TARGET_SIZE);
	CHECK_RET(retv, ft_read_e_hdr, bin->file_ptr, &bin->e_hdr);
	CHECK_RET(retv, ft_read_s_hdrs, bin);
	CHECK_RET(retv, ft_read_syms, bin);
	CHECK_RET(retv, ft_read_p_hdrs, bin);
	return (retv);
}