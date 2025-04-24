/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:12:54 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

# define ELF_NB_EHDR_TYPE	5

# define ELF_LOOS	0xFE00
# define ELF_HIOS	0xFEFF
# define ELF_LOPROC	0xFF00
# define ELF_HIPROC	0xFFFF

t_id_str EHDR_FILE_TYPE[ELF_NB_EHDR_TYPE] = {
	{ET_NONE,	"No file type"},
	{ET_REL,	"Relocatable file"},
	{ET_EXEC,	"Executable file"},
	{ET_DYN,	"Shared object file"},
	{ET_CORE,	"Core file"},
};

t_eh_type	ft_e_hdr_get_type_32(t_e_hdr_view *e_hdr)
{
	return (t_eh_type)e_hdr->raw._32->e_type;
}

t_eh_type	ft_e_hdr_get_type_64(t_e_hdr_view *e_hdr)
{
	return (t_eh_type)e_hdr->raw._64->e_type;
}

void	ft_e_hdr_set_type_32(t_e_hdr_view *e_hdr, t_eh_type value)
{
	e_hdr->raw._32->e_type = value;
}

void	ft_e_hdr_set_type_64(t_e_hdr_view *e_hdr, t_eh_type value)
{
	e_hdr->raw._64->e_type = value;
}

t_elf_error	ft_check_e_hdr_type(t_eh_type value)
{
	int			counter;

	counter = 0;
	while(counter < ELF_NB_EHDR_TYPE)
	{
		if (value == EHDR_FILE_TYPE[counter].id)
		{
			ft_pdeb(ELF_STR_EHDR_TYPE SEP "%s\n", EHDR_FILE_TYPE[counter].str);
			return (SUCCESS);
		}
		counter++;
	}
	if (value >= ELF_LOOS && value <= ELF_HIOS)
	{
		ft_pdeb(ELF_STR_EHDR_TYPE SEP "OS-specific\n");
		return (SUCCESS);
	}
	if (value >= ELF_LOPROC)
	{
		ft_pdeb(ELF_STR_EHDR_TYPE SEP "Processor-specific\n");
		return (SUCCESS);
	}
	ft_pdeb(ELF_STR_EHDR_TYPE SEP "Unknown\n");
	return (ERR_HDR_TYPE);
}