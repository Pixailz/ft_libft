/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:13:32 by stales            #+#    #+#             */
/*   Updated: 2022/06/30 21:46:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include <stdlib.h>

/**
 * @brief			Delete a string
 *
 * @param dest		String to delete
 *
 * @return (void)	None.
 */
void	ft_strdel(char **as)
{
	if (!as)
		return ;
	free(*as);
	*as = NULL;
}
