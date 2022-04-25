/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:55:00 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/04/25 19:57:06 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <errno.h>
# include "libft.h"
# include "gnl/get_next_line.h"
# include <mlx.h>

typedef struct s_board {
	int		col;
	int		row;
	char	type;
	int		is_border;
	int		jug;
    int		coll;
    int		end;
}	t_board;

typedef struct s_cont {
	int	jug;
    int	coll;
    int	end;
	int	x;
	int	y;
}	t_cont;

typedef struct s_player {
	int	x;
	int	y;
}	t_player;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*field;
	void	*dino;
	void	*food;
	void	*obs;
	void	*border;
	void	*end;
	int		px;
	t_board	**board;
	t_cont	*cont;
	t_player	player;	
} t_data;

// read_file.c
void	free_if_error(int fd, t_list **aux);
// t_list	*ft_read_map(char *file, int cont[2]);
t_list	*ft_read_map(char *file, int cont[2]);

// leaks.c
void	leaks();

// free_variables.c
void	free_variables(t_list **list);
void	free_variables_board(t_board **list, int fil);

// matrix.c
void ft_initialize_pos(t_board *elem);
t_board	ft_add_line_to_lit_list(char c, int fil, int col);
t_board	**ft_final_matrix(t_list **list, int cont[2]);

// check_matrix.c
void	check_map(t_board **board, int cont[2]);

// check_matrix_cont.c
void	check_player(t_cont *cont);
void	check_end(t_cont *cont);
void	check_collectionables(t_cont *cont);
void	check_counters(t_cont *cont);
t_cont	*sum_cont(t_board **board, int cont[2]);

// check_matrix_values.c
void	check_map_values(t_board **board, int x, int y);
void	check_map_border(t_board **board, int x, int y);

// exit_game.c
int		key_hook(int keycode, t_data *data);

// utils.c
void	print_list(t_list **list);
void	print_matrix(t_board **matrix, int x, int y);

#endif
