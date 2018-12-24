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


#include <stdio.h>
#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	int			ret;
	static char *buf;
	char		*sub;
	char		*s;
	char		b[0];

	if (fd < 0 || !line || BUFF_SIZE < 1 || fd >= FD_LIMIT ||
		read(fd, b, 0) < 0)
		return (-1);

	if (!buf)
		CHECK_ERROR((buf = ft_strnew(BUFF_SIZE)));

	if (!(*line))
		CHECK_ERROR((*line = ft_strnew(0)));

	if (buf[0] == '\0')
		ret = read(fd, buf, BUFF_SIZE);
	if (buf[0] == '\0')
	{
		free(buf);
		return (0);
	}
	while (buf[0] != '\0')
	{
		sub = ft_strchr(buf, '\n');
		if (sub)
		{
			s = ft_strnew(sub - buf);
			s = ft_strncpy(s, buf, sub - buf);
			*line = ft_strjoin(*line, s);
			ft_strcpy(buf, sub + 1);
			return (1);
		}
		s = ft_strdup(buf);
		*line = ft_strjoin(*line, s);
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
	}
	return (1);
}



	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		temp2 = temp;
		CHECK_ERROR((temp = ft_strjoin(temp, buf)));
		free(temp2);
		if (ft_strchr(buf, '\n'))
			break;
	}
	free(buf);
	if (!ret && !temp)
		return (0);
	temp2 = ft_strchr(temp, '\n');
	if (temp2)
	{
		CHECK_ERROR((*line = ft_strnew(temp2 - temp)));
		ft_strncpy(*line, temp, temp2 - temp);
		char *temp3 = temp;
		CHECK_ERROR((temp = ft_strdup(temp2 + 1)));
		
		free(temp3);
	}
	else
	{
		CHECK_ERROR((*line = ft_strnew(ft_strlen(temp))));
		ft_strcpy(*line, temp);
		ft_memdel((void **)&temp);
	}
	return (1);
}


#include <fcntl.h>

int	main(int argc, char **argv)
{
	int fd;
	char *line;
	(void)argc;
	int	ret;
	int i;

	fd = open(argv[1], O_RDONLY);
/*
	// int ret = 0;
	while (get_next_line(fd, &line))
	{
		printf("line: %s\n",  line);
		free(line);
	}
*/
	i = 0;
	while (i < 4)
	{
	ret = get_next_line(fd, &line);
	printf("%d line: %d\t|%p|\n",  i, ret, line);
//	free(line);
	i++;
}
/*	ret = get_next_line(fd, &line);
	printf("line: %d\t|%p|\n",  ret, line);
	free(line);
	ret = get_next_line(fd, &line);
	printf("line: %d\t|%p|\n",  ret, line);

	ret = get_next_line(fd, &line);
	printf("line: %d\t|%p|\n",  ret, line);
*/
	return (0);
}
