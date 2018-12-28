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
#include <stdio.h>
#include <fcntl.h>


// int	get_next_line(const int fd, char **line)
// {
// 	static char *buf;
// 	char byte[1];
// 	char *chunk = NULL;
// 	char *sub = NULL;
// 	char *prev = NULL;

// 	CHECK_ERROR((line && BUFF_SIZE > 0 && fd >= 0 && fd < FD_LIMIT && read(fd, byte, 0) >= 0));
// 	if (!buf)
// 		CHECK_ERROR((buf = ft_strnew(BUFF_SIZE)));
// 	if (buf[0] == '\0')
// 		buf[read(fd, buf, BUFF_SIZE)] = '\0';
// 	if (buf[0] == '\0')
// 	{
// 		ft_memdel((void **)&buf);
// 		return (0);
// 	}
// 	CHECK_ERROR((*line = ft_strnew(0)));
	
// //	printf("BUF: |%s|\n", buf);
// 	while (buf[0] != '\0')
// 	{
// 		sub = ft_strchr(buf, '\n');
// 		if (sub)
// 		{
// 			CHECK_ERROR((chunk = ft_strnew(sub - buf)));
// 			ft_strncpy(chunk, buf, sub - buf);
// 			prev = *line;
// 			*line = ft_strjoin(prev, chunk);
// 			ft_memdel((void **)&chunk);
// 			CHECK_ERROR(*line);
// 			ft_memdel((void **)&prev);
// 			ft_strcpy(buf, sub + 1);
// //			printf("BUFF AFTER: |%s|\n", buf);
// 			return (1);
// 		}
// 		prev = *line;
// 		*line = ft_strjoin(prev, buf);
// 		CHECK_ERROR(*line);
// 		ft_memdel((void **)&prev);
// 		buf[read(fd, buf, BUFF_SIZE)] = '\0';
// //		printf("NEW BUF: |%s|\n", buf);
// 	}
// 	return (1);
// }

int	get_next_line(const int fd, char **line)
{
	static char **buffers;
	char byte[1];
	char *chunk = NULL;
	char *sub = NULL;
	char *prev = NULL;

	CHECK_ERROR((line && BUFF_SIZE > 0 && fd >= 0 && fd < FD_LIMIT && read(fd, byte, 0) >= 0));
	if (!buffers)
		CHECK_ERROR(buffers = (char **)malloc(sizeof(char *) * FD_LIMIT));
	if (!buffers[fd])
		buffers[fd] = ft_strnew(1);
	if (*(buffers[fd]) == '\0')
		buffers[fd][read(fd, buffers[fd], BUFF_SIZE)] = '\0';
	if (*(buffers[fd]) == '\0')
	{
		ft_memdel((void **)&*buffers);
		return (0);
	}
	CHECK_ERROR((*line = ft_strnew(0)));
	
//	printf("*buffers: |%s|\n", *buffers);
	while (*(buffers[fd]) != '\0')
	{
		sub = ft_strchr(buffers[fd], '\n');
		if (sub)
		{
			CHECK_ERROR((chunk = ft_strnew(sub - buffers[fd])));
			ft_strncpy(chunk, buffers[fd], sub - buffers[fd]);
			prev = *line;
			*line = ft_strjoin(prev, chunk);
			ft_memdel((void **)&chunk);
			CHECK_ERROR(*line);
			ft_memdel((void **)&prev);
			ft_strcpy(buffers[fd], sub + 1);
//			printf("*buffersF AFTER: |%s|\n", *buffers);
			return (1);
		}
		prev = *line;
		*line = ft_strjoin(prev, buffers[fd]);
		CHECK_ERROR(*line);
		ft_memdel((void **)&prev);
		buffers[fd][read(fd, buffers[fd], BUFF_SIZE)] = '\0';
//		printf("NEW *buffers: |%s|\n", *buffers);
	}
	return (1);
}

// int	main(int argc, char **argv)
// {
// 	char *line = NULL;
// 	CHECK_ERROR(argc > 1);
// 	int	fd = open(argv[1], O_RDONLY);
// 	CHECK_ERROR(fd > 0);
// 	int	ret = 0;
// 	while ((ret = get_next_line(fd, &line)))
// 	{
// 		if (ret == -1)
// 		{
// 			printf("get_next_line returned an error\n");
// 			return (-1);
// 		}
// 		printf("ret: %d line: %s\n",  ret, line);
// 		ft_memdel((void **)&line);
// 	}
// 	printf("ret: %d line: %s\n",  ret, line);
// 	// once again
// 	printf("ret %d line: %s\n", get_next_line(fd, &line), line);
// 	return (0);
// }
