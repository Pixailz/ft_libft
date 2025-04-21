/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 14:26:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

# define ELF_SHDR_NB_TYPE	31

extern t_uint8	NM_CLASS;

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

// #define SHT_LOPROC	  0x70000000	/* Start of processor-specific */
// #define SHT_HIPROC	  0x7fffffff	/* End of processor-specific */
// #define SHT_LOUSER	  0x80000000	/* Start of application-specific */
// #define SHT_HIUSER	  0x8fffffff	/* End of application-specific */

t_sh_type	ft_get_s_hdr_type(t_elf_shdr *s_hdr)
{
	t_sh_type	type;

	if (ft_is_good_s_hdr(s_hdr))
		return (0);
	if (NM_CLASS == ELFCLASS64)
		type = s_hdr->_64->sh_type;
	else if (NM_CLASS == ELFCLASS32)
		type = (t_sh_type)s_hdr->_32->sh_type;
	return (type);
}

t_elf_error	ft_check_s_hdr_type(t_elf_shdr *s_hdr)
{
	t_sh_type	type;
	int			counter;

	type = ft_get_s_hdr_type(s_hdr);
	counter = 0;
	while(counter < ELF_SHDR_NB_TYPE)
	{
		if (type == (t_uint32)SHDR_TYPE[counter].id)
		{
			ft_pdeb(ELF_STR_SHDR_TYPE SEP "%s\n", SHDR_TYPE[counter].str);
			return (SUCCESS);
		}
		counter++;
	}
	if (type >= SHT_LOPROC && type <= SHT_HIPROC)
	{
		ft_pdeb(ELF_STR_EHDR_TYPE SEP "Processor-specific\n");
		return (SUCCESS);
	}
	if (type >= SHT_LOUSER)
	{
		ft_pdeb(ELF_STR_EHDR_TYPE SEP "Application-specific\n");
		return (SUCCESS);
	}
	ft_pdeb(ELF_STR_SHDR_TYPE SEP "Unknown\n");
	return (SUCCESS);
}
