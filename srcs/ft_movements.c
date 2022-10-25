/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:28:44 by dsoroko           #+#    #+#             */
/*   Updated: 2022/10/25 11:28:01 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_collected(t_vars ***v)
{
	int		img_w;
	int		img_h;

	(**v)->collect--;
	(**v)->map[((**v)->y_p / 50)][((**v)->x_p / 50)] = '0';
	(**v)->img = mlx_xpm_file_to_image(
			(**v)->mlx, "./img/floor.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(**v)->mlx, (**v)->win, (**v)->img, (**v)->x_p, (**v)->y_p);
}

void	to_left(t_vars **v)
{
	int		img_w;
	int		img_h;

	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx, "./img/floor.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx, (*v)->win, (*v)->img, (*v)->x_p, (*v)->y_p);
	if ((*v)->map[((*v)->y_p / 50)][((*v)->x_p / 50) - 1] == 'E')
	{
		if ((*v)->collect <= 0)
			ft_exit_door(&v);
	}
	else if ((*v)->map[((*v)->y_p / 50)][((*v)->x_p / 50) - 1] != '1')
	{
		(*v)->x_p -= 50;
		ft_put_text(&v);
	}
	if ((*v)->map[((*v)->y_p / 50)][((*v)->x_p / 50)] == 'C')
		ft_collected(&v);
	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx, "./img/left.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx, (*v)->win, (*v)->img, (*v)->x_p, (*v)->y_p);
}

void	to_right(t_vars **v)
{
	int		img_w;
	int		img_h;

	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx, "./img/floor.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx, (*v)->win, (*v)->img, (*v)->x_p, (*v)->y_p);
	if ((*v)->map[((*v)->y_p / 50)][((*v)->x_p / 50) + 1] == 'E')
	{
		if ((*v)->collect <= 0)
			ft_exit_door(&v);
	}
	else if ((*v)->map[((*v)->y_p / 50)][((*v)->x_p / 50) + 1] != '1')
	{
		(*v)->x_p += 50;
		ft_put_text(&v);
	}
	if ((*v)->map[((*v)->y_p / 50)][((*v)->x_p / 50)] == 'C')
		ft_collected(&v);
	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx, "./img/right.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx, (*v)->win, (*v)->img, (*v)->x_p, (*v)->y_p);
}

void	to_up(t_vars **v)
{
	int		img_w;
	int		img_h;

	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx, "./img/floor.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx, (*v)->win, (*v)->img, (*v)->x_p, (*v)->y_p);
	if ((*v)->map[((*v)->y_p / 50) - 1][((*v)->x_p / 50)] == 'E')
	{
		if ((*v)->collect <= 0)
			ft_exit_door(&v);
	}
	else if ((*v)->map[((*v)->y_p / 50) - 1][((*v)->x_p / 50)] != '1')
	{
		(*v)->y_p -= 50;
		ft_put_text(&v);
	}
	if ((*v)->map[((*v)->y_p / 50)][((*v)->x_p / 50)] == 'C')
		ft_collected(&v);
	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx, "./img/back.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx, (*v)->win, (*v)->img, (*v)->x_p, (*v)->y_p);
}

void	to_down(t_vars **v)
{
	int		img_w;
	int		img_h;

	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx, "./img/floor.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx, (*v)->win, (*v)->img, (*v)->x_p, (*v)->y_p);
	if ((*v)->map[((*v)->y_p / 50) + 1][((*v)->x_p / 50)] == 'E')
	{
		if ((*v)->collect <= 0)
			ft_exit_door(&v);
	}
	else if ((*v)->map[((*v)->y_p / 50) + 1][((*v)->x_p / 50)] != '1')
	{
		(*v)->y_p += 50;
		ft_put_text(&v);
	}
	if ((*v)->map[((*v)->y_p / 50)][((*v)->x_p / 50)] == 'C')
		ft_collected(&v);
	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx, "./img/front.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx, (*v)->win, (*v)->img, (*v)->x_p, (*v)->y_p);
}
