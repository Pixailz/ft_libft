/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int4_dcomp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 02:40:50 by brda-sil          #+#    #+#             */
/*   Updated: 2022/11/07 03:01:05 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_integer.h"

t_int1	ft_int4_dcomp(t_int4 n, int level)
{
	t_int1	result;

	result = n >> (level * 8);
	return (result);
}
