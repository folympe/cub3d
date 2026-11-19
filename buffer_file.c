#include "cub3d.h"

static int	open_file(t_cub *cub, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_out(cub, ERR_OPEN, file);
	return (fd);
}

static void	read_file(t_cub *cub, int fd, char *file)
{
	cub->parse.file = get_file(fd);
	close(fd);
	if (errno)
		error_out(cub, ERR_READ, file);
	if (!cub->parse.file)
		error_out(cub, ERR_EMPFILE, file);
}

void	buffer_file(t_cub *cub, char *file)
{
	int	fd;

	fd = open_file(cub, file);
	read_file(cub, fd, file);
}
