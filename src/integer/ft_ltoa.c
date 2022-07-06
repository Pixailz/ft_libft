/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:24:34 by stales            #+#    #+#             */
/*   Updated: 2022/07/01 12:22:59 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

/**
 * @brief			Constructs a string representation of a long long.
 *
 * @param const_nb	t_int64 to convert
 *
 * @return (char *)	The converted value or FT_NULL on error
 */
char	*ft_ltoa(const t_int64 const_nb)
{
	t_int64	nb;
	t_int64	nb_size;
	char	*nb_str;

	nb = (t_int64)const_nb;
	nb_size = ft_nbrlen((void *)nb);
	nb_str = ft_calloc(1, nb_size + 1);
	if (!nb_str)
		return (FT_NULL);
	if (nb < 0)
	{
		nb = ~(nb - 1);
		nb_str[0] = '-';
	}
	if (nb == 0)
		nb_str[0] = '0';
	while (nb)
	{
		nb_str[nb_size - 1] = '0' + (nb % 10);
		nb /= 10;
		nb_size--;
	}
	return (nb_str);
}
