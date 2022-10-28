/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:29:59 by dsoroko           #+#    #+#             */
/*   Updated: 2022/10/28 17:51:50 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_path(t_vars **vars)
{
	char	**temp;
	int		x;
	int		y;

	x = 0;
	y = 0;
	(*vars)->c_check = 0;
	(*vars)->e_check = 0;
	temp = ft_dup_map(vars);
	while (temp[y] && temp[y][x] != 'P')
	{
		x = 0;
		y++;
		while (temp[y][x] && temp[y][x] != 'P')
			x++;
	}
	ft_grid(temp, x, y, vars);
	if ((*vars)->c_check != (*vars)->c || (*vars)->e_check != (*vars)->e)
	{
		ft_putendl_fd("No Valid Path", 1);
		exit(1);
	}
	ft_free_dup(temp);
	return ;
}

char	**ft_dup_map(t_vars **vars)
{
	char	**res;
	char	*temp;
	int		y;

	y = 0;
	while ((*vars)->map[y])
	{
		y++;
	}
	res = ft_calloc(y + 1, sizeof(char *));
	y = 0;
	while ((*vars)->map[y])
	{
		temp = ft_strdup((*vars)->map[y]);
		res[y] = temp;
		y++;
	}
	return (res);
}

void	ft_free_dup(char **dup)
{
	int	x;

	x = 0;
	while (dup[x])
	{
		free(dup[x]);
		x++;
	}
	free(dup);
	return ;
}

void	ft_grid(char **grid, int i, int j, t_vars **vars)
{
	int	x;
	int	y;

	if (grid[j][i] == 'C')
		(*vars)->c_check ++;
	if (grid[j][i] == 'E')
		(*vars)->e_check = 1;
	x = (*vars)->win_w;
	y = (*vars)->win_h;
	if (i < 0 || i >= x || j < 0 || j >= y || grid[j][i] == '1'
			|| grid[j][i] == 'X' || grid[j][i] == 'E')
		return ;
	grid[j][i] = 'X';
	ft_grid(grid, i, j + 1, vars);
	ft_grid(grid, i, j - 1, vars);
	ft_grid(grid, i + 1, j, vars);
	ft_grid(grid, i - 1, j, vars);
	return ;
}
