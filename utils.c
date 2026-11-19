/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olfhal <olfhal@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:11:14 by olfhal            #+#    #+#             */
/*   Updated: 2026/04/22 18:11:20 by olfhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_same_char(char *str)
{
	int		i;
	char	buff;

	i = 0;
	buff = '1';
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] != buff && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	*ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (0);
}

int	surrounded_by_wall(char **map, int x, int y, char wall)
{
	if (map[x + 1][y] == wall &&
		map[x - 1][y] == wall &&
		map[x][y + 1] == wall &&
		map[x][y - 1] == wall)
		return (1);
	return (0);
}

int	ft_check_player_exit_blocked(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == data->content.player ||
				data->map[x][y] == data->content.exit ||
				data->map[x][y] == data->content.collect)
			{
				if (surrounded_by_wall(data->map, x, y, data->content.wall))
				{
					ft_error("Error\nP, E or C blocked by walls\n");
					return (0);
				}
			}
			y++;
		}
		x++;
	}
	return (1);
}

int	check_double_newline(const char *s)
{
	int	i;

	if (!s || s[0] == '\n')
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
			return (0);
		i++;
	}
	return (1);
}
