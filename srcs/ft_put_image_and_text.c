/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image_and_text.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:28:51 by dsoroko           #+#    #+#             */
/*   Updated: 2022/10/25 12:20:35 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_put_image(t_vars ***v, int x, int y, char *img)
{
	int		img_w;
	int		img_h;

	(**v)->img = mlx_xpm_file_to_image((**v)->mlx, img, &img_w, &img_h);
	mlx_put_image_to_window((**v)->mlx, (**v)->win, (**v)->img, x, y);
}

void	ft_put_image_to_map(char p, int x1, int y1, t_vars **v)
{
	if (p == '1')
		ft_put_image(&v, x1, y1, "./img/wall.xpm");
	else if (p == 'C')
	{
		ft_put_image(&v, x1, y1, "./img/floor.xpm");
		ft_put_image(&v, x1, y1, "./img/collect.xpm");
		(*v)->collect++;
	}
	else if (p == 'E')
		ft_put_image(&v, x1, y1, "./img/exit.xpm");
	else if (p == 'P')
	{
		(*v)->y_p = y1;
		(*v)->x_p = x1;
		ft_put_image(&v, x1, y1, "./img/floor.xpm");
		ft_put_image(&v, x1, y1, "./img/front.xpm");
	}
	else
		ft_put_image(&v, x1, y1, "./img/floor.xpm");
}

void	ft_put_text(t_vars ***v)
{
	int		img_w;
	int		img_h;
	char	*text;
	char	*number;

	number = ft_itoa(++(**v)->movement);
	text = ft_strjoin("Moves: ", number);
	(**v)->img = mlx_xpm_file_to_image(
			(**v)->mlx, "./img/wall.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(**v)->mlx, (**v)->win, (**v)->img, 0, 0);
	mlx_put_image_to_window(
		(**v)->mlx, (**v)->win, (**v)->img, 50, 0);
	mlx_put_image_to_window(
		(**v)->mlx, (**v)->win, (**v)->img, 50 * 2, 0);
	mlx_string_put((**v)->mlx, (**v)->win, 5, 10, 0xfffffff, text);
	ft_putendl_fd(number, 1);
	free(text);
	free(number);
}
