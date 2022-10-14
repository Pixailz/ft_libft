/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tmpfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 01:58:47 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/14 05:55:16 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_random.h"

char	*ft_tmpfile(int in_tmp)
{
	char	*name;
	int		tmp_set_len;
	int		tmp_len;
	int		counter;

	counter = 0;
	tmp_len = 15;
	if (in_tmp)
		tmp_len += 5;
	name = (char *)ft_calloc(sizeof(char), tmp_len);
	if (in_tmp)
	{
		ft_strncpy(name, "/tmp/", 5);
		counter += 5;
	}
	ft_strncpy(&name[counter], "tmp.", 4);
	counter += 4;
	tmp_set_len = ft_strlen(TMP_ST) - 1;
	while (counter < tmp_len - 1)
		name[counter++] = TMP_ST[ft_randint(0, tmp_set_len)];
	return (name);
}
