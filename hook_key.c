#include "cub3d.h"

int	key_up_hook(int keycode, t_cub *cub)
{
	switch (keycode)
	{
		case KEY_W:
			cub->key.w = 0;
			break ;
		case KEY_A:
			cub->key.a = 0;
			break ;
		case KEY_S:
			cub->key.s = 0;
			break ;
		case KEY_D:
			cub->key.d = 0;
			break ;
		case KEY_LEFT:
			cub->key.left = 0;
			break ;
		case KEY_RIGHT:
			cub->key.right = 0;
			break ;
	}
	return (0);
}

int	key_down_hook(int keycode, t_cub *cub)
{
	switch (keycode)
	{
		case KEY_ESC:
			exit_prog(cub, 0);
			break ;
		case KEY_W:
			cub->key.w = 1;
			break ;
		case KEY_A:
			cub->key.a = 1;
			break ;
		case KEY_S:
			cub->key.s = 1;
			break ;
		case KEY_D:
			cub->key.d = 1;
			break ;
		case KEY_LEFT:
			cub->key.left = 1;
			break ;
		case KEY_RIGHT:
			cub->key.right = 1;
			break ;
	}
	return (0);
}

int	clientmsg_hook(t_cub *cub)
{
	exit_prog(cub, 0);
	return (0);
}

int	pointer_motion_hook(int x, int y, t_cub *cub)
{
	(void)y;
	if (x != 0)
		cub->plr += (PL_SPD_ROT * x) / MOUSE_SENS;
	mlx_mouse_move(cub->mlx.ptr, cub->mlx.win, 0, 0);
	return (0);
}
