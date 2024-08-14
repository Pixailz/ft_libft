#include "libft_network.h"
#include <arpa/inet.h> //for inet_pton()
#include <netdb.h> // for NI_MAXHOST, getnameinfo() and gai_strerror()
#ifndef CI_TEST
# define CI_TEST FALSE
#endif

int	test_i4toh(t_int4 ip)
{
	char	*name;

	name = ft_i4toh(ip);
	ft_putip_fd(ip, 1);
	ft_putstr_fd(" -> ", 1);
	if (!name)
	{
		ft_putstr_fd("error\n", 1);
		return (1);
	}
	ft_printf("%s\n", name);
	return (0);
}

int	ci_test(void)
{
	int	ret;

	ret = 0;
	for (int i = 0; i < 1; i++)
	{
		// google.com
		ret += test_i4toh(0xd83ad6ae);
		// wwww.google.com
		ret += test_i4toh(0xacd914c4);
		// archlinux.org
		ret += test_i4toh(0x5fd9a3f6);
		// ret += test_i4toh(0x4d9aed79);
		// ret += test_i4toh(0xd5f50030);
		// ret += test_i4toh(0xc0b251f9);
		// ret += test_i4toh(0xc0b26915);
	}
	// ret += test_i4toh(0xc0a80001); // not working for local ip
	// ret += test_i4toh(0xc0a8000c);
	return (ret);
}

int	interactive(void)
{
	ft_perr("parsing", 2);
	return (0);
}

int	main(void)
{
	if (CI_TEST)
		ci_test();
	else
		interactive();
	return (0);
}
