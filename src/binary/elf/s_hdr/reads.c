/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reads.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:42:54 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/25 00:50:46 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

void ft_check_s_hdrs(t_elfbin *bin)
{
	t_eh_shnum		shnum;
	int				counter;
	t_s_hdr_view	*s_hdr;

	shnum = bin->e_hdr.get_shnum(&bin->e_hdr);
	counter = 0;
	ft_pdeb(ELF_STR_SHDR "\n");
	while (counter < shnum)
	{
		s_hdr = &bin->s_hdrs[counter];
		ft_pdeb(
			ELF_STR_PAD ELF_STR_LIST "%s (%d)\n",
			bin->s_hdrs_name[counter], counter
		);
		ft_check_s_hdr_name(s_hdr->get_name(s_hdr));
		ft_check_s_hdr_type(s_hdr->get_type(s_hdr));
		ft_check_s_hdr_flags(s_hdr->get_flags(s_hdr));
		ft_check_s_hdr_addr(s_hdr->get_addr(s_hdr));
		ft_check_s_hdr_offset(s_hdr->get_offset(s_hdr));
		ft_check_s_hdr_size(s_hdr->get_size(s_hdr));
		ft_check_s_hdr_link(s_hdr->get_link(s_hdr));
		ft_check_s_hdr_info(s_hdr->get_info(s_hdr));
		ft_check_s_hdr_align(s_hdr->get_align(s_hdr));
		ft_check_s_hdr_entsize(s_hdr->get_entsize(s_hdr));
		ft_pdeb("\n");
		counter++;
	}
}

t_elf_error	ft_read_s_hdrs_struct(t_elfbin *bin)
{
	t_eh_shnum		shnum;
	t_eh_shoff		shoff;
	t_eh_shentsize	shentsize;
	int				counter;
	t_size			off;
	t_size			max;

	shnum = bin->e_hdr.get_shnum(&bin->e_hdr);
	if (!shnum)
		return (WRONG_SHNUM);
	max = (t_size)bin->stat.st_size;
	shoff = bin->e_hdr.get_shoff(&bin->e_hdr);
	if (shoff >= max)
		return (WRONG_SHOFF);
	shentsize = bin->e_hdr.get_shentsize(&bin->e_hdr);
	bin->s_hdrs = (t_s_hdr_view *)ft_calloc(sizeof(t_s_hdr_view), shnum);
	counter = 0;
	while (counter < shnum)
	{
		off = shoff + (shentsize * counter);
		if (off >= max)
			return (WRONG_SENT);
		ft_make_s_hdr(
			bin->file_ptr + off,
			&bin->s_hdrs[counter]
		);
		counter++;
	}
	return (SUCCESS);
}

t_elf_error	ft_read_s_hdrs_name(t_elfbin *bin)
{
	t_eh_shnum		shnum;
	int				counter;
	t_eh_shstrndx	shstrndx;
	t_sh_offset		shstr_offset;
	t_sh_name		shstr_name_ndx;

	shstrndx = bin->e_hdr.get_shstrndx(&bin->e_hdr);
	shnum = bin->e_hdr.get_shnum(&bin->e_hdr);
	shstr_offset = bin->s_hdrs[shstrndx].get_offset(&bin->s_hdrs[shstrndx]);
	counter = 0;
	bin->s_hdrs_name = (char **)ft_calloc(sizeof(char *), shnum + 1);
	while (counter < shnum)
	{
		shstr_name_ndx = bin->s_hdrs[counter].get_name(&bin->s_hdrs[counter]);
		bin->s_hdrs_name[counter] = bin->file_ptr + shstr_offset + shstr_name_ndx;
		counter++;
	}
	return (SUCCESS);
}

t_elf_error ft_read_s_hdrs(t_elfbin *bin)
{
	t_elf_error	retv;

	CHECK_RET(retv, ft_read_s_hdrs_struct, bin);
	CHECK_RET(retv, ft_read_s_hdrs_name, bin);
	ft_check_s_hdrs(bin);
	return (SUCCESS);
}
