/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehell <ehell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:57:34 by ehell             #+#    #+#             */
/*   Updated: 2019/10/19 21:46:51 by ehell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_myjoin(char *s1, char *s2)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (tmp)
	{
		tmp = ft_strjoin(s1, s2);
		free(s1);
	}
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
	return (tmp2);
}

int		get_next_line(const int fd, char **line)
{
	static	char	*file_mass;
	char			*buff;
	int				r;

	if (fd < 0 || BUFF_SIZE < 0 || !line ||
		!(buff = ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	if (!file_mass)
		file_mass = ft_strnew(1);
	r = 1;
	while (!ft_strchr(buff, '\n') && !ft_strchr(file_mass, '\n') && r != 0)
	{
		ft_bzero(buff, BUFF_SIZE + 1);
		if ((r = read(fd, buff, BUFF_SIZE)) == -1)
		{
			free(buff);
			free(file_mass);
			return (-1);
		}
		else if (r == 0 && file_mass[0] == '\0')
			return (0);
		else
		{
			if (!(file_mass = ft_myjoin(file_mass, buff)))
			{
				free(file_mass);
				free(buff);
				return (-1);
			}
		}
	}
	free(buff);
	*line = ft_mycpy(file_mass);
	file_mass = ft_strskip(file_mass);
	return (1);
}
