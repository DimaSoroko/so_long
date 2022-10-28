/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:27:27 by dsoroko           #+#    #+#             */
/*   Updated: 2022/10/28 17:48:51 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_extension(char *file_line)
{
	while (*file_line)
	{
		if (*file_line == '.')
		{
			if (ft_strnstr(file_line, ".ber", ft_strlen(file_line)))
			{
				return ;
			}
		}
		file_line++;
	}
	ft_putendl_fd("Map Extension Error", 1);
	exit(1);
}

static char	*ft_err_message(t_vars *map)
{
	if (map->c == 0)
		return (
			"Element 'C' is missing");
	if (map->p == 0)
		return (
			"Element 'P' is missing");
	if (map->e == 0 || map->e > 1)
	{
		if (map->e > 1)
			return ("There is more then one element 'E'");
		return ("Element 'E' is missing");
	}
	if (map->p == 0 || map->p > 1)
	{
		if (map->p > 1)
			return ("There is more then one element 'P'");
		return ("Element 'P' is missing");
	}
	return ("Element missing in the map");
}

char	*ft_unknown_element(t_vars ***v)
{
	int	x;

	x = 0;
	while ((**v)->map[x])
	{
		free((**v)->map[x]);
		x++;
	}
	free((**v)->map);
	ft_putendl_fd("Unknown element", 1);
	exit(1);
}

void	ft_check_elements(t_vars **vars)
{
	(*vars)->c = 0;
	(*vars)->p = 0;
	(*vars)->e = 0;
	(*vars)->y = ft_get_height((*vars)->map) - 1;
	while ((*vars)->y--)
	{
		(*vars)->x = 0;
		while ((*vars)->map[(*vars)->y][(*vars)->x] != '\0')
		{
			if ((*vars)->map[(*vars)->y][(*vars)->x] == 'E')
					(*vars)->e++;
			else if ((*vars)->map[(*vars)->y][(*vars)->x] == 'P')
					(*vars)->p++;
			else if ((*vars)->map[(*vars)->y][(*vars)->x] == 'C')
					(*vars)->c++;
			else if ((*vars)->map[(*vars)->y][(*vars)->x] != '1' &&
					(*vars)->map[(*vars)->y][(*vars)->x] != '0')
				ft_unknown_element(&vars);
			(*vars)->x++;
		}
	}
	if ((*vars)->c == 0 || (*vars)->p == 0 || (*vars)->e == 0
		|| (*vars)->p > 1 || (*vars)->e > 1)
		ft_error(&vars, ft_err_message(*vars));
}
