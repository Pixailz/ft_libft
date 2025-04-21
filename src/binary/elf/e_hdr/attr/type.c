/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 14:14:43 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

# define ELF_NB_EHDR_TYPE	5

# define ELF_LOOS	0xFE00
# define ELF_HIOS	0xFEFF
# define ELF_LOPROC	0xFF00
# define ELF_HIPROC	0xFFFF

extern t_uint8	NM_CLASS;

t_id_str EHDR_FILE_TYPE[ELF_NB_EHDR_TYPE] = {
	{ET_NONE,	"No file type"},
	{ET_REL,	"Relocatable file"},
	{ET_EXEC,	"Executable file"},
	{ET_DYN,	"Shared object file"},
	{ET_CORE,	"Core file"},
};

t_eh_type	ft_get_e_hdr_type(t_elf_ehdr *e_hdr)
{
	t_eh_type	type;

	if (ft_is_good_e_hdr(e_hdr))
		return (0);
	if (NM_CLASS == ELFCLASS64)
		type = e_hdr->_64->e_type;
	else if (NM_CLASS == ELFCLASS32)
		type = e_hdr->_32->e_type;
	return (type);
}

t_elf_error	ft_check_e_hdr_type(t_elf_ehdr *e_hdr)
{
	int			counter;
	t_eh_type	type;

	counter = 0;
	type = ft_get_e_hdr_type(e_hdr);
	while(counter < ELF_NB_EHDR_TYPE)
	{
		if (type == EHDR_FILE_TYPE[counter].id)
		{
			ft_pdeb(ELF_STR_EHDR_TYPE SEP "%s\n", EHDR_FILE_TYPE[counter].str);
			return (SUCCESS);
		}
		counter++;
	}
	if (type >= ELF_LOOS && type <= ELF_HIOS)
	{
		ft_pdeb(ELF_STR_EHDR_TYPE SEP "OS-specific\n");
		return (SUCCESS);
	}
	if (type >= ELF_LOPROC)
	{
		ft_pdeb(ELF_STR_EHDR_TYPE SEP "Processor-specific\n");
		return (SUCCESS);
	}
	ft_pdeb(ELF_STR_EHDR_TYPE SEP "Unknown\n");
	return (ERR_HDR_TYPE);
}
