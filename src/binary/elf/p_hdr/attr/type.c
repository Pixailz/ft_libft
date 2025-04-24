/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/24 23:14:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

# define ELF_NB_PHDR_TYPE	22

t_id_str PHDR_FILE_TYPE[ELF_NB_PHDR_TYPE] = {
	{PT_NULL,			"Program header table entry unused"},
	{PT_LOAD,			"Loadable program segment"},
	{PT_DYNAMIC,		"Dynamic linking information"},
	{PT_INTERP,			"Program interpreter"},
	{PT_NOTE,			"Auxiliary information"},
	{PT_SHLIB,			"Reserved"},
	{PT_PHDR,			"Entry for header table itself"},
	{PT_TLS,			"Thread-local storage segment"},
	{PT_NUM,			"Number of defined types"},
	{PT_LOOS,			"Start of OS-specific"},
	{PT_GNU_EH_FRAME,	"GCC .eh_frame_hdr segment"},
	{PT_GNU_STACK,		"Indicates stack executability"},
	{PT_GNU_RELRO,		"Read-only after relocation"},
	{PT_GNU_PROPERTY,	"GNU property"},
	{PT_GNU_SFRAME,		"SFrame segment."},
	{PT_LOSUNW,			"No description"},
	{PT_SUNWBSS,		"Sun Specific segment"},
	{PT_SUNWSTACK,		"Stack segment"},
	{PT_HISUNW,			"No description"},
	{PT_HIOS,			"End of OS-specific"},
	{PT_LOPROC,			"Start of processor-specific"},
	{PT_HIPROC,			"End of processor-specific"},
};

t_ph_type	ft_p_hdr_get_type_32(t_p_hdr_view *p_hdr)
{
	return (t_ph_type)p_hdr->raw._32->p_type;
}

t_ph_type	ft_p_hdr_get_type_64(t_p_hdr_view *p_hdr)
{
	return (t_ph_type)p_hdr->raw._64->p_type;
}

void	ft_p_hdr_set_type_32(t_p_hdr_view *p_hdr, t_ph_type value)
{
	p_hdr->raw._32->p_type = value;
}

void	ft_p_hdr_set_type_64(t_p_hdr_view *p_hdr, t_ph_type value)
{
	p_hdr->raw._64->p_type = value;
}

t_elf_error	ft_check_p_hdr_type(t_ph_type value)
{
	int	counter;

	counter = 0;
	while(counter < ELF_NB_PHDR_TYPE)
	{
		if (value == (t_ph_type)PHDR_FILE_TYPE[counter].id)
		{
			ft_pdeb(ELF_STR_PHDR_TYPE SEP "%s\n", PHDR_FILE_TYPE[counter].str);
			return (SUCCESS);
		}
		counter++;
	}
	ft_pdeb(ELF_STR_PHDR_TYPE SEP "Unknown\n");
	return (ERR_HDR_TYPE);
}
