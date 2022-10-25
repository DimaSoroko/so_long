/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:27:31 by dsoroko           #+#    #+#             */
/*   Updated: 2022/10/25 11:11:48 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error(t_vars ***v, char *err)
{
	int	x;

	x = 0;
	while ((**v)->map[x])
	{
		free((**v)->map[x]);
		x++;
	}
	free((**v)->map);
	ft_putendl_fd(err, 1);
	exit(1);
}

static void	ft_check_is_rectangular(t_vars **vars)
{
	int	y_map;
	int	x_map;
	int	height;
	int	backup;

	y_map = 0;
	backup = 0;
	height = ft_get_height((*vars)->map);
	while (y_map != height)
	{
		x_map = 0;
		while ((*vars)->map[y_map][x_map] != '\0')
			x_map++;
		y_map++;
		if (backup != 0)
		{
			if (backup != x_map)
				ft_error(&vars, "Map is not rectangular");
		}
		else
			backup = x_map;
	}
}

static int	ft_check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static void	ft_check_surrounded_by_walls(t_vars **v)
{
	int		i;
	char	*err;

	err = "Map is not surrounded by walls";
	if (ft_check_line((*v)->map[0]))
		ft_error(&v, err);
	i = ft_get_height((*v)->map) - 1;
	while (i)
	{
		if ((*v)->map[i][0] != '1' ||
			(*v)->map[i][ft_strlen((*v)->map[i]) - 1] != '1')
		{
			ft_error(&v, err);
		}
		i--;
	}
	if (ft_check_line((*v)->map[ft_get_height((*v)->map) - 1]))
		ft_error(&v, err);
}

void	ft_check_map_valid(t_vars *vars)
{
	ft_check_is_rectangular(&vars);
	ft_check_surrounded_by_walls(&vars);
	ft_check_elements(&vars);
}
