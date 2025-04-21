/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:28:13 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 14:50:31 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_binary/elf.h"

t_elf_error ft_map_file(int fd, t_int32 size, char **ptr)
{
	*ptr = mmap(0, size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (*ptr == MAP_FAILED)
		return (ERR_TARGET_MAP);
	return (SUCCESS);
}

t_elf_error	ft_get_file_stat(int fd, struct stat *stat)
{
	if (fstat(fd, stat) < 0)
	{
		ft_perr("Failed getting file stat\n");
		return (ERR_TARGET_STAT);
	}
	return (SUCCESS);
}

t_elf_error	ft_open_elfbin(char *path, t_elfbin *bin)
{
	int		fd;
	t_elf_error	retv;

	bin->file_path = path;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_pdeb("Failed opening file: %s\n", path);
		ft_dprintf(2, "%s: '%s': No such file\n", PROG_NAME, path);
		return (ERR_TARGET_OPEN);
	}
	if ((retv = ft_get_file_stat(fd, &bin->stat)))
	{
		close(fd);
		return (retv);
	}
	CHECK_RET(retv, ft_map_file, fd, bin->stat.st_size, &bin->file_ptr);
	close(fd);
	ft_pdeb("File size: %d\n", bin->stat.st_size);
	return (retv);
}