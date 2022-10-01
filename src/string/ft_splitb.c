/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 00:03:22 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/01 18:19:01 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

int	ft_splitb_get_word(char **str, char delim, char *encl)
{
	int		have_encl;
	char	tmp_delim;
	char	*str_ptr;

	while (**str && **str == delim)
		(*str)++;
	str_ptr = *str;
	have_encl = ft_strcchr(encl, **str);
	if (have_encl)
	{
		tmp_delim = **str;
		str_ptr++;
		while (*str_ptr && *str_ptr != tmp_delim)
			str_ptr++;
		str_ptr++;
	}
	else
		while (*str_ptr && *str_ptr != delim && !ft_strcchr(encl, *str_ptr))
			str_ptr++;
	return (str_ptr - *str);
}

int	ft_splitb_get_size(char *str, char delim, char *encl)
{
	int		count;
	int		have_encl;
	char	tmp_delim;

	count = 0;
	while (*str)
	{
		while (*str && *str == delim)
			str++;
		if (*str && *str != delim)
			count++;
		have_encl = ft_strcchr(encl, *str);
		if (have_encl)
		{
			tmp_delim = *str;
			str++;
			while (*str && *str != tmp_delim)
				str++;
			str++;
		}
		else
			while (*str && *str != delim && !ft_strcchr(encl, *str))
				str++;
	}
	return (count);
}

char	**ft_splitb_get_words(char *s, char delim, char *encl, int tab_size)
{
	int		counter;
	int		size;
	char	*s_ptr;
	char	*s_ptr_ptr;
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * (tab_size + 1));
	size = 0;
	counter = 0;
	s_ptr = ft_strtrim(s, " ");
	s_ptr_ptr = s_ptr;
	while (counter < tab_size)
	{
		size = ft_splitb_get_word(&s_ptr, delim, encl);
		tab[counter] = (char *)malloc(sizeof(char) * (size + 1));
		ft_strncpy(tab[counter], s_ptr, size);
		tab[counter][size] = 0;
		s_ptr = s_ptr + size;
		counter++;
	}
	free(s_ptr_ptr);
	tab[tab_size] = FT_NULL;
	return (tab);
}

char	**ft_splitb(char *s, char delim, char *encl)
{
	char	**tab;
	int		tab_len;

	if (!s)
		return (FT_NULL);
	tab_len = ft_splitb_get_size(s, delim, encl);
	tab = ft_splitb_get_words(s, delim, encl, tab_len);
	return (tab);
}
