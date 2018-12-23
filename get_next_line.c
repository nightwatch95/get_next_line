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

int	get_next_line(const int fd, char **line)
{
	int			ret;
	char		*buf;
	static char *temp;
	char 		*temp2;
	int			len;

	if (fd < 0 || !line || BUFF_SIZE < 1 || fd > FD_LIMIT)
		return (-1);
	buf = (char*)malloc(BUFF_SIZE + 1);
	if (!temp)
		temp = (char*)malloc(BUFF_SIZE + 1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		//printf("%s\n", temp);

		temp2 = temp;
		temp = ft_strjoin(temp, buf);
		//free(temp2);

		if (ft_strchr(buf, '\n'))
		{
			ret = 1;
			break;
		}
	}
	temp2 = ft_strchr(temp, '\n');
	*line = (char*)malloc(temp2 - temp);
	*line = ft_strncpy(*line, temp, temp2 - temp);
	temp = temp2 + 1;

	//ft_strsub(temp, 0, ft_strchr(buf, '\n'))

	printf("%s",temp);
	//line = temp;
	return (ret > 1 ? 1 : ret);
}


int	main(int argc, char **argv)
{
	int fd;
	char *line;

	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);

	printf("line: %s\n",  line);

		get_next_line(fd, &line);

	printf("line: %s",  line);
		get_next_line(fd, &line);

	printf("line: %s",  line);

	return (0);
}