/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:14:10 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

# define ELF_SHDR_NB_TYPE	31

t_id_str SHDR_TYPE[ELF_SHDR_NB_TYPE] = {
	{SHT_NULL,			"Section header table entry unused"},
	{SHT_PROGBITS,		"Program data"},
	{SHT_SYMTAB,		"Symbol table"},
	{SHT_STRTAB,		"String table"},
	{SHT_RELA,			"Relocation entries with addends"},
	{SHT_HASH,			"Symbol hash table"},
	{SHT_DYNAMIC,		"Dynamic linking information"},
	{SHT_NOTE,			"Notes"},
	{SHT_NOBITS,		"Program space with no data (bss)"},
	{SHT_REL,			"Relocation entries, no addends"},
	{SHT_SHLIB,			"Reserved"},
	{SHT_DYNSYM,		"Dynamic linker symbol table"},
	{SHT_INIT_ARRAY,	"Array of constructors"},
	{SHT_FINI_ARRAY,	"Array of destructors"},
	{SHT_PREINIT_ARRAY,	"Array of pre-constructors"},
	{SHT_GROUP,			"Section group"},
	{SHT_SYMTAB_SHNDX,	"Extended section indices"},
	{SHT_RELR,			"RELR relative relocations"},
	{SHT_NUM,			"Number of defined types"},
	{SHT_LOOS,			"Start OS-specific"},
	{SHT_GNU_ATTRIBUTES,"Object attributes"},
	{SHT_GNU_HASH,		"GNU-style hash table"},
	{SHT_GNU_LIBLIST,	"Prelink library list"},
	{SHT_CHECKSUM,		"Checksum for DSO content"},
	{SHT_LOSUNW,		"Sun-specific low bound"},
	{SHT_SUNW_move,		"Sun-specific move"},
	{SHT_SUNW_COMDAT,	"Sun-specific COMDAT"},
	{SHT_SUNW_syminfo,	"Sun-specific syminfo"},
	{SHT_GNU_verdef,	"Version definition section"},
	{SHT_GNU_verneed,	"Version needs section"},
	{SHT_GNU_versym | SHT_HISUNW | SHT_HIOS,	"Version symbol table / Sun-specific high bound / End OS-specific type"},
};

t_sh_type	ft_s_hdr_get_type_32(t_s_hdr_view *s_hdr)
{
	return (t_sh_type)s_hdr->raw._32->sh_type;
}

t_sh_type	ft_s_hdr_get_type_64(t_s_hdr_view *s_hdr)
{
	return (t_sh_type)s_hdr->raw._64->sh_type;
}

void	ft_s_hdr_set_type_32(t_s_hdr_view *s_hdr, t_sh_type value)
{
	s_hdr->raw._32->sh_type = value;
}

void	ft_s_hdr_set_type_64(t_s_hdr_view *s_hdr, t_sh_type value)
{
	s_hdr->raw._64->sh_type = value;
}

void	ft_check_s_hdr_type(t_sh_type value)
{
	int			counter;

	counter = 0;
	while(counter < ELF_SHDR_NB_TYPE)
	{
		if (value == (t_uint32)SHDR_TYPE[counter].id)
		{
			ft_pdeb(ELF_STR_SHDR_TYPE SEP "%s\n", SHDR_TYPE[counter].str);
			return ;
		}
		counter++;
	}
	if (value >= SHT_LOPROC && value <= SHT_HIPROC)
	{
		ft_pdeb(ELF_STR_EHDR_TYPE SEP "Processor-specific\n");
		return ;
	}
	if (value >= SHT_LOUSER)
	{
		ft_pdeb(ELF_STR_EHDR_TYPE SEP "Application-specific\n");
		return ;
	}
	ft_pdeb(ELF_STR_SHDR_TYPE SEP "Unknown\n");
	return ;
}
