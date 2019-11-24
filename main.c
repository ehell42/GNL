/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehell <ehell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:42:03 by ehell             #+#    #+#             */
/*   Updated: 2019/11/19 16:52:43 by ehell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

/*
** 4 lines with 16 chars with Line Feed
*/

int				main(void)
{
    char		*line;
    int			fd;
    int			ret;
    int			count_lines;
    char		*filename;
    int			errors;

    filename = "../test.txt";
    fd = open(filename, O_RDONLY);
    if (fd > 2)
    {
        count_lines = 0;
        errors = 0;
        line = NULL;
        while ((ret = get_next_line(fd, &line)) > 0)
        {
            if (count_lines == 0 && strcmp(line, "1234567") != 0)
                errors++;
            if (count_lines == 1 && strcmp(line, "abcdefgh") != 0)
                errors++;
            count_lines++;
            if (count_lines > 50)
                break ;
        }
        close(fd);
        if (count_lines != 2)
            printf("-> must have returned '1' twice instead of %d time(s)\n", count_lines);
        if (errors > 0)
            printf("-> must have read \"1234567\" and \"abcdefgh\"\n");
        if (count_lines == 2 && errors == 0)
            printf("OK\n");
    }
    else
        printf("An error occured while opening file %s\n", filename);
    return (0);
}