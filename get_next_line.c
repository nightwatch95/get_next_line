/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:12:46 by vjacks            #+#    #+#             */
/*   Updated: 2018/12/21 16:13:32 by vjacks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	init_buffers(char **buffers)
{
	int	i;

	i = -1;
	while (++i < FD_LIMIT)
		buffers[i] = NULL;
}

static int	read_line(char **buf, int fd, char **line)
{
	char *chunk;
	char *sub;
	char *prev;

	while ((*buf)[0] != '\0')
	{
		sub = ft_strchr(*buf, '\n');
		if (sub)
		{
			CHECK_ERROR((chunk = ft_strnew(sub - *buf)));
			ft_strncpy(chunk, *buf, sub - *buf);
			prev = *line;
			CHECK_ERROR((*line = ft_strjoin(prev, chunk)));			
			ft_memdel((void **)&chunk);
			ft_memdel((void **)&prev);
			ft_strcpy(*buf, sub + 1);
			return (1);
		}
		prev = *line;
		CHECK_ERROR((*line = ft_strjoin(prev, *buf)));
		ft_memdel((void **)&prev);
		(*buf)[read(fd, *buf, BUFF_SIZE)] = '\0';
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char **buffers;
	char		byte[1];

	CHECK_ERROR(line && BUFF_SIZE > 0 && fd >= 0 &&
		fd < FD_LIMIT && read(fd, byte, 0) >= 0);
	if (!buffers)
	{
		CHECK_ERROR((buffers = (char**)malloc(sizeof(char*) * FD_LIMIT)));
		init_buffers(buffers);
	}	
	if (!buffers[fd])
		buffers[fd] = ft_strnew(BUFF_SIZE);
	if (buffers[fd][0] == '\0')
		buffers[fd][read(fd, buffers[fd], BUFF_SIZE)] = '\0';
	if (buffers[fd][0] == '\0')
	{
		ft_memdel((void **)&buffers[fd]);
		return (0);
	}
	CHECK_ERROR((*line = ft_strnew(0)));
	CHECK_ERROR(read_line(&buffers[fd], fd, line));
	return (1);
}

// #include <fcntl.h>

// int	main(int argc, char **argv)
// {
// 	char *line = NULL;
// 	CHECK_ERROR(argc > 1);
// 	int	fd1 = open(argv[1], O_RDONLY);
// 	int fd2 = open(argv[2], O_RDONLY);
// 	int	ret = 0;

// 	for (int i = 1; i <= 9; i++)
// 	{
// 		int fd = i % 2 == 0 ? fd1 : fd2;

// 		ret = get_next_line(fd, &line);
// 		printf("ret: %d, fd: %d, line: %s\n",  ret, fd, line);
// 		ft_memdel((void **)&line);
// 	}
// 	return (0);
// }
