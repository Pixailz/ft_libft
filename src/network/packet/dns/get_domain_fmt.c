/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_domain_fmt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 00:15:56 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/26 01:21:19 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

void	ft_dns_get_domain_fmt_loop(
		char *ret,
		t_size len_splitted_dom,
		char **splitted_dom
	)
{
	t_size	counter;
	t_size	tmp_len;

	counter = 0;
	while (counter < len_splitted_dom)
	{
		tmp_len = ft_strlen(splitted_dom[counter]);
		*ret = (t_uint8)tmp_len;
		ret++;
		ft_memcpy(ret, splitted_dom[counter], tmp_len);
		ret += tmp_len;
		counter++;
	}
}

char	*ft_dns_get_domain_fmt(char *domain)
{
	char	**splitted_dom;
	char	*ret;
	t_size	len_dom;
	t_size	len_splitted_dom;

	len_splitted_dom = ft_get_words(domain, '.');
	len_dom = ft_strlen(domain);
	if (len_splitted_dom == 0 && len_dom == 0)
		return (FT_NULL);

	ret = (char *)ft_calloc(len_dom + 2, sizeof(char *));
	splitted_dom = ft_split(domain, '.');
	ft_dns_get_domain_fmt_loop(ret, len_splitted_dom, splitted_dom);
	ft_free_char_pp(splitted_dom);
	return (ret);
}
