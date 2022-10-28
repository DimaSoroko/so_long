/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:28:10 by dsoroko           #+#    #+#             */
/*   Updated: 2022/10/28 17:33:44 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_message_error(void)
{
	perror("ERROR");
	exit(1);
}

int	ft_get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

char	**ft_get_map(char *fmap)
{
	char	*line;
	char	*all_lines;
	int		i;
	int		fd;

	i = 0;
	line = "";
	all_lines = ft_strdup("");
	fd = open(fmap, O_RDONLY);
	if (fd < 0)
		ft_message_error();
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		all_lines = ft_strjoin(all_lines, line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
	if (all_lines[0] == '\0')
		ft_message_error();
	return (ft_split(all_lines, '\n'));
}

void	ft_exit_door(t_vars ***v)
{
	int	x;

	x = 0;
	while ((**v)->map[x])
	{
		free((**v)->map[x]);
		x++;
	}
	free((**v)->map);
	mlx_destroy_window((**v)->mlx, (**v)->win);
	exit(1);
}
