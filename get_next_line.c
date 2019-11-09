/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehell <ehell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:57:34 by ehell             #+#    #+#             */
/*   Updated: 2019/11/09 19:54:25 by ehell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_myjoin(char *s1, char *s2)
{
	char	*tmp;
	size_t	i;
	size_t	n;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (tmp)
	{
		while (s1[i] != '\0')
		{
			tmp[i] = s1[i];
			i++;
		}
		n = 0;
		while (s2[n] != '\0')
		{
			tmp[i] = s2[n];
			i++;
			n++;
		}
	}
	tmp[i] = '\0';
	free(s1);
	s1 = NULL;
	return (tmp);
}

char	*ft_mycpy(char *s2)
{
	char	*s1;
	size_t	i;

	i = 0;
	s1 = ft_strnew(ft_strlen(s2) + 1);
	if (s1)
	{
		while (s2[i] != '\n' && s2[i] != '\0')
		{
			s1[i] = s2[i];
			i++;
		}
		s1[i] = '\0';
	}
	return (s1);
}

char	*ft_strskip(char *s)
{
	char	*tmp1;
	char	*tmp2;
	size_t	i;

	i = 0;
	tmp1 = ft_strchr(s, '\n');
	tmp2 = NULL;
	if (tmp1)
	{
		tmp2 = (char *)malloc(sizeof(char) * (ft_strlen(tmp1) + 1));
		if (tmp2)
		{
			while (tmp1[i + 1] != '\0' && tmp1[i] != '\0')
			{
				tmp2[i] = tmp1[i + 1];
				i++;
			}
			tmp2[i] = '\0';
		}
	}
	free(s);
	s = NULL;
	tmp1 = NULL;
	return (tmp2);
}

t_file	*find_elem(t_file *file_mass, int fd)
{
	t_file	*tmp1;
	t_file	tmp2;

	tmp1 = file_mass;
	while (tmp1)
		if (tmp1->fd == fd)
			return (tmp1);
		else
			tmp1 = tmp1->next;
	tmp2.fd = fd;
	tmp2.cont = ft_strnew(1);
	tmp2.next = file_mass;
	file_mass = &tmp2;
	return (file_mass);
}

int		get_next_line(const int fd, char **line)
{
	static	t_file	*file_mass;
	t_file			*file;
	char			*buff;
	char			*tmp;
	int				r;

	if (fd < 0 || BUFF_SIZE <= 0 || !line ||
		!(buff = ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	file = find_elem(file_mass, fd);
	r = 1;
	while (!ft_strchr(buff, '\n') && !ft_strchr(file->cont, '\n')
		&& r != 0)
	{
		ft_bzero(buff, BUFF_SIZE + 1);
		ft_putnbr(ft_strlen(file->cont));
		ft_putchar('\n');
		if ((r = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		ft_putnbr(ft_strlen(file->cont));					////////!!!!!!!JFEO???????????????????????DTYJTYJTY
		if (!(file->cont = ft_myjoin(file->cont, buff)))
			return (-1);
		ft_putstr("here");
		if (r == 0 && !file->cont)
			return (0);
	}
	free(buff);
	buff = NULL;
	*line = ft_mycpy(file->cont);
	file->cont = ft_strskip(file->cont);
	return (1);
}
