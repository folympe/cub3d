/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olfhal <olfhal@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:07:56 by olfhal            #+#    #+#             */
/*   Updated: 2026/04/22 18:08:00 by olfhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*get_map(int fd)
{
	char	*a;
	char	*b;
	int		n;
	char	*t;

	a = ft_strdup("");
	b = ft_strdup("");
	n = gnl(fd, &a);
	while (n > 0)
	{
		t = b;
		b = ft_strjoin(b, a);
		free(t);
		free(a);
		a = ft_strdup("");
		n = gnl(fd, &a);
	}
	if (!b || n < 0)
		return (ft_error("Error\nWrong lecture map\n"), NULL);
	return (b);
}

void	*ft_free_map(t_data *d)
{
	int	i;

	i = -1;
	while (d->map[++i])
		free(d->map[i]);
	free(d->map);
	d->map = NULL;
	return (0);
}

static int	check_map_body(t_data *d, int *height)
{
	int	i;

	i = 0;
	while (d->map[++i])
	{
		if (!ft_check_col(d->map[i], d->content.wall, d))
			return (0);
		if (!ft_check_other(d->map[i], &d->content))
			return (0);
	}
	*height = i;
	if (!ft_check_line(d->map[i - 1], d->content.wall))
		return (0);
	if (!ft_check_player_exit_blocked(d))
		return (0);
	return (1);
}

char	**parse_map(int fd, t_data *d)
{
	char	*tmp;

	tmp = get_map(fd);
	if (!tmp)
		return (NULL);
	if (!check_double_newline(tmp))
		return (free(tmp), ft_error("Error\nempty line\n"), NULL);
	d->map = ft_split(tmp, '\n');
	if (!d->map)
		return (free(tmp), NULL);
	free(tmp);
	ft_check_content(d);
	if (!ft_check_format(d->map)
		|| !ft_check_line(d->map[0], d->content.wall))
		return (ft_free_map(d));
	if (!check_map_body(d, &d->height))
		return (ft_free_map(d));
	return (d->map);
}

char	**map_core(char **av, t_data *d)
{
	int	fd;

	fd = -1;
	d->map = NULL;
	if (!ft_strchr(av[1], ".ber"))
		return (ft_error("Error\nNo correct format map founded\n"), NULL);
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		return (ft_error("Error\nFailed to open file\n"), NULL);
	d->map = parse_map(fd, d);
	if (d->map && (d->content.count_c == 0
			|| d->content.count_e != 1
			|| d->content.count_p != 1))
	{
		ft_free_map(d);
		return (ft_error("Error\nNeed 1 Player/Exit, 1 Object\n"), NULL);
	}
	return (d->map);
}
