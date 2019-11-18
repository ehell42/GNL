/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehell <ehell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:42:03 by ehell             #+#    #+#             */
/*   Updated: 2019/11/11 17:30:16 by ehell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int main()
{

    char		*line = NULL;
	int			fd = open("/Users/ehell/42FileChecker/srcs/gnl/gnl10.txt", O_RDONLY);
	int				i = 0;

	while((get_next_line(fd, &line)) > 0)
	{
    ft_putstr(line);
	ft_putchar('\n');
	ft_putnbr(i);
	}
	close(fd);
    return (0);
}