/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:25:44 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/25 00:50:36 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

static t_s_hdr_view		*sym_hdr;
static t_sh_offset		sym_offset;
static t_sh_entsize		sym_entsize;
static t_sh_align		sym_align;

void	ft_check_sym(t_sym_view *sym)
{
	ft_check_sym_name(sym->get_name(sym));
	ft_check_sym_value(sym->get_value(sym));
	ft_check_sym_size(sym->get_size(sym));
	ft_check_sym_info(sym->get_info(sym));
	ft_check_sym_other(sym->get_other(sym));
	ft_check_sym_shndx(sym->get_shndx(sym));
	ft_pdeb("\n");
}

t_elf_error ft_read_sym(t_elfbin *bin, t_sym *symbole)
{
	t_sym_info		info;
	t_sym_shndx		ndx;
	t_s_hdr_view	*shdr;

	info = symbole->view.get_info(&symbole->view);
	symbole->bind = ELF_ST_BIND(info);
	symbole->type = ELF_ST_TYPE(info);
	symbole->name = ft_get_section_str(bin, ".strtab", symbole->view.get_name(&symbole->view));
	ndx = symbole->view.get_shndx(&symbole->view);
	shdr = ft_get_section_header_byndx(bin, ndx);

	if (shdr)
	{
		symbole->shdr_name = ft_get_section_name_byndx(bin, ndx);
		symbole->shdr = *shdr;
		ft_pdeb(
			"sym [%s]{.type %d, bind %d, hdr {name %s, type %d, flags %d}}\n",
			symbole->name, symbole->type, symbole->bind, symbole->shdr_name,
			symbole->shdr.get_type(&symbole->shdr), symbole->shdr.get_flags(&symbole->shdr)
		);
	}
	else
	{
		symbole->shdr_name = FT_NULL;
		ft_pdeb(
			"sym [%s]{.type %d, bind %d, hdr {name %s, type NULL, flags NULL}}\n",
			symbole->name, symbole->type, symbole->bind, symbole->shdr_name
		);
	}

	if (ft_strncmp(symbole->name, "", 1) == 0 && symbole->shdr_name)
		symbole->name = symbole->shdr_name;

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
		ft_make_sym(bin->file_ptr + index, &bin->syms[counter].view);
		ft_read_sym(bin, &bin->syms[counter]);
		ft_check_sym(&bin->syms[counter].view);
		counter++;
		index += sym_entsize;
		if ((padding = index % sym_align))
			index += sym_align - padding;
	}
	return (SUCCESS);
}

t_elf_error	ft_read_syms(t_elfbin *bin)
{
	sym_hdr = ft_get_section_header_byname(bin, ".symtab");
	if (sym_hdr == FT_NULL)
		return (NOT_FOUND_SYMTAB);
	sym_offset = sym_hdr->get_offset(sym_hdr);
	sym_entsize = sym_hdr->get_entsize(sym_hdr);
	sym_align = sym_hdr->get_align(sym_hdr);
	bin->sym_nb = sym_hdr->get_size(sym_hdr) / sym_entsize;
	bin->sym_nb--;
	ft_pdeb("sym_nb %d\n", bin->sym_nb - 1);
	bin->syms = (t_sym *)ft_calloc(sizeof(t_sym), bin->sym_nb + 1);
	return (ft_read_syms_loop(bin));
}
