/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putip_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 03:36:06 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/24 00:39:25 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

t_size	ft_putip_fd(t_int4 n, int fd)
{
	t_size	printed;

	printed = ft_putunbr_fd(ft_int4_dcomp(n, 3), fd);
	printed = ft_putchar_fd('.', fd);
	printed = ft_putunbr_fd(ft_int4_dcomp(n, 2), fd);
	printed = ft_putchar_fd('.', fd);
	printed = ft_putunbr_fd(ft_int4_dcomp(n, 1), fd);
	printed = ft_putchar_fd('.', fd);
	printed = ft_putunbr_fd(ft_int4_dcomp(n, 0), fd);
	return (printed);
}

// static	set_part()

char	*ft_getip_str(t_int4 n)
{
	char	*ptr;
	char	*tmp_n;
	t_size	index;
	t_size	len_tmp_n;

	ptr = (char *)ft_calloc(15, sizeof(char));

	tmp_n = ft_itoa(ft_int4_dcomp(n, 3));
	len_tmp_n = ft_strlen(tmp_n);
	ft_memcpy(ptr, tmp_n, len_tmp_n);
	free(tmp_n);
	index = len_tmp_n;
	ptr[index++] = '.';

	tmp_n = ft_itoa(ft_int4_dcomp(n, 2));
	len_tmp_n = ft_strlen(tmp_n);
	ft_memcpy(ptr + index, tmp_n, len_tmp_n);
	free(tmp_n);
	index += len_tmp_n;
	ptr[index++] = '.';

	tmp_n = ft_itoa(ft_int4_dcomp(n, 1));
	len_tmp_n = ft_strlen(tmp_n);
	ft_memcpy(ptr + index, tmp_n, len_tmp_n);
	free(tmp_n);
	index += len_tmp_n;
	ptr[index++] = '.';

	tmp_n = ft_itoa(ft_int4_dcomp(n, 0));
	len_tmp_n = ft_strlen(tmp_n);
	ft_memcpy(ptr + index, tmp_n, len_tmp_n);
	free(tmp_n);
	index += len_tmp_n;

	return ptr;
}
