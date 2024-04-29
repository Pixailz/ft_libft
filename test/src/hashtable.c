/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 22:56:30 by brda-sil          #+#    #+#             */
/*   Updated: 2024/04/29 06:35:14 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_hashtable.h"
#include <stdio.h>

#ifndef CI_TEST
# define CI_TEST FALSE
#endif

t_bool	KEY_TABLE[HT_SIZE] = {0};

t_bin	test_hash_add_key(t_uint32 key)
{
	if (KEY_TABLE[key % HT_SIZE])
		return (TRUE);
	KEY_TABLE[key % HT_SIZE] = TRUE;
	return (FALSE);
}

void	test_hash(char *str)
{
	printf("k:");
	for (int i = 0; i < ft_strlen(str); i++)
		printf("%02x", (unsigned char)str[i]);

	t_uint32	key = ft_ht_hash_key(str);

	printf("|h:%u", key);

	if (test_hash_add_key(key))
		printf(": Collision detected\n");
	else
		printf(": GOOD\n");
}

int	get_len_hash_table(void)
{
	int counter = 0;

	for (unsigned long int i = 0; i < HT_SIZE; i++)
		if (KEY_TABLE[i])
			counter++;
	return (counter);
}

void	test_collision(void)
{
	t_size			size = 2;
	char	buff[size];

	buff[size - 1] = 0;

	for (int i = 0; i <= 0xff; i++)
	{	buff[0] = i;
		test_hash(buff);
	}
	printf("len %d\n", get_len_hash_table());
}

void ft_ht_enumerate(ht table)
{
	ht_item	*ptr;

	for (unsigned long int i = 0; i < HT_SIZE; i++)
	{
		ptr = table.item[i];

		while (ptr)
		{
			printf("[%03ld]  %-9s  %p\n", i, ptr->key, ptr->value);
			ptr = ptr->next;
		}
	}
}

ht	*test_table(void)
{
	ht		*table = ft_ht_new();
	char	buff[10];
	int		i;

	for (i = 0; i < 0xfff; i++)
	{
		ft_bzero(buff, 10);
		ft_strcat(buff, "test_");
		char *tmp = ft_itoa(i);
		ft_strcat(buff, tmp);
		free(tmp);
		// printf("%s -> %d\n", buff, ft_ht_hash_key(buff));
		ft_ht_set(table, buff, "value");
	}
	printf("len table %ld\n", ft_ht_len(*table));
	return (table);
}

int	ci_test(void)
{
	test_collision();

	ht	*test = test_table();

	ft_ht_enumerate(*test);
	printf("%s\n", ft_ht_get(test, "test_1"));
	ft_ht_free(test);
	return (0);
}

int	interactive(void)
{
	return (0);
}

int	main(void)
{
	if (CI_TEST)
		return (ci_test());
	else
		return (interactive());
	return (0);
}

