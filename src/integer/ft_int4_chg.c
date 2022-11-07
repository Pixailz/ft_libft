/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int4_chg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 02:40:50 by brda-sil          #+#    #+#             */
/*   Updated: 2022/11/07 04:41:44 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_integer.h"

void	ft_int4_chg(t_int4 *n, int level, t_int1 change)
{
	t_int1	n1;
	t_int1	n2;
	t_int1	n3;
	t_int1	n4;

	n1 = ft_int4_dcomp(*n, 3);
	n2 = ft_int4_dcomp(*n, 2);
	n3 = ft_int4_dcomp(*n, 1);
	n4 = ft_int4_dcomp(*n, 0);
	if (!level)
		n4 = change;
	else if (level == 1)
		n3 = change;
	else if (level == 2)
		n2 = change;
	else if (level == 3)
		n1 = change;
	*n = ft_int4_comp(n1, n2, n3, n4);
}
