/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:13:49 by vjacks            #+#    #+#             */
/*   Updated: 2018/12/21 16:17:48 by vjacks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE	1
# define FD_LIMIT	4864
# define CHECK_ERROR(x) if (!(x)) return (-1);

# include "libft/libft.h"

int	get_next_line(const int fd, char **line);

#endif
