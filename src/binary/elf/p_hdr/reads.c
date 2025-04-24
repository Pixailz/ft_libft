/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reads.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:42:54 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/25 00:03:51 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_elf_error	ft_read_p_hdrs_struct(t_elfbin *bin)
{
	t_eh_phnum		phnum;
	t_eh_phoff		phoff;
	t_eh_phentsize	phentsize;
	int				counter;
	t_size			off;
	t_size			max;
	t_p_hdr_view	*p_hdr;

	phnum = bin->e_hdr.get_phnum(&bin->e_hdr);
	// if (!phnum)
	// 	return (WRONG_PHNUM);
	max = (t_size)bin->stat.st_size;
	phoff = bin->e_hdr.get_phoff(&bin->e_hdr);
	if (phoff >= max)
		return (WRONG_PHOFF);
	phentsize = bin->e_hdr.get_phentsize(&bin->e_hdr);
	bin->p_hdrs = (t_p_hdr_view *)ft_calloc(sizeof(t_p_hdr_view), phnum);
	counter = 0;
	while (counter < phnum)
	{
		off = phoff + (phentsize * counter);
		if (off >= max)
			return (WRONG_PENT);

		p_hdr = &bin->p_hdrs[counter];
		ft_make_p_hdr(bin->file_ptr + off, p_hdr);
		ft_check_p_hdr_type(p_hdr->get_type(p_hdr));
		ft_check_p_hdr_offset(p_hdr->get_offset(p_hdr));
		ft_check_p_hdr_vaddr(p_hdr->get_vaddr(p_hdr));
		ft_check_p_hdr_paddr(p_hdr->get_paddr(p_hdr));
		ft_check_p_hdr_filesz(p_hdr->get_filesz(p_hdr));
		ft_check_p_hdr_memsz(p_hdr->get_memsz(p_hdr));
		ft_check_p_hdr_flags(p_hdr->get_flags(p_hdr));
		ft_check_p_hdr_align(p_hdr->get_align(p_hdr));
		ft_pdeb("\n");

		counter++;
	}
	return (SUCCESS);
}

t_elf_error	ft_read_p_hdrs(t_elfbin *bin)
{
	t_elf_error	retv;

	CHECK_RET(retv, ft_read_p_hdrs_struct, bin);
	return (SUCCESS);
}