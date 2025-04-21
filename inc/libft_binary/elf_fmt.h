/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf_fmt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 13:57:52 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ELF_FMT_H
# define FT_ELF_FMT_H

# define	ELF_STR_PAD						"   "
# define	ELF_STR_LIST					"- "
# define	ELF_STR_NLIST_SEP				". "
# define	ELF_FMT_NB						"%-8d (%#x)"


# define	ELF_STR_EHDR_IDENT				ELF_STR_PAD ELF_STR_LIST \
											"Identification header"
# define	ELF_STR_EHDR_IDENT_CLASS		ELF_STR_PAD ELF_STR_PAD ELF_STR_LIST \
											"Ident File Class     "
# define	ELF_STR_EHDR_IDENT_ENDIANESS	ELF_STR_PAD ELF_STR_PAD ELF_STR_LIST \
											"Ident Data Endianess "
# define	ELF_STR_EHDR_IDENT_VERSION		ELF_STR_PAD ELF_STR_PAD ELF_STR_LIST \
											"Ident File Version   "
# define	ELF_STR_EHDR_IDENT_ABI			ELF_STR_PAD ELF_STR_PAD ELF_STR_LIST \
											"Ident ABI            "
# define	ELF_STR_EHDR_IDENT_ABI_VERSION	ELF_STR_PAD ELF_STR_PAD ELF_STR_LIST \
											"Ident ABI (Version)  "
# define	ELF_STR_EHDR_IDENT_ABI_SPEC		ELF_STR_PAD ELF_STR_PAD ELF_STR_LIST \
											"Ident ABI (Spec)     "
# define	ELF_STR_EHDR_IDENT_PADDING		ELF_STR_PAD ELF_STR_PAD ELF_STR_LIST \
											"Ident Is good padding"

# define	ELF_STR_EHDR					"Elf header"
# define	ELF_STR_EHDR_TYPE				ELF_STR_PAD ELF_STR_LIST \
											"Type                    "
# define	ELF_STR_EHDR_MACHINE			ELF_STR_PAD ELF_STR_LIST \
											"Machine                 "
# define	ELF_STR_EHDR_VERSION			ELF_STR_PAD ELF_STR_LIST \
											"Version                 "
# define	ELF_STR_EHDR_ENTRY				ELF_STR_PAD ELF_STR_LIST \
											"Entry                   "
# define	ELF_STR_EHDR_PHOFF				ELF_STR_PAD ELF_STR_LIST \
											"Program header offset   "
# define	ELF_STR_EHDR_SHOFF				ELF_STR_PAD ELF_STR_LIST \
											"Section header offset   "
# define	ELF_STR_EHDR_FLAGS				ELF_STR_PAD ELF_STR_LIST \
											"Flags                   "
# define	ELF_STR_EHDR_SIZE				ELF_STR_PAD ELF_STR_LIST \
											"Header size             "
# define	ELF_STR_EHDR_PROG_HDR_SIZE		ELF_STR_PAD ELF_STR_LIST \
											"Program Headers size    "
# define	ELF_STR_EHDR_PROG_HDR_NUM		ELF_STR_PAD ELF_STR_LIST \
											"Program Headers num     "
# define	ELF_STR_EHDR_SECT_HDR_SIZE		ELF_STR_PAD ELF_STR_LIST \
											"Section Headers size    "
# define	ELF_STR_EHDR_SECT_HDR_NUM		ELF_STR_PAD ELF_STR_LIST \
											"Section Headers num     "
# define	ELF_STR_EHDR_SECT_TXT_INDEX		ELF_STR_PAD ELF_STR_LIST \
											"Section text index      "

# define	ELF_STR_SHDR					"Elf section headers"
# define	ELF_STR_SHDR_NAME				ELF_STR_PAD ELF_STR_PAD ELF_STR_LIST \
											"Name          "
# define	ELF_STR_SHDR_TYPE				ELF_STR_PAD ELF_STR_PAD ELF_STR_LIST \
											"Type          "
# define	ELF_STR_SHDR_FLAGS				ELF_STR_PAD ELF_STR_PAD ELF_STR_LIST \
											"Flags         "
# define	ELF_STR_SHDR_ADDR				ELF_STR_PAD ELF_STR_PAD ELF_STR_LIST \
											"Address       "
# define	ELF_STR_SHDR_OFFSET				ELF_STR_PAD ELF_STR_PAD ELF_STR_LIST \
											"Offset        "
# define	ELF_STR_SHDR_SIZE				ELF_STR_PAD ELF_STR_PAD ELF_STR_LIST \
											"Size          "
# define	ELF_STR_SHDR_LINK				ELF_STR_PAD ELF_STR_PAD ELF_STR_LIST \
											"Link          "
# define	ELF_STR_SHDR_INFO				ELF_STR_PAD ELF_STR_PAD ELF_STR_LIST \
											"Info          "
# define	ELF_STR_SHDR_ALIGN				ELF_STR_PAD ELF_STR_PAD ELF_STR_LIST \
											"Address Align "
# define	ELF_STR_SHDR_ENTSIZE			ELF_STR_PAD ELF_STR_PAD ELF_STR_LIST \
											"Entity Size   "

# define	ELF_STR_SYM						"Elf Symtable table"
# define	ELF_STR_SYM_NAME				ELF_STR_PAD ELF_STR_LIST \
											"Name                 "
# define	ELF_STR_SYM_SIZE				ELF_STR_PAD ELF_STR_LIST \
											"Size                 "
# define	ELF_STR_SYM_VALUE				ELF_STR_PAD ELF_STR_LIST \
											"Value                "
# define	ELF_STR_SYM_INFO				ELF_STR_PAD ELF_STR_LIST \
											"Info                 "
# define	ELF_STR_SYM_OTHER				ELF_STR_PAD ELF_STR_LIST \
											"Other                "
# define	ELF_STR_SYM_SHNDX				ELF_STR_PAD ELF_STR_LIST \
											"Section header index "


#endif // FT_ELF_FMT_H
