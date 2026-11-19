/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olfhal <olfhal@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:08:27 by olfhal            #+#    #+#             */
/*   Updated: 2026/04/22 18:08:29 by olfhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_col(char *map_line, char wall, t_data *data)
{
	int	len;

	len = 0;
	while (map_line[len] != '\0')
		len++;
	if (len < 2 || map_line[0] != wall)
	{
		ft_error("Error\nMap column not close\n");
		return (0);
	}
	if (map_line[len - 1] != wall)
	{
		ft_error("Error\nMap column not close\n");
		return (0);
	}
	data->width = len;
	return (1);
}

int	ft_check_line(char *map_line, char wall)
{
	int	i;

	i = -1;
	while (map_line[++i])
	{
		if (map_line[i] == wall)
			continue ;
		ft_error("Error\nMap line not close\n");
		return (0);
	}
	return (1);
}

int	ft_check_other(char *map_line, t_cnt *content)
{
	char	*ptr;

	ptr = map_line;
	while (*ptr)
	{
		if (content->count_e > 1 || content->count_p > 1)
		{
			ft_error("Error\nWrong number of player or exit\n");
			return (0);
		}
		if (*ptr == content->wall || *ptr == content->player
			|| *ptr == content->exit || *ptr == content->collect
			|| *ptr == content->space)
			ptr++;
		else
		{
			ft_error("Error\nUnknown symbol(s) in map\n");
			return (0);
		}
	}
	return (1);
}

void	ft_check_content(t_data *data)
{
	int		x;
	int		y;
	char	c;

	x = 0;
	while (data->map[x] != NULL)
	{
		y = 0;
		while (data->map[x][y] != '\0')
		{
			c = data->map[x][y];
			if (c == data->content.collect)
				data->content.count_c++;
			else if (c == data->content.player)
				data->content.count_p++;
			else if (c == data->content.exit)
				data->content.count_e++;
			y++;
		}
		x++;
	}
}

int	ft_check_format(char **map)
{
	int	y;
	int	x;
	int	count_x;

	y = 0;
	x = 0;
	count_x = 0;
	while (map[0][count_x] != '\0')
		count_x++;
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
			x++;
		if ((x ^ count_x) != 0)
		{
			ft_error("Error\nMap must be a rectangle or a square\n");
			return (0);
		}
		x = 0;
		y++;
	}
	return (1);
}
