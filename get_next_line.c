/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehell <ehell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:57:34 by ehell             #+#    #+#             */
/*   Updated: 2019/11/19 16:52:39 by ehell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_myjoin(t_file *s1, int fd)
{
	int		i;
	char    *meme;
    char    buff[BUFF_SIZE + 1];

    ft_bzero(buff, BUFF_SIZE + 1);
    while (((i = read(fd, buff, BUFF_SIZE)) > 0))
    {
        if(s1->cont == NULL)
            s1->cont = ft_strnew(1);
        meme = ft_strjoin(s1->cont, buff);
        free(s1->cont);
        s1->cont = meme;
        if (ft_strchr(s1->cont, '\n'))
            break ;
    }
    if (i < 0)
        return (-1);
	return (i);
}

int makeline(char **line, t_file *longm, int fd, int schitali)
{
    int i;
    char *mem;

    i = 0;
    while ((longm->cont)[i] != '\n' && (longm->cont)[i] != '\0')
        i++;
    if ((longm->cont)[i] == '\n')
    {
        *line = ft_strsub(longm->cont, 0, i);
        mem = ft_strdup((longm->cont) + i + 1);
        free(longm->cont);
        longm->cont = mem;
       if ((longm->cont)[0] == '\0')
           ft_strdel(&(longm->cont));
    }
    else
    {
        if (schitali == BUFF_SIZE)
            return (get_next_line(fd, line));
        *line = ft_strsub(longm->cont, 0, i);
        ft_strdel(&(longm->cont));
    }
    return (1);
}

t_file	*find_elem(t_file **file_mass, int fd)
{
    t_file	*tmp1;
	t_file	*tmp2;

	tmp1 = *file_mass;
	while (tmp1)
		if (tmp1->fd == fd)
			return (tmp1);
		else
			tmp1 = tmp1->next;
    if (!(tmp2 = (t_file *)ft_memalloc(sizeof(t_file))))
        return (NULL);
	tmp2->fd = fd;
	tmp2->cont = NULL;
	tmp2->next = *file_mass;
	*file_mass = tmp2;
	return (*file_mass);
}

int		get_next_line(const int fd, char **line) {
    static t_file *file_mass;
    t_file *file;
    int r;

    if (fd < 0 || BUFF_SIZE <= 0 || !line)
        return (-1);
    file = find_elem(&file_mass, fd);
    if ((r = ft_myjoin(file, fd)) < 0)
        return (-1);
    if (r == 0 && file->cont == NULL)
        return (0);
    return (makeline(line, file, fd, r));
}
