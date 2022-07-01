/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 09:12:28 by brda-sil          #+#    #+#             */
/*   Updated: 2022/07/01 12:35:21 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"
#include "libft_integer.h"
#include <limits.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	printf("ft_atoi: %d\n", ft_atoi(argv[1]));
	printf("ft_atol: %ld\n", ft_atol(argv[1]));
	printf("ft_itoa: %s\n", ft_itoa(ft_atoi(argv[1])));
	printf("ft_ltoa: %s\n", ft_ltoa(ft_atol(argv[1])));
	printf("ft_nbrlen: %d\n", ft_nbrlen((void *)ft_atol(argv[1])));
	printf("ft_nbrlen_base: %d\n", ft_nbrlen_base((void *)ft_atol(argv[1]), "0123456789abcdef"));
	return (0);
}

// #include <stdlib.h>
// #include <stdio.h>

// // proto

// long long	ft_atol(char *n_ptr);
// int			ft_intlen(const void *void_nbr);
// int 		ft_strlen(const char *str);
// int			ft_intlen_base(const void *void_nbr, const char *base);
// char		*ft_ltoa(const long long nbr);

// // utils

// long long	ft_atol(char *n_ptr)
// {
// 	long long	to_dec;
// 	long long	neg;

// 	to_dec = 0;
// 	neg = 1;
// 	if (*n_ptr == '-' || *n_ptr == '+')
// 	{
// 		if (*n_ptr == '-')
// 			neg = ~(neg - 1);
// 		n_ptr++;
// 	}
// 	while (*n_ptr >= '0' && *n_ptr <= '9')
// 		to_dec = (to_dec * 10) + (*n_ptr++ - '0');
// 	return (to_dec * neg);
// }

// int	ft_intlen(const void *void_nbr)
// {
// 	long long	nbr;
// 	int			len;

// 	nbr = (long long)void_nbr;
// 	len = 0;
// 	if (nbr < 0)
// 		len++;
// 	while (nbr)
// 	{
// 		nbr /= 10;
// 		len++;
// 	}
// 	return (len);
// }

// int	ft_intlen_base(const void *void_nbr, const char *base)
// {
// 	long long	nbr;
// 	int			len;
// 	int			base_len;

// 	nbr = (long long)void_nbr;
// 	base_len = ft_strlen(base);
// 	len = 0;
// 	if (nbr < 0)
// 		len++;
// 	while (nbr)
// 	{
// 		nbr /= base_len;
// 		len++;
// 	}
// 	return (len);
// }

// char	*ft_ltoa(const long long nbr)
// {
// 	char		*ptr;
// 	long long	ptr_nbr;
// 	int			index;

// 	index = ft_intlen((const void *)nbr);
// 	ptr = (char *)malloc(sizeof(char) * index + 1);
// 	if (!ptr)
// 		return (NULL);
// 	ptr[index] = 0;
// 	ptr_nbr = (long long)nbr;
// 	if (ptr_nbr == 0)
// 		ptr[0] = '0';
// 	if (ptr_nbr < 0)
// 	{
// 		ptr[0] = '-';
// 		ptr_nbr = ~(ptr_nbr - 1);
// 	}
// 	while (ptr_nbr)
// 	{
// 		ptr[--index] = '0' + (ptr_nbr % 10);
// 		ptr_nbr /= 10;
// 	}
// 	return (ptr);
// }

// char	*ft_ltoa_base(const long long nbr, const char *base)
// {
// 	char		*ptr;
// 	long long	ptr_nbr;
// 	int			index;
// 	int			base_len;

// 	index = ft_intlen_base((const void *)nbr, base);
// 	ptr = (char *)malloc(sizeof(char) * index + 1);
// 	if (!ptr)
// 		return (NULL);
// 	ptr[index] = 0;
// 	ptr_nbr = (long long)nbr;
// 	base_len = ft_strlen(base);
// 	if (ptr_nbr == 0)
// 		ptr[0] = '0';
// 	if (ptr_nbr < 0)
// 	{
// 		ptr[0] = '-';
// 		ptr_nbr = ~(ptr_nbr - 1);
// 	}
// 	while (ptr_nbr)
// 	{
// 		ptr[--index] = base[(ptr_nbr % base_len)];
// 		ptr_nbr /= base_len;
// 	}
// 	return (ptr);
// }

// int ft_strlen(const char *str)
// {
// 	char	*tmp;

// 	tmp = (char *)str;
// 	while (*tmp)
// 		tmp++;
// 	return (tmp - str);
// }
// //

// int main (int argc, char **argv)
// {
// 	if (argc != 3)
// 		return (1);
// 	printf("ltoa_base: %s\n", ft_ltoa_base(ft_atol(argv[1]), argv[2]));
// 	// printf("%s -> %lld -> %s\n", argv[1], ft_atol (argv[1]), ft_ltoa(ft_atol(argv[1])));
// 	return (0);
// }
