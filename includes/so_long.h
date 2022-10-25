/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:29:39 by dsoroko           #+#    #+#             */
/*   Updated: 2022/10/25 11:19:13 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_enemy {
	int		x_e;
	int		y_e;
	int		sign;
	int		x;
	int		path_to_move;
	int		sleep;
	int		sleep_for_move;
	char	*imgs[5];
}	t_enemy_vars;

typedef struct s_vars {
	void			*mlx;
	void			*img;
	void			*win;
	int				win_w;
	int				win_h;
	int				x_p;
	int				y_p;
	int				movement;
	char			**map;
	int				collect;
	t_enemy_vars	e_vars;
}	t_vars;

typedef struct s_vars_map {
	int	c;
	int	p;
	int	e;
	int	x;
	int	y;
}	t_map_vars;

char	**ft_get_map(char *fmap);
void	to_left(t_vars **v);
void	to_right(t_vars **v);
void	to_up(t_vars **v);
void	to_down(t_vars **v);
void	ft_put_image(t_vars ***v, int x, int y, char *img);
void	ft_put_text(t_vars ***v);
void	ft_put_image_to_map(char p, int x1, int y1, t_vars **v);
int		ft_get_height(char **map);
void	ft_check_map_valid(t_vars *vars);
void	ft_check_extension(char *file_line);
void	ft_check_elements(t_vars **vars);
void	ft_error(t_vars ***v, char *err);
int		ft_animation(t_vars *vars);
int		ft_enemy_position(t_vars **vars);
void	ft_open_exit(t_vars **vars);
void	ft_exit_door(t_vars ***v);

#endif
