/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int4_comp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 02:40:50 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/14 05:55:47 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_integer.h"

t_int4	ft_int4_comp(t_int1 n1, t_int1 n2, t_int1 n3, t_int1 n4)
{
	t_int4	result;

	result = n1;
	result += n2 << 8;
	result += n3 << 16;
	result += n4 << 24;
	return (result);
}
