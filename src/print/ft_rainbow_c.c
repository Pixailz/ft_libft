/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rainbow_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 00:24:30 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/24 00:26:41 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

# define LEN_RAINBOW_C	7

char	*RAINBOW_C(int i)
{
	switch (i % LEN_RAINBOW_C)
	{
		case (0):
			return (PUR);
		case (1):
			return (BLU);
		case (2):
			return (CYA);
		case (3):
			return (GRE);
		case (4):
			return (YEL);
		case (5):
			return (ORA);
		case (6):
			return (RED);
	}
	return "";
}
