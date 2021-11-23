/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:11:34 by esafar            #+#    #+#             */
/*   Updated: 2021/11/17 09:53:04 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./mlx/mlx.h"

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

# define BUFFER_SIZE 1

# define ERROR -1
# define SUCCESS 1

typedef struct s_data
{
    void *img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
    int x;
    int y;
}               t_data;

typedef struct s_param
{
	char **map;
	int width;
	int width_with_x;
	int height;
    int height_with_wall;
}				t_param;

typedef struct s_all
{
    t_data wall;
    t_data floor;
    t_data floor_half_right;
    t_data floor_half_left;
    t_data box;
}               t_all;

typedef struct s_test
{
    void *mlx;
    void *win;
	t_param param;
    t_data data;
    t_all all;
}               t_test;

char	*get_line(char *save);
int    get_map(t_test *test, int ac, char **av);

//Init
void	initialize(t_test *test);

//Utils
int	get_pixel(t_data *img, int x, int y);
void	my_mlx_pixel_put(t_test *test, int x, int y, int color);

//Exit
void	clean_exit(t_test *test);

#endif
