/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_char_pp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 05:38:46 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/14 05:41:41 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

void	ft_free_char_pp(char **str_str)
{
	t_size	counter;

	counter = 0;
	while (str_str[counter])
	{
		free(str_str[counter]);
		str_str[counter] = FT_NULL;
		counter++;
	}
	free(str_str);
	str_str = FT_NULL;
}
