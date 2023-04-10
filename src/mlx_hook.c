/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:57:15 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/10 17:34:59 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"



# define RIGHT 65363
# define LEFT 65361
# define DOWN 65364
# define UP 65362

int key_handle(int keycode, t_vars *vars)
{
	if (keycode == RIGHT)
		rotate_vector(vars, &vars->player.vec, -1);
	else if (keycode == LEFT)
		rotate_vector(vars, &vars->player.vec, 1);
	else if (keycode == UP)
	{
		double checkx = vars->player.pos_p.x + (vars->player.vec.dx) * 0.12;
		if (vars->vgame.smap[(int)vars->player.pos_p.y][(int)checkx] == '0')
			vars->player.pos_p.x = checkx;
		double checky = vars->player.pos_p.y + (vars->player.vec.dy) * 0.12;
		if (vars->vgame.smap[(int)checky][(int)vars->player.pos_p.x] == '0')
			vars->player.pos_p.y = checky;
	}
	else if (keycode == DOWN)
	{
		double checkx = vars->player.pos_p.x - (vars->player.vec.dx) * 0.12;
		if (vars->vgame.smap[(int)vars->player.pos_p.y][(int)checkx] == '0')
			vars->player.pos_p.x = checkx;
		double checky = vars->player.pos_p.y - (vars->player.vec.dy) * 0.12;
		if (vars->vgame.smap[(int)checky][(int)vars->player.pos_p.x] == '0')
			vars->player.pos_p.y = checky;
	}
	else
		return 0;
	mlx_clear_window(vars->mlx, vars->win);
	game_loop(vars);
	return 0;
	// // draw_wall(vars);
	// (void)vars;
	
}
void game_hooks(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L << 0, key_handle, vars);
	mlx_hook(vars->win, 17, 0, exit_game, vars);
	game_loop(vars);
	mlx_loop(vars->mlx);
}
