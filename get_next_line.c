/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehell <ehell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:57:34 by ehell             #+#    #+#             */
/*   Updated: 2019/10/07 18:52:53 by ehell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	char		*buff;
	size_t		n;
	t_list		list;

	if (ft_memalloc(buff))
	{
		n = 0;
		if (fd > 0)
		{
			while (read(fd, buff, BUFF_SIZE) > 0)
			{
				ft_strchr(buff, '\n');
			}
		}
	}
	return (-1);
}
	/*
	char	*buff;
	int		i;
	t_list	list;

	list.next = NULL;
	if (ft_memalloc(buff))
	{
		i = 0;
		if (fd > 0)
		{
			while (read(fd, &buff[i], 1) > 0 && i < BUFF_SIZE)
				if (buff[i] != '\n')
					i++;
				else
					break ;
			if (buff[i] != '\n')
			{
				if (!(ft_lst_add(&list, buff)))
				{
					ft_lstdell(list);
					return (-1);
				}
				ft_bzero(buff, BUFF_SIZE);
				//go to the while again
			}
			else if (buff[i] == '\n')
			{
				buff[i] = '\0';
				if (!(ft_lst_add(&list, buff)))
				{
					ft_lstdell(list);
					return (-1);
				}
				line = ft_concat_list(&list);//should I allocate memory???
				ft_lstdell(list);
				return (1);
			}
			else
			{
				if (!(ft_lst_add(&list, buff)))
				{
					ft_lstdell(list);
					return (-1);
				}
				line = ft_concat_list(&list);//should I allocate memory???
				ft_lstdell(list);
				return (0);
			}
		}
	}
	return (-1);
}
*/