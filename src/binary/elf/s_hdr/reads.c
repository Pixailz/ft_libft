/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reads.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:42:54 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 14:36:00 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

extern t_uint8	NM_CLASS;

t_elf_error ft_check_s_hdrs(t_elfbin *bin)
{
	t_eh_shnum	shnum;
	int			counter;
	t_elf_shdr	*s_hdrs;

	shnum = ft_get_e_hdr_shnum(&bin->e_hdr);
	counter = 0;
	ft_pdeb(ELF_STR_SHDR "\n");
	while (counter < shnum)
	{
		s_hdrs = &bin->s_hdrs[counter];
		ft_pdeb(
			ELF_STR_PAD ELF_STR_LIST "%s (%d)\n",
			bin->s_hdrs_name[counter], counter
		);
		ft_check_s_hdr_name(s_hdrs);
		ft_check_s_hdr_type(s_hdrs);
		ft_check_s_hdr_flags(s_hdrs);
		ft_check_s_hdr_addr(s_hdrs);
		ft_check_s_hdr_offset(s_hdrs);
		ft_check_s_hdr_size(s_hdrs);
		ft_check_s_hdr_link(s_hdrs);
		ft_check_s_hdr_info(s_hdrs);
		ft_check_s_hdr_align(s_hdrs);
		ft_check_s_hdr_entsize(s_hdrs);
		ft_pdeb("\n");
		counter++;
	}
	return (SUCCESS);
}

t_elf_error	ft_read_s_hdrs_struct(t_elfbin *bin)
{
	t_eh_shnum		shnum;
	t_eh_shoff		shoff;
	t_eh_shentsize	shentsize;
	int				counter;

	shnum = ft_get_e_hdr_shnum(&bin->e_hdr);
	if (!shnum)
		return (WRONG_SHNUM);
	shoff = ft_get_e_hdr_shoff(&bin->e_hdr);
	if (shoff >= (t_uint64)bin->stat.st_size)
		return (WRONG_SHOFF);
	shentsize = ft_get_e_hdr_shentsize(&bin->e_hdr);
	bin->s_hdrs = (t_elf_shdr *)ft_calloc(sizeof(t_elf_shdr), shnum);
	counter = 0;
	while (counter < shnum)
	{
		ft_cast_s_hdr(
			bin->file_ptr + shoff + (shentsize * counter),
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

	shstrndx = ft_get_e_hdr_shstrndx(&bin->e_hdr);
	shstr_offset = ft_get_s_hdr_offset(&bin->s_hdrs[shstrndx]);
	shnum = ft_get_e_hdr_shnum(&bin->e_hdr);
	counter = 0;
	bin->s_hdrs_name = (char **)ft_calloc(sizeof(char *), shnum + 1);
	while (counter < shnum)
	{
		shstr_name_ndx = ft_get_s_hdr_name(&bin->s_hdrs[counter]);
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
