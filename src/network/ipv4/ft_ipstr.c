/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ipstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 05:54:46 by brda-sil          #+#    #+#             */
/*   Updated: 2022/11/09 03:10:52 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

int	ft_ip_check_part(char *splitted)
{
	int	tmp;
	int	has_overflow;

	tmp = ft_patoi(splitted, &has_overflow);
	if (has_overflow)
		return (-1);
	if (tmp < 0 || tmp > 0xff)
		return (-1);
	return (tmp);
}

char	**ft_ip_check(char *str)
{
	char	**splitted;
	t_size	counter;

	if (ft_get_words(str, '.') != 4)
		return (FT_NULL);
	splitted = ft_split(str, '.');
	counter = 0;
	while (counter < 4)
	{
		if (!ft_is_str(splitted[counter], ft_isdigit))
			return (FT_NULL);
		counter++;
	}
	return (splitted);
}

t_int4	ft_ipstr(char *str)
{
	t_size	counter;
	t_int4	ip;
	int		tmp_part_ip;
	char	**splitted;

	splitted = ft_ip_check(str);
	if (!splitted)
		return (0);
	ip = ft_int4_comp(0, 0, 0, 0);
	counter = 0;
	while (counter < 4)
	{
		tmp_part_ip = ft_ip_check_part(splitted[counter]);
		if (tmp_part_ip == -1)
			return (0);
		ft_int4_chg(&ip, 3 - counter, tmp_part_ip);
		counter++;
	}
	ft_free_char_pp(splitted);
	return (ip);
}
