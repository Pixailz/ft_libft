/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:25:32 by stales            #+#    #+#             */
/*   Updated: 2022/07/05 03:34:49 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

/**
 * @brief			Constructs a string representation of an integer, given a
 *					base.
 *
 * @param const_nb	Integer to convert
 * @param base		String base to convert from
 *
 * @return (char *)	The converted value or FT_NULL on error
 */
char	*ft_ltoa_base(const t_int64 const_nb, const char *base)
{
	t_int64	nb;
	t_size	nb_size;
	t_size	base_len;
	char	*nb_str;

	nb = (t_int64)const_nb;
	nb_size = ft_nbrlen_base((void *)nb, base);
	nb_str = ft_calloc(1, nb_size + 1);
	base_len = ft_strlen((char *)base);
	if (!nb_str)
		return (FT_NULL);
	if (nb < 0)
	{
		nb = ~(nb - 1);
		nb_str[0] = '-';
	}
	if (nb == 0)
		nb_str[0] = base[0];
	while (nb)
	{
		nb_str[nb_size - 1] = base[nb % base_len];
		nb /= base_len;
		nb_size--;
	}
	return (nb_str);
}
