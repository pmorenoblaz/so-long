/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:05:56 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/04/25 20:18:32 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_img(t_board **matrix, int row, int col, t_data  data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < col)
	{
		j = 0;
		while (j < row)
		{
			mlx_put_image_to_window(data.mlx, data.mlx_win, data.field,(matrix[i][j].col * data.px), (matrix[i][j].row * data.px));
			j++;
		}
	}
}
	
void	print_img2(t_board **matrix, int row, int col, t_data  data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < col)
	{
		j = 0;
		while (j < row)
		{
			if (matrix[i][j].type == '1')
			{
				if (i == 0 || j == 0 || i == col - 1 || j == row - 1)
					mlx_put_image_to_window(data.mlx, data.mlx_win, data.border,(matrix[i][j].col * data.px), (matrix[i][j].row * data.px));
				else
					mlx_put_image_to_window(data.mlx, data.mlx_win, data.obs,(matrix[i][j].col * data.px), (matrix[i][j].row * data.px));
			}
			if (matrix[i][j].type == 'P')
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.dino,(matrix[i][j].col * data.px), (matrix[i][j].row * data.px));
			if (matrix[i][j].type == 'C')
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.food,(matrix[i][j].col * data.px), (matrix[i][j].row * data.px));
			if (matrix[i][j].type == 'E')
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.end,(matrix[i][j].col * data.px), (matrix[i][j].row * data.px));
			j++;
		}
	}
}

void	set_images(t_data *data, int cont[2])
{
	data->px = 80;
	data->mlx = mlx_init();
	data->field =  mlx_xpm_file_to_image(data->mlx,"./img/field.xpm", &data->px, &data->px);
	data->dino =  mlx_xpm_file_to_image(data->mlx,"./img/1.xpm", &data->px, &data->px);
	data->food =  mlx_xpm_file_to_image(data->mlx,"./img/polloesc2.xpm", &data->px, &data->px);
	data->border = mlx_xpm_file_to_image(data->mlx,"./img/border.xpm", &data->px, &data->px);
	data->obs = mlx_xpm_file_to_image(data->mlx,"./img/obs2.xpm", &data->px, &data->px);
	data->end = mlx_xpm_file_to_image(data->mlx,"./img/cave.xpm", &data->px, &data->px);
	data->mlx_win = mlx_new_window(data->mlx, data->px * cont[1], data->px * cont[0], "so_long");
}

int	is_player(t_board **board, int i, int j)
{
	if (board[i][j].type == 'P')
		return (1);
	return (0);
}

t_player	where_is_the_player(t_board **board, int x, int y)
{
	int			i;
	int			j;
	t_player	player;

	player.x = -1;
	player.y = -1;
	i = -1;
	while (++i < x)
	{
		j = 0;
		while (j < y)
		{
			if (is_player(board, i, j))
			{
				player.x = i;
				player.y = j;
				break ;
			}	
			j++;
		}
	}
	return (player);
}


int	main(int argc, char **argv)
{
	t_data	data;
	t_list	*list;
	int		cont[2];

	atexit(leaks);
	list = 0;
	data.board = 0;
	data.cont = 0;
	cont[0] = 0;
	cont[1] = 0;
	if (argc != 2)
	{
		printf("Error en el número de argumentos\n");
		exit (0);
	}
	list = ft_read_map(argv[1], cont);
	// board2 = ft_final_matrix(&list, cont);
	// counters = sum_cont(board2, cont);
	// check_map(board2, cont);
	data.board = ft_final_matrix(&list, cont);
	// counters = sum_cont(data.board, cont);
	data.cont = sum_cont(data.board, cont);
	// printf("%d, %d", counters->x, counters->y);
	check_map(data.board, cont);
	// check_counters(counters);
	check_counters(data.cont);
	
	data.player = where_is_the_player(data.board, data.cont->y, data.cont->x);


	set_images(&data, cont);
	// print_img(board2, cont[1], cont[0], data);
	// print_img2(board2, cont[1], cont[0], data);
	print_img(data.board, cont[1], cont[0], data);
	print_img2(data.board, cont[1], cont[0], data);
	mlx_key_hook(data.mlx_win, &key_hook, &data);


	mlx_loop(data.mlx);
	free(data.mlx);
	free(data.mlx_win);
	
	free_variables(&list);
	free_variables_board(data.board, cont[0]);
	// free_variables_board(board2, cont[0]);
	return (0);
}
