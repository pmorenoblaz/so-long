/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:41:49 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/04/25 20:36:05 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53 || keycode == 49)
	{	
		mlx_clear_window(data->mlx, data->mlx_win);
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	if (keycode == 2)
	{
		if ((data->player.x + 1) < (data->cont->x - 1))
		{
			write(1, "puedes mover\n", 13);
			data->player.x += 1;
		}
		else
			write(1, "te has salido\n", 14);
		// d_movement()
	}
	if (keycode == 0)
	{
		if ((data->player.x - 1) > 1)
		{
			write(1, "puedes mover\n", 13);
			data->player.x -= 1;
		}
		else
			write(1, "te has salido\n", 14);
		// d_movement()
	}
	if (keycode == 13)
	{
		if ((data->player.y - 1) > 0)
		{
			write(1, "puedes mover\n", 13);
			data->player.y -= 1;
		}
		else
			write(1, "te has salido\n", 14);
		// d_movement()
	}
	if (keycode == 1)
	{
		if ((data->player.y + 1) < (data->cont->y - 1))
		{
			write(1, "puedes mover\n", 13);
			write(1, "puedes mover\n", 13);
			write(1, "puedes mover\n", 13);
			data->player.y += 1;
		}
		else
			write(1, "te has salido\n", 14);
		// d_movement()
	}
	return (0);
}
