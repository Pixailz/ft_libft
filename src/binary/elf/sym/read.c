/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:25:44 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 14:36:00 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

static t_elf_shdr		*sym_hdr;
static t_sh_offset		sym_offset;
static t_sh_entsize		sym_entsize;
static t_sh_align		sym_align;
t_elf_sym				sym;

void	ft_check_sym(t_elf_sym sym)
{
	ft_check_sym_name(&sym);
	ft_check_sym_value(&sym);
	ft_check_sym_size(&sym);
	ft_check_sym_info(&sym);
	ft_check_sym_other(&sym);
	ft_check_sym_shndx(&sym);
	ft_pdeb("\n");
}

t_elf_error ft_read_sym(t_elfbin *bin, t_sym *symbole)
{
	symbole->bind = ELF_ST_BIND(symbole->info);
	symbole->type = ELF_ST_TYPE(symbole->info);
	symbole->shndx = ft_get_sym_shndx(&sym);
	symbole->name = ft_get_section_str(bin, ".strtab", ft_get_sym_name(&sym));
	symbole->shdr = ft_get_section_header_byndx(bin, symbole->shndx);
	symbole->shdr_name = ft_get_section_name_byndx(bin, symbole->shndx);
	if (ft_strncmp(symbole->name, "", 1) == 0 && symbole->shdr_name)
		symbole->name = symbole->shdr_name;

	ft_pdeb(
		"sym [%s]{.type %d, bind %d, hdr {name %s, type %d, flags %d}}\n",
		symbole->name, symbole->type, symbole->bind, symbole->shdr_name, ft_get_s_hdr_type(symbole->shdr), ft_get_s_hdr_flags(symbole->shdr)
	);

	symbole->value = ft_get_sym_value(&sym);
	symbole->type = ft_get_sym_type(symbole);
	return (SUCCESS);
}

t_elf_error	ft_read_syms_loop(t_elfbin *bin)
{
	int			index;
	int			padding;
	int			counter;

	counter = 0;
	index = sym_offset + sym_entsize;
	while (counter < bin->sym_nb)
	{
		cast_sym(bin->file_ptr + index, &sym);
		index += sym_entsize;
		if ((padding = index % sym_align))
			index += sym_align - padding;
		ft_bzero(&bin->syms[counter], sizeof(t_sym));
		bin->syms[counter].info = ft_get_sym_info(&sym);
		ft_read_sym(bin, &bin->syms[counter]);
		ft_check_sym(sym);
		counter++;
	}
	return (SUCCESS);
}

t_elf_error	ft_read_syms(t_elfbin *bin)
{
	sym_hdr = ft_get_section_header_byname(bin, ".symtab");
	if (sym_hdr == FT_NULL)
		return (NOT_FOUND_SYMTAB);
	sym_offset = ft_get_s_hdr_offset(sym_hdr);
	sym_entsize = ft_get_s_hdr_entsize(sym_hdr);
	sym_align = ft_get_s_hdr_align(sym_hdr);
	bin->sym_nb = ft_get_s_hdr_size(sym_hdr) / sym_entsize;
	bin->sym_nb--;
	ft_pdeb("sym_nb %d\n", bin->sym_nb - 1);
	bin->syms = (t_sym *)ft_calloc(sizeof(t_sym), bin->sym_nb + 1);
	return (ft_read_syms_loop(bin));
}
