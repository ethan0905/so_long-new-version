/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:32:28 by esafar            #+#    #+#             */
/*   Updated: 2021/11/23 16:32:30 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_on_image(t_test *test, t_data *img, int startx, int starty)
{
	int tex_x = 0;
	int tex_y = 0;
	int	x, y = 0;
	double ratio_x;
	double ratio_y;

	ratio_x = 1.0f;
	ratio_y = 1.0f;
	while (y < 64)
	{
		tex_y = (int)((double)y * ratio_y);
		x = 0;
		while (x < 64)
		{
			tex_x = (int)((double)x * ratio_x);
			if (get_pixel(img, tex_x, tex_y) != (int)0xFF000000)
				my_mlx_pixel_put(test, x + startx, y + starty, get_pixel(img, tex_x, tex_y));
			x++;
		}
		y++;
	}
}

void	draw_on_image_bis(t_test *test, t_data *img, int startx, int starty)
{
	int tex_x = 0;
	int tex_y = 0;
	int	x, y = 0;
	double ratio_x;
	double ratio_y;

	ratio_x = 1.0f;
	ratio_y = 1.0f;
	while (y < 128)
	{
		tex_y = (int)((double)y * ratio_y);
		x = 0;
		while (x < 128)
		{
			tex_x = (int)((double)x * ratio_x);
			if (get_pixel(img, tex_x, tex_y) != (int)0xFF000000)
				my_mlx_pixel_put(test, x + startx, y + starty, get_pixel(img, tex_x, tex_y));
			x++;
		}
		y++;
	}
}

void	draw_on_image_intro(t_test *test, t_data *img, int startx, int starty)
{
	int tex_x = 0;
	int tex_y = 0;
	int	x, y = 0;
	double ratio_x;
	double ratio_y;

	ratio_x = 1.0f;
	ratio_y = 1.0f;
	while (y < 448)
	{
		tex_y = (int)((double)y * ratio_y);
		x = 0;
		while (x < 960)
		{
			tex_x = (int)((double)x * ratio_x);
			// if (get_pixel(img, tex_x, tex_y) != (int)0xFF000000)
			my_mlx_pixel_put(test, x + startx, y + starty, get_pixel(img, tex_x, tex_y));
			x++;
		}
		y++;
	}
}

void draw_background(t_test *test)
{
    int y;
    int x;

    y = 0;
    x = 0;
    while (y < (test->param.height-2)*64+3*64)
    {
        x = 0;
        while (x < test->param.width_with_x*64-(2*64))
        {
            my_mlx_pixel_put(test, x, y, 0xFF000000);
            x++;
        }
        y++;
    }
}

void draw_walls(t_test *test)
{
    int y;
    int x;

    y = 0;
    while (y < 3)
    {
    	x = test->param.width_with_x - test->param.width-1;
        while (x < test->param.width_with_x - 2)
        {
    		draw_on_image(test, &test->all.wall, x * 64, y *64);
            x++;
        }
        y++;
    }
}

void draw_floors(t_test *test)
{
    int y;
    int x;
	int count;

    y = 0;
	count = 0;
    while (y < test->param.height - 2)
    {
    	x = test->param.width_with_x - test->param.width - count - 1 - 1;
        while (x < test->param.width_with_x - 2 - count)
        {
			if (x == test->param.width_with_x - test->param.width - count - 1 - 1)
    			draw_on_image(test, &test->all.floor_half_right, x * 64, 3*64 + y *64);
			else if (x == test->param.width_with_x - 2 - count - 1)
    			draw_on_image(test, &test->all.floor_half_left, x * 64, 3*64 + y *64);
			else
    			draw_on_image(test, &test->all.floor, x * 64, 3*64 + y *64);
            x++;
        }
		count++;
        y++;
    }
}

void	draw_flames(t_test *test, int x, int y)
{
	draw_on_image(test, test->all.fire.frame, x, y);
}

void draw_furnitures(t_test *test)
{
	int i;
	int j;
	int x;
	int y;
	int random_obj;
	int piano;
	// int iter;
	// t_data *ptr;
	// char frame[8] = {&test->all.fire.frame_one, &test->all.fire.frame_two, &test->all.fire.frame_three, &test->all.fire.frame_four, &test->all.fire.frame_five, &test->all.fire.frame_six, &test->all.fire.frame_seven, &test->all.fire.frame_eight, NULL};

	i = 1;
	piano = 0;
	random_obj = 0;
	// iter = 0;
	while (test->param.map[i + 1])
	{
		j = 1;
		while (test->param.map[i][j + 1])
		{
			x = (64 + (test->param.height - 2 - i)*64 + (j-1)*64);
			y = (192 + (i-1)*64);
			if (test->param.map[i][j] == '1' && i != 1)
				draw_on_image(test, &test->all.box, x, y);
			else if (test->param.map[i][j] == '1' && ((test->param.map[i][j - 1] == '0' || test->param.map[i][j - 1] == 'P') || (test->param.map[i][j - 1] == '1' && j - 1 == 0)) && ((test->param.map[i][j + 1] == '0' || test->param.map[i][j + 1] == 'P') || (test->param.map[i][j + 1] == '1' && j + 1 == test->param.width - 1)) && i == 1)
			{
				if (random_obj == 0)
				{
					draw_on_image(test, &test->all.pot, x, y - 32);
					if (test->all.babo == 0)
					{
						draw_on_image(test, &test->all.babolex_painting, x + 32, y-128);
						test->all.babo = 1;
					}
					random_obj = 1;
				}
			}
			else if (test->param.map[i][j] == '1' && test->param.map[i][j + 1] == '1' && j + 1 != test->param.width - 1 && ((test->param.map[i][j - 1] == '0' || test->param.map[i][j - 1] == 'P') || (test->param.map[i][j - 1] == '1' && j - 1 == 0)) && ((test->param.map[i][j + 2] == '0' || test->param.map[i][j + 2] == 'P') || (test->param.map[i][j + 2] == '1' && j + 2 == test->param.width - 1)))
			{
				if (random_obj == 0)
				{
					draw_on_image(test, &test->all.dresser_downleft, x, y - 24);
					draw_on_image(test, &test->all.dresser_downright, x + 64, y - 24);
					draw_on_image(test, &test->all.dresser_topleft, x, y - 64 - 24);
					draw_on_image(test, &test->all.dresser_topright, x + 64, y - 64 - 24);
					random_obj = 1;
				}
				else if (random_obj == 1)
				{
					draw_on_image(test, &test->all.chimney.bottom_left, x, y - 32 - 16 + 8);
					draw_on_image(test, &test->all.chimney.bottom_right, x + 64, y - 32 - 16 + 8);
					draw_on_image(test, &test->all.chimney.mid_left, x, y - 32 - 16 - 64 + 8);
					draw_on_image(test, &test->all.chimney.mid_right, x + 64, y - 32 - 16 - 64 + 8);
					draw_on_image(test, &test->all.chimney.top_left, x, y - 32 - 16 - 128 + 8);
					draw_on_image(test, &test->all.chimney.top_right, x + 64, y - 32 - 16 - 128 + 8);
					if (test->frame < 8)
						test->all.fire.frame = &test->all.fire.frame_one;
					else if (test->frame < 16 && test->frame >= 8)
						test->all.fire.frame = &test->all.fire.frame_three;
					else if (test->frame < 24 && test->frame >= 16)
						test->all.fire.frame = &test->all.fire.frame_five;
					else if (test->frame >= 24)
						test->all.fire.frame = &test->all.fire.frame_seven;
					draw_flames(test, x + 16, y - 51);
					random_obj = 0;
				}
			}
			else if (test->param.map[i][j] == '1' && test->param.map[i][j + 1] == '1' && test->param.map[i][j + 2] == '1' && j + 1 != test->param.width - 1 && ((test->param.map[i][j - 1] == '0' || test->param.map[i][j - 1] == 'P') || (test->param.map[i][j - 1] == '1' && j - 1  == 0)) && ((test->param.map[i][j + 3] == '0' || test->param.map[i][j + 3] == 'P') || (test->param.map[i][j + 3] == '1' && j + 3 == test->param.width - 1)))
			{
					if (piano == 0)
					{
							draw_on_image(test, &test->all.piano.downleft, x, y - 26);
							draw_on_image(test, &test->all.piano.midleft, x, y - 64 - 26);
							draw_on_image(test, &test->all.piano.topleft, x + 9, y - 128 - 26);
							draw_on_image(test, &test->all.piano.downmid, x + 64, y - 26);
							draw_on_image(test, &test->all.piano.midmid, x + 64, y - 64 - 26);
							draw_on_image(test, &test->all.piano.topmid, x + 64, y - 128 - 26);
							draw_on_image(test, &test->all.piano.downright, x + 128, y - 26);
							draw_on_image(test, &test->all.piano.midright, x + 128, y - 64 - 26);
							draw_on_image(test, &test->all.piano.topright, x + 128, y - 128 - 26);
							piano++;
					}
					else
					{
							draw_on_image(test, &test->all.pot, x, y - 32);
							draw_on_image(test, &test->all.pot, x + 64, y - 32);
							draw_on_image(test, &test->all.pot, x + 128, y - 32);
					}
			}
			else if (i == 1 && j != test->param.width - 4 && test->param.map[i][j] == '1' && test->param.map[i][j + 1] == '1' && test->param.map[i][j + 2] == '1' && test->param.map[i][j + 3] == '1')
			{
				draw_on_image(test, &test->all.pot, x, y - 32);
				draw_on_image(test, &test->all.pot, x + 64, y - 32);
				draw_on_image(test, &test->all.pot, x + 128, y - 32);
				draw_on_image(test, &test->all.pot, x + 192, y - 32);
			}
			j++;
		}
		i++;
	}
	test->all.babo = 0;
}

void	draw_collectibles(t_test *test)
{
	int i;
	int j;
	int x;
	int y;
	// int random;

	i = 1;
	// random = 0;
	while (test->param.map[i + 1])
	{
		j = 1;
		while (test->param.map[i][j + 1])
		{
			x = (64 + (test->param.height - 2 - i)*64 + (j-1)*64);
			y = (192 + (i-1)*64);
			if (test->param.map[i][j] == 'C' && j % 2 == 0)
			{
				if (i % 2 == 0)
					draw_on_image(test, &test->collec.newspaper, x, y);
				else if (i % 2 == 1)
					draw_on_image(test, &test->collec.murder_article, x, y);
				// test->collec.random = 1;
			}
			else if (test->param.map[i][j] == 'C' && j % 2 == 1)
			{
				draw_on_image(test, &test->collec.wanted, x, y);
				// test->collec.random = 0;
			}
			j++;
		}
		i++;
	}
}

void	draw_exit(t_test *test)
{
	int i;
	int j;
	int x;
	int y;

	i = 1;
	while (test->param.map[i + 1])
	{
		j = 1;
		while (test->param.map[i][j + 1])
		{
			x = (64 + (test->param.height - 2 - i)*64 + (j-1)*64);
			y = (192 + (i-1)*64);
			if (test->param.map[i][j] == 'E')
			{
 				draw_on_image(test, &test->all.exit.exit_half_right, x + 23, y);
				draw_on_image(test, &test->all.exit.exit_half_left, x - 64 + 27, y);
				if (test->all.exit.opened == 0)
				{
 					draw_on_image(test, &test->all.exit.trapdoor_right, x + 23, y);
 					draw_on_image(test, &test->all.exit.trapdoor_left, x - 64 + 23, y);
				}
				else if (test->all.exit.opened == 1 && test->param.map[i-1][j] != '1')
				{
 					draw_on_image(test, &test->all.exit.open_to_right, x + 23 + 64 - 8 - 8, y-64 + 12);
 					draw_on_image(test, &test->all.exit.open_to_left, x - 64 + 23 + 64 - 8 - 8, y - 64 + 12);
				}
				else if (test->all.exit.opened == 1 && test->param.map[i-1][j] == '1')
				{
					if (test->param.map[i][j + 1] == '0' || test->param.map[i][j + 1] == 'P')
					{
 						draw_on_image(test, &test->all.exit.open_to_right, x + 23 + 64 - 8, y + 12);
 						draw_on_image(test, &test->all.exit.open_to_left, x - 64 + 23 + 64 - 8, y + 12);
					}				
				}
			}
			j++;
		}
		i++;
	}
}

void	get_pos_player(t_test *test)
{
	int i;
	int j;

	i = 0;
    while (test->param.map[i])
	{
		j = 0;
		while (test->param.map[i][j])
		{
			if (test->param.map[i][j] == 'P')
			{
				test->player.pos_i = i;
				test->player.pos_j = j;
				//(j-1)*64 + 12 -> set the position according to the j value in the tab. (+12 is only for more logical player positioning)
				//+(test.data.height - 3) * 64 -> allow you to adjust the player on the x axis depending on the height of the map (every + 1 will need to add 64px to pos_x)
				//-(i-1)*64 -> allow you to adjust the player depending of the y value the player spawn (every +1 will need to remove 64px to print the player closer to the left border) 
				// ORIGINAL SET UP PLAYER

				test->player.pos_x = (j-1)*64 + 30 + (test->param.height - 3) * 64 - (i-1)*64; 
				test->player.pos_y = 3 * 64 + (i-1) * 64 - 64 - 25 + 10;

				//
			}
			else if (test->param.map[i][j] == 'C' && test->param.rendered == 0)
				test->collec.amount++;
			j++;
		}	
		i++;
	}
}

void draw_player(t_test *test)
{
	get_pos_player(test);
	if (test->player.hurt == 1)
	{
		test->player.lock_pos = 1;
        if (test->frame < 17)
		{
			if (test->param.map[test->player.pos_i + 1][test->player.pos_j] == 'T')
		    	test->player.side = &test->player.dmg_front;
			else if (test->param.map[test->player.pos_i - 1][test->player.pos_j] == 'T')
		    	test->player.side = &test->player.dmg_back;
			else if (test->param.map[test->player.pos_i][test->player.pos_j - 1] == 'T')
		    	test->player.side = &test->player.dmg_left;
			else if (test->param.map[test->player.pos_i][test->player.pos_j + 1] == 'T')
		    	test->player.side = &test->player.dmg_right;
		}
		else if (test->frame >= 17)
		{
			//choisir si le player change d'angle de vue en cas de degat ou non
			if (test->param.map[test->player.pos_i + 1][test->player.pos_j] == 'T')
		    	test->player.side = &test->player.frontside;
			else if (test->param.map[test->player.pos_i - 1][test->player.pos_j] == 'T')
		    	test->player.side = &test->player.backside;
			else if (test->param.map[test->player.pos_i][test->player.pos_j - 1] == 'T')
		    	test->player.side = &test->player.leftside;
			else if (test->param.map[test->player.pos_i][test->player.pos_j + 1] == 'T')
		    	test->player.side = &test->player.rightside;
		}
		if (test->frame == 31)
			test->loop++;
		if (test->loop == 4)
		{
			test->player.hurt = 0;
			test->loop = 0;
			test->player.lock_pos = 0;
			test->player.side = &test->player.frontside;
		}
		draw_on_image_bis(test, test->player.side, test->player.pos_x, test->player.pos_y);
	}
	else if (test->player.hurt == 0)
		draw_on_image_bis(test, test->player.side, test->player.pos_x, test->player.pos_y);
}

void	draw_score(t_test *test)
{
	char *steps;
	char *collec;
	char *amount;

	steps = ft_itoa(test->player.steps);
	if (!steps)
		clean_exit(test);
	mlx_string_put(test->mlx, test->win, 25 - 3 - ft_strlen(steps), 20 + 10, 0xf4fefe, steps);
	draw_on_image(test, &test->stats.step, 40 - 8, -10);
	collec = ft_itoa(test->collec.count);
	if (!collec)
		clean_exit(test);
	amount = ft_itoa(test->collec.amount);
	if (!amount)
		clean_exit(test);
	mlx_string_put(test->mlx, test->win, 158 - 100 - 32 - 10, 25 + 32 - 7 + 20, 0xfefefe, collec);
	mlx_string_put(test->mlx, test->win, 166 - 100 - 32 - 10 + (ft_strlen(collec) - 1) * 6, 25 + 32 - 7 + 20, 0xfefefe, "/");
	mlx_string_put(test->mlx, test->win, 173 - 100 - 32 - 10 + (ft_strlen(collec) - 1) * 7, 25 + 32 - 7 + 20, 0xfefefe, amount);
	draw_on_image(test, &test->stats.glass, 173 - 100 - 32 - 10 + (ft_strlen(collec) - 1) * 7, 15 + 20);

	free(steps);
	steps = NULL;
	free(collec);
	collec = NULL;
	free(amount);
	amount = NULL;
}

void	draw_trap(t_test *test)
{
	int i;
	int j;
	int x;
	int y;

	i = 1;
	while (test->param.map[i + 1])
	{
		j = 1;
		while (test->param.map[i][j + 1])
		{
			x = (64 + (test->param.height - 2 - i)*64 + (j-1)*64);
			y = (192 + (i-1)*64);
			if (test->param.map[i][j] == 'T')
			{
 				draw_on_image(test, &test->all.spike, x+16, y-32-8);
 				draw_on_image(test, &test->all.spike, x+8, y-32);
 				draw_on_image(test, &test->all.spike, x, y-16-8);
 				draw_on_image(test, &test->all.spike, x-8, y-16);
			}
			j++;
		}
		i++;
	}
}

void	draw_button(t_test *test)
{
	int i;

	i = 0;
    if ((test->param.map[test->player.pos_i][test->player.pos_j + 1] == 'C' || test->param.map[test->player.pos_i][test->player.pos_j - 1] == 'C' || test->param.map[test->player.pos_i - 1][test->player.pos_j] == 'C' || test->param.map[test->player.pos_i + 1][test->player.pos_j] == 'C'))
    {
		if (test->button.time % 2 == 0)
		{
        	draw_on_image(test, &test->button.e_key, test->player.pos_x + 32, test->player.pos_y - 42);
			while (i < 45000000)
				i++;
			test->button.time = 1;
		}
		else if (test->button.time % 2 == 1)
		{
			draw_walls(test);
			draw_floors(test);
			draw_furnitures(test);
			draw_collectibles(test);
			draw_trap(test);
			if (test->param.map[test->player.pos_i][test->player.pos_j + 1] == 'C')
				test->player.side = &test->player.rightside;
			else if (test->param.map[test->player.pos_i][test->player.pos_j - 1] == 'C')
				test->player.side = &test->player.leftside;
			else if (test->param.map[test->player.pos_i - 1][test->player.pos_j] == 'C')
				test->player.side = &test->player.backside;
			else if (test->param.map[test->player.pos_i + 1][test->player.pos_j] == 'C')
				test->player.side = &test->player.frontside;
			if (test->all.exit.opened == 1)
				draw_exit(test);
			draw_player(test);
			if (test->all.exit.opened == 0)
				draw_exit(test);
			draw_score(test);
			while (i < 240000000)
				i++;
			test->button.time = 0;
		}
    }
	else if (test->param.map[test->player.pos_i - 1][test->player.pos_j] == '1' && test->param.map[test->player.pos_i - 1][test->player.pos_j + 1] == '1' && test->param.map[test->player.pos_i - 1][test->player.pos_j + 2] == '0' && test->player.pos_j + 1 < test->param.width - 1 && test->param.map[test->player.pos_i - 1][test->player.pos_j - 1] == '1' && test->param.map[test->player.pos_i - 1][test->player.pos_j - 2] == '0')
	{
		if (test->button.time % 2 == 0 && test->player.lock_pos == 0)
		{
        	draw_on_image(test, &test->button.p_key, test->player.pos_x + 32, test->player.pos_y - 42);
			while (i < 45000000)
				i++;
			test->button.time = 1;
		}
		else if (test->button.time % 2 == 1)
		{
			draw_walls(test);
			draw_floors(test);
			draw_furnitures(test);
			draw_collectibles(test);
			draw_trap(test);
			test->player.side = &test->player.backside;
			if (test->all.exit.opened == 1)
				draw_exit(test);
			draw_player(test);
			if (test->all.exit.opened == 0)
				draw_exit(test);
			draw_score(test);
			while (i < 240000000)
				i++;
			test->button.time = 0;
		}
	}
	else if (test->collec.exit == 1 && test->all.exit.opened == 0)
	{
		if (test->button.time % 2 == 0)
		{
        	draw_on_image(test, &test->button.o_key, test->player.pos_x + 32, test->player.pos_y - 42);
			while (i < 45000000)
				i++;
			test->button.time = 1;
			test->player.lock_pos = 1;
		}
		else if (test->button.time % 2 == 1)
		{
			draw_walls(test);
			draw_floors(test);
			draw_furnitures(test);
			draw_collectibles(test);
			draw_trap(test);
			if (test->all.exit.opened == 1)
				draw_exit(test);
			draw_player(test);
			if (test->all.exit.opened == 0)
				draw_exit(test);
			draw_score(test);
			while (i < 240000000)
				i++;
			test->button.time = 0;
		}
	}
}

void 	draw_dialog_box(t_test *test)
{
	draw_on_image(test, &test->dialog_box.left, (test->param.width/2-2) * 64, (test->param.height) * 64);
	draw_on_image(test, &test->dialog_box.mid, (test->param.width/2-1) * 64, (test->param.height) * 64);
	draw_on_image(test, &test->dialog_box.mid, (test->param.width/2) * 64, (test->param.height) * 64);
	draw_on_image(test, &test->dialog_box.mid, (test->param.width/2+1) * 64, (test->param.height) * 64);
	draw_on_image(test, &test->dialog_box.right, (test->param.width/2+2) * 64, (test->param.height) * 64);
	// printf("event = %d\n", test->dialog_box.event);
	if (test->dialog_box.event == 1)
	{
		mlx_string_put(test->mlx, test->win, (test->param.width/2-2) * 64 + 4, (test->param.height) * 64 + 16, 0xf4fefe, "Hmm strange... This piano seems to be perfectly");
		mlx_string_put(test->mlx, test->win, (test->param.width/2-2) * 64 + 4, (test->param.height) * 64 + 32, 0xf4fefe, "working...");
		mlx_string_put(test->mlx, test->win, (test->param.width/2+1) * 64 + 8, (test->param.height) * 64 + 32 + 16 + 5, 0xf4fefe, "Press C to continue");
		test->player.lock_pos = 1;
	}
	else if (test->dialog_box.event == 2)
	{
		mlx_string_put(test->mlx, test->win, (test->param.width/2-2) * 64 + 4, (test->param.height) * 64 + 16, 0xf4fefe, "You have 1 new item in your inventory!");
		mlx_string_put(test->mlx, test->win, (test->param.width/2+1) * 64 + 8, (test->param.height) * 64 + 32 + 16 + 5, 0xf4fefe, "Press C to continue");
		test->player.lock_pos = 1;
	}
	else if (test->dialog_box.event == 3)
	{
		mlx_string_put(test->mlx, test->win, (test->param.width/2-2) * 64 + 4, (test->param.height) * 64 + 16, 0xf4fefe, "I should take all the newspaper reports with me");
		mlx_string_put(test->mlx, test->win, (test->param.width/2-2) * 64 + 4, (test->param.height) * 64 + 32, 0xf4fefe, "before I go further..");
		mlx_string_put(test->mlx, test->win, (test->param.width/2+1) * 64 + 8, (test->param.height) * 64 + 32 + 16 + 5, 0xf4fefe, "Press C to continue");
		test->player.lock_pos = 1;
	}
}

void	draw_life(t_test *test)
{
	int i;
	int j;

	draw_on_image(test, &test->stats.typeface_life, 7, 28 + 64);
	i = test->stats.lives;
	test->stats.damages = 3 - test->stats.lives;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			draw_on_image(test, &test->stats.full_heart, 7 + j * 24, -5 + 64);
			j++;
		}
		while (test->stats.damages > 0)
		{
			draw_on_image(test, &test->stats.empty_heart, 7 + ((test->stats.damages - 1) + test->stats.lives)* 24, -5 + 64);
			test->stats.damages--;
		}
		i--;
	}
}

int    render(t_test *test)
{
	if (test->intro_or_not == 1 && test->param.width_with_x*64-(2*64) == 960 && (test->param.height-2)*64+3*64 == 448)
	{
		draw_on_image_intro(test, &test->intro.one, 0, 0);
		mlx_put_image_to_window(test->mlx, test->win, test->data.img, 0, 0);
	}
	else if (test->intro_or_not == 2 && test->param.width_with_x*64-(2*64) == 960 && (test->param.height-2)*64+3*64 == 448)
	{
		draw_on_image_intro(test, &test->intro.two, 0, 0);
		mlx_put_image_to_window(test->mlx, test->win, test->data.img, 0, 0);
	}
	else if (test->intro_or_not == 3 && test->param.width_with_x*64-(2*64) == 960 && (test->param.height-2)*64+3*64 == 448)
	{
		draw_on_image_intro(test, &test->intro.three, 0, 0);
		mlx_put_image_to_window(test->mlx, test->win, test->data.img, 0, 0);
	}
	else if (test->intro_or_not == 4 && test->param.width_with_x*64-(2*64) == 960 && (test->param.height-2)*64+3*64 == 448)
	{
		draw_on_image_intro(test, &test->intro.four, 0, 0);
		mlx_put_image_to_window(test->mlx, test->win, test->data.img, 0, 0);
	}
	else if (test->intro_or_not == 5 && test->param.width_with_x*64-(2*64) == 960 && (test->param.height-2)*64+3*64 == 448)
	{
		draw_on_image_intro(test, &test->intro.five, 0, 0);
		mlx_put_image_to_window(test->mlx, test->win, test->data.img, 0, 0);
	}
	else if (test->param.rendered == 0 || test->param.rendered == 1)
	{
		draw_background(test);
		draw_walls(test);
		draw_floors(test);
		draw_furnitures(test);
		draw_collectibles(test);
		draw_trap(test);
		if (test->param.rendered == 0)
			test->player.side = &test->player.frontside;
		if (test->all.exit.opened == 1)
			draw_exit(test);
		draw_player(test);
		if (test->all.exit.opened == 0)
			draw_exit(test);
		mlx_put_image_to_window(test->mlx, test->win, test->data.img, 0, 0);
		draw_score(test);
		draw_button(test);
		test->param.rendered = 1;
		if (test->dialog_box.keep == 1)
			draw_dialog_box(test);
		draw_life(test);
		test->frame++;
		if (test->frame % 40 / 32 == 1)
			test->frame = 0;
		test->intro_or_not = 0;
	}
	// printf("%d\n", test->frame);
	return (0);
}

void	play_piano(t_test *test)
{
	if (test->player.pos_i != 1 && test->param.map[test->player.pos_i - 1][test->player.pos_j] == '1' && test->param.map[test->player.pos_i - 1][test->player.pos_j + 1] == '1' && test->param.map[test->player.pos_i - 1][test->player.pos_j + 2] == '0' && test->player.pos_j + 1 < test->param.width - 1 && test->param.map[test->player.pos_i - 1][test->player.pos_j - 1] == '1' && test->param.map[test->player.pos_i - 1][test->player.pos_j - 2] == '0')
	{
		test->dialog_box.event = 1;
		draw_dialog_box(test);
		test->dialog_box.keep = 1;
	}
}

void	pick_up_coll(t_test *test)
{
	if (test->param.map[test->player.pos_i][test->player.pos_j + 1] == 'C')
	{
		test->dialog_box.event = 2;
		draw_dialog_box(test);
		test->dialog_box.keep = 1;
		test->param.map[test->player.pos_i][test->player.pos_j + 1] = '0';
        test->collec.count++;
        printf("%d object in your inventory\n", test->collec.count);
	}
	else if (test->param.map[test->player.pos_i][test->player.pos_j - 1] == 'C')
	{
		test->dialog_box.event = 2;
		draw_dialog_box(test);
		test->dialog_box.keep = 1;
		test->param.map[test->player.pos_i][test->player.pos_j - 1] = '0';
        test->collec.count++;
        printf("%d object in your inventory\n", test->collec.count);
	}
	else if (test->param.map[test->player.pos_i + 1][test->player.pos_j] == 'C')
	{
		test->dialog_box.event = 2;
		draw_dialog_box(test);
		test->dialog_box.keep = 1;
		test->param.map[test->player.pos_i + 1][test->player.pos_j] = '0';
        test->collec.count++;
        printf("%d object in your inventory\n", test->collec.count);
	}
	else if (test->param.map[test->player.pos_i - 1][test->player.pos_j] == 'C')
	{
		test->dialog_box.event = 2;
		draw_dialog_box(test);
		test->dialog_box.keep = 1;
		test->param.map[test->player.pos_i - 1][test->player.pos_j] = '0';
        test->collec.count++;
        printf("%d object in your inventory\n", test->collec.count);
	}
}

void	clean_dialog(t_test *test)
{
	test->dialog_box.keep = 0;
	test->player.lock_pos = 0;
}

void	open_trapdoor(t_test *test)
{
	test->all.exit.opened = 1;
	test->player.lock_pos = 0;
}

int     handle_keypress(int keysym, t_test *test)
{
	if (test->intro_or_not == 0)
	{
    	if (keysym == ESC)
	   		clean_exit(test);
    	else if (keysym == D)
	    	move_right(test);
    	else if (keysym == A)
	    	move_left(test);
    	else if (keysym == W)
	    	move_up(test);
   		else if (keysym == S)
	    	move_down(test);
		else if (keysym == E)
			pick_up_coll(test);
		else if (keysym == P)
			play_piano(test);
		else if (keysym == C)
			clean_dialog(test);
		else if (keysym == O)
			open_trapdoor(test);
		else if (keysym != ESC)
        	write(1, &keysym, 1);
	}
	else
	{
		if (keysym == SPACE && test->intro_or_not == 1)
			test->intro_or_not++;
		else if (keysym == SPACE && test->intro_or_not == 2)
			test->intro_or_not++;
		else if (keysym == SPACE && test->intro_or_not == 3)
			test->intro_or_not++;
		else if (keysym == SPACE && test->intro_or_not == 4)
			test->intro_or_not++;
		else if (keysym == SPACE && test->intro_or_not == 5)
			test->intro_or_not = 0;
		else if (keysym == ESC)
	   		clean_exit(test);
		else
        	write(1, &keysym, 1);
	}
    return (0);
}

int main(int ac, char **av)
{
    t_test test;
///////////////////////////// RECUP MA MAP DANS TAB
	
	get_map(&test, ac, av);

///////////////
    test.mlx = mlx_init();
    test.win = mlx_new_window(test.mlx, test.param.width_with_x*64-(2*64), (test.param.height-2)*64+3*64, "so_short on time!");
    test.data.img = mlx_new_image(test.mlx, test.param.width_with_x*64-(2*64), (test.param.height-2)*64+3*64);
    test.data.addr = mlx_get_data_addr(test.data.img, &test.data.bits_per_pixel, &test.data.line_length, &test.data.endian);

	test.intro.one.img = mlx_xpm_file_to_image(test.mlx, "textures/murderer_960.xpm", &test.intro.one.x, &test.intro.one.y);
	test.intro.one.addr = mlx_get_data_addr(test.intro.one.img, &test.intro.one.bits_per_pixel, &test.intro.one.line_length, &test.intro.one.endian);
	test.intro.two.img = mlx_xpm_file_to_image(test.mlx, "textures/dead_wife_960.xpm", &test.intro.two.x, &test.intro.two.y);
	test.intro.two.addr = mlx_get_data_addr(test.intro.two.img, &test.intro.two.bits_per_pixel, &test.intro.two.line_length, &test.intro.two.endian);
	test.intro.three.img = mlx_xpm_file_to_image(test.mlx, "textures/rainy_960.xpm", &test.intro.three.x, &test.intro.three.y);
	test.intro.three.addr = mlx_get_data_addr(test.intro.three.img, &test.intro.three.bits_per_pixel, &test.intro.three.line_length, &test.intro.three.endian);
	test.intro.four.img = mlx_xpm_file_to_image(test.mlx, "textures/working_desk_960.xpm", &test.intro.four.x, &test.intro.four.y);
	test.intro.four.addr = mlx_get_data_addr(test.intro.four.img, &test.intro.four.bits_per_pixel, &test.intro.four.line_length, &test.intro.four.endian);
	test.intro.five.img = mlx_xpm_file_to_image(test.mlx, "textures/960_448.xpm", &test.intro.five.x, &test.intro.five.y);
	test.intro.five.addr = mlx_get_data_addr(test.intro.five.img, &test.intro.five.bits_per_pixel, &test.intro.five.line_length, &test.intro.five.endian);

    test.all.wall.img = mlx_xpm_file_to_image(test.mlx, "textures/wall.xpm", &test.all.wall.x, &test.all.wall.y);
    test.all.wall.addr = mlx_get_data_addr(test.all.wall.img, &test.all.wall.bits_per_pixel, &test.all.wall.line_length, &test.all.wall.endian);

    test.all.floor.img = mlx_xpm_file_to_image(test.mlx, "textures/floor.xpm", &test.all.floor.x, &test.all.floor.y);
    test.all.floor.addr = mlx_get_data_addr(test.all.floor.img, &test.all.floor.bits_per_pixel, &test.all.floor.line_length, &test.all.floor.endian);

    test.all.floor_half_right.img = mlx_xpm_file_to_image(test.mlx, "textures/floor_half_right.xpm", &test.all.floor_half_right.x, &test.all.floor_half_right.y);
    test.all.floor_half_right.addr = mlx_get_data_addr(test.all.floor_half_right.img, &test.all.floor_half_right.bits_per_pixel, &test.all.floor_half_right.line_length, &test.all.floor_half_right.endian);
    test.all.floor_half_left.img = mlx_xpm_file_to_image(test.mlx, "textures/floor_half_left.xpm", &test.all.floor_half_left.x, &test.all.floor_half_left.y);
    test.all.floor_half_left.addr = mlx_get_data_addr(test.all.floor_half_left.img, &test.all.floor_half_left.bits_per_pixel, &test.all.floor_half_left.line_length, &test.all.floor_half_left.endian);

    test.all.box.img = mlx_xpm_file_to_image(test.mlx, "textures/box.xpm", &test.all.box.x, &test.all.box.y);
    test.all.box.addr = mlx_get_data_addr(test.all.box.img, &test.all.box.bits_per_pixel, &test.all.box.line_length, &test.all.box.endian);
    test.all.pot.img = mlx_xpm_file_to_image(test.mlx, "textures/pot.xpm", &test.all.pot.x, &test.all.pot.y);
    test.all.pot.addr = mlx_get_data_addr(test.all.pot.img, &test.all.pot.bits_per_pixel, &test.all.pot.line_length, &test.all.pot.endian);
    test.all.cardboard.img = mlx_xpm_file_to_image(test.mlx, "textures/cardboard.xpm", &test.all.cardboard.x, &test.all.cardboard.y);
    test.all.cardboard.addr = mlx_get_data_addr(test.all.cardboard.img, &test.all.cardboard.bits_per_pixel, &test.all.cardboard.line_length, &test.all.cardboard.endian);
    test.all.dresser_topright.img = mlx_xpm_file_to_image(test.mlx, "textures/dresser3_topright.xpm", &test.all.dresser_topright.x, &test.all.dresser_topright.y);
    test.all.dresser_topright.addr = mlx_get_data_addr(test.all.dresser_topright.img, &test.all.dresser_topright.bits_per_pixel, &test.all.dresser_topright.line_length, &test.all.dresser_topright.endian);
    test.all.dresser_topleft.img = mlx_xpm_file_to_image(test.mlx, "textures/dresser3_topleft.xpm", &test.all.dresser_topleft.x, &test.all.dresser_topleft.y);
    test.all.dresser_topleft.addr = mlx_get_data_addr(test.all.dresser_topleft.img, &test.all.dresser_topleft.bits_per_pixel, &test.all.dresser_topleft.line_length, &test.all.dresser_topleft.endian);
    test.all.dresser_downright.img = mlx_xpm_file_to_image(test.mlx, "textures/dresser3_downright.xpm", &test.all.dresser_downright.x, &test.all.dresser_downright.y);
    test.all.dresser_downright.addr = mlx_get_data_addr(test.all.dresser_downright.img, &test.all.dresser_downright.bits_per_pixel, &test.all.dresser_downright.line_length, &test.all.dresser_downright.endian);
    test.all.dresser_downleft.img = mlx_xpm_file_to_image(test.mlx, "textures/dresser3_downleft.xpm", &test.all.dresser_downleft.x, &test.all.dresser_downleft.y);
    test.all.dresser_downleft.addr = mlx_get_data_addr(test.all.dresser_downleft.img, &test.all.dresser_downleft.bits_per_pixel, &test.all.dresser_downleft.line_length, &test.all.dresser_downleft.endian);
    test.all.babolex_painting.img = mlx_xpm_file_to_image(test.mlx, "textures/babolex_painting2.xpm", &test.all.babolex_painting.x, &test.all.babolex_painting.y);
    test.all.babolex_painting.addr = mlx_get_data_addr(test.all.babolex_painting.img, &test.all.babolex_painting.bits_per_pixel, &test.all.babolex_painting.line_length, &test.all.babolex_painting.endian);
    
// PIANO /////
	test.all.piano.topright.img = mlx_xpm_file_to_image(test.mlx, "textures/piano_topright.xpm", &test.all.piano.topright.x, &test.all.piano.topright.y);
    test.all.piano.topright.addr = mlx_get_data_addr(test.all.piano.topright.img, &test.all.piano.topright.bits_per_pixel, &test.all.piano.topright.line_length, &test.all.piano.topright.endian);
    test.all.piano.topmid.img = mlx_xpm_file_to_image(test.mlx, "textures/piano_topmid.xpm", &test.all.piano.topmid.x, &test.all.piano.topmid.y);
    test.all.piano.topmid.addr = mlx_get_data_addr(test.all.piano.topmid.img, &test.all.piano.topmid.bits_per_pixel, &test.all.piano.topmid.line_length, &test.all.piano.topmid.endian);
    test.all.piano.topleft.img = mlx_xpm_file_to_image(test.mlx, "textures/piano_topleft.xpm", &test.all.piano.topleft.x, &test.all.piano.topleft.y);
    test.all.piano.topleft.addr = mlx_get_data_addr(test.all.piano.topleft.img, &test.all.piano.topleft.bits_per_pixel, &test.all.piano.topleft.line_length, &test.all.piano.topleft.endian);

	test.all.piano.midright.img = mlx_xpm_file_to_image(test.mlx, "textures/piano_midright.xpm", &test.all.piano.midright.x, &test.all.piano.midright.y);
    test.all.piano.midright.addr = mlx_get_data_addr(test.all.piano.midright.img, &test.all.piano.midright.bits_per_pixel, &test.all.piano.midright.line_length, &test.all.piano.midright.endian);
    test.all.piano.midmid.img = mlx_xpm_file_to_image(test.mlx, "textures/piano_midmid.xpm", &test.all.piano.midmid.x, &test.all.piano.midmid.y);
    test.all.piano.midmid.addr = mlx_get_data_addr(test.all.piano.midmid.img, &test.all.piano.midmid.bits_per_pixel, &test.all.piano.midmid.line_length, &test.all.piano.midmid.endian);
    test.all.piano.midleft.img = mlx_xpm_file_to_image(test.mlx, "textures/piano_midleft.xpm", &test.all.piano.midleft.x, &test.all.piano.midleft.y);
    test.all.piano.midleft.addr = mlx_get_data_addr(test.all.piano.midleft.img, &test.all.piano.midleft.bits_per_pixel, &test.all.piano.midleft.line_length, &test.all.piano.midleft.endian);

	test.all.piano.downright.img = mlx_xpm_file_to_image(test.mlx, "textures/piano_downright.xpm", &test.all.piano.downright.x, &test.all.piano.downright.y);
    test.all.piano.downright.addr = mlx_get_data_addr(test.all.piano.downright.img, &test.all.piano.downright.bits_per_pixel, &test.all.piano.downright.line_length, &test.all.piano.downright.endian);
    test.all.piano.downmid.img = mlx_xpm_file_to_image(test.mlx, "textures/piano_downmid.xpm", &test.all.piano.downmid.x, &test.all.piano.downmid.y);
    test.all.piano.downmid.addr = mlx_get_data_addr(test.all.piano.downmid.img, &test.all.piano.downmid.bits_per_pixel, &test.all.piano.downmid.line_length, &test.all.piano.downmid.endian);
    test.all.piano.downleft.img = mlx_xpm_file_to_image(test.mlx, "textures/piano_downleft.xpm", &test.all.piano.downleft.x, &test.all.piano.downleft.y);
    test.all.piano.downleft.addr = mlx_get_data_addr(test.all.piano.downleft.img, &test.all.piano.downleft.bits_per_pixel, &test.all.piano.downleft.line_length, &test.all.piano.downleft.endian);
///////CHIMNEY//////

	test.all.chimney.bottom_right.img = mlx_xpm_file_to_image(test.mlx, "textures/chimney_br.xpm", &test.all.chimney.bottom_right.x, &test.all.chimney.bottom_right.y);
    test.all.chimney.bottom_right.addr = mlx_get_data_addr(test.all.chimney.bottom_right.img, &test.all.chimney.bottom_right.bits_per_pixel, &test.all.chimney.bottom_right.line_length, &test.all.chimney.bottom_right.endian);
	test.all.chimney.bottom_left.img = mlx_xpm_file_to_image(test.mlx, "textures/chimney_bl.xpm", &test.all.chimney.bottom_left.x, &test.all.chimney.bottom_left.y);
    test.all.chimney.bottom_left.addr = mlx_get_data_addr(test.all.chimney.bottom_left.img, &test.all.chimney.bottom_left.bits_per_pixel, &test.all.chimney.bottom_left.line_length, &test.all.chimney.bottom_left.endian);
	test.all.chimney.mid_right.img = mlx_xpm_file_to_image(test.mlx, "textures/chimney_mr.xpm", &test.all.chimney.mid_right.x, &test.all.chimney.mid_right.y);
    test.all.chimney.mid_right.addr = mlx_get_data_addr(test.all.chimney.mid_right.img, &test.all.chimney.mid_right.bits_per_pixel, &test.all.chimney.mid_right.line_length, &test.all.chimney.mid_right.endian);
	test.all.chimney.mid_left.img = mlx_xpm_file_to_image(test.mlx, "textures/chimney_ml.xpm", &test.all.chimney.mid_left.x, &test.all.chimney.mid_left.y);
    test.all.chimney.mid_left.addr = mlx_get_data_addr(test.all.chimney.mid_left.img, &test.all.chimney.mid_left.bits_per_pixel, &test.all.chimney.mid_left.line_length, &test.all.chimney.mid_left.endian);
	test.all.chimney.top_right.img = mlx_xpm_file_to_image(test.mlx, "textures/chimney_tr.xpm", &test.all.chimney.top_right.x, &test.all.chimney.top_right.y);
    test.all.chimney.top_right.addr = mlx_get_data_addr(test.all.chimney.top_right.img, &test.all.chimney.top_right.bits_per_pixel, &test.all.chimney.top_right.line_length, &test.all.chimney.top_right.endian);
	test.all.chimney.top_left.img = mlx_xpm_file_to_image(test.mlx, "textures/chimney_tl.xpm", &test.all.chimney.top_left.x, &test.all.chimney.top_left.y);
    test.all.chimney.top_left.addr = mlx_get_data_addr(test.all.chimney.top_left.img, &test.all.chimney.top_left.bits_per_pixel, &test.all.chimney.top_left.line_length, &test.all.chimney.top_left.endian);

	test.all.fire.frame_one.img = mlx_xpm_file_to_image(test.mlx, "textures/flame_1.xpm", &test.all.fire.frame_one.x, &test.all.fire.frame_one.y);
    test.all.fire.frame_one.addr = mlx_get_data_addr(test.all.fire.frame_one.img, &test.all.fire.frame_one.bits_per_pixel, &test.all.fire.frame_one.line_length, &test.all.fire.frame_one.endian);
	test.all.fire.frame_two.img = mlx_xpm_file_to_image(test.mlx, "textures/flame_2.xpm", &test.all.fire.frame_two.x, &test.all.fire.frame_two.y);
    test.all.fire.frame_two.addr = mlx_get_data_addr(test.all.fire.frame_two.img, &test.all.fire.frame_two.bits_per_pixel, &test.all.fire.frame_two.line_length, &test.all.fire.frame_two.endian);
	test.all.fire.frame_three.img = mlx_xpm_file_to_image(test.mlx, "textures/flame_3.xpm", &test.all.fire.frame_three.x, &test.all.fire.frame_three.y);
    test.all.fire.frame_three.addr = mlx_get_data_addr(test.all.fire.frame_three.img, &test.all.fire.frame_three.bits_per_pixel, &test.all.fire.frame_three.line_length, &test.all.fire.frame_three.endian);
	test.all.fire.frame_four.img = mlx_xpm_file_to_image(test.mlx, "textures/flame_4.xpm", &test.all.fire.frame_four.x, &test.all.fire.frame_four.y);
    test.all.fire.frame_four.addr = mlx_get_data_addr(test.all.fire.frame_four.img, &test.all.fire.frame_four.bits_per_pixel, &test.all.fire.frame_four.line_length, &test.all.fire.frame_four.endian);
	test.all.fire.frame_five.img = mlx_xpm_file_to_image(test.mlx, "textures/flame_5.xpm", &test.all.fire.frame_five.x, &test.all.fire.frame_five.y);
    test.all.fire.frame_five.addr = mlx_get_data_addr(test.all.fire.frame_five.img, &test.all.fire.frame_five.bits_per_pixel, &test.all.fire.frame_five.line_length, &test.all.fire.frame_five.endian);
	test.all.fire.frame_six.img = mlx_xpm_file_to_image(test.mlx, "textures/flame_6.xpm", &test.all.fire.frame_six.x, &test.all.fire.frame_six.y);
    test.all.fire.frame_six.addr = mlx_get_data_addr(test.all.fire.frame_six.img, &test.all.fire.frame_six.bits_per_pixel, &test.all.fire.frame_six.line_length, &test.all.fire.frame_six.endian);
	test.all.fire.frame_seven.img = mlx_xpm_file_to_image(test.mlx, "textures/flame_7.xpm", &test.all.fire.frame_seven.x, &test.all.fire.frame_seven.y);
    test.all.fire.frame_seven.addr = mlx_get_data_addr(test.all.fire.frame_seven.img, &test.all.fire.frame_seven.bits_per_pixel, &test.all.fire.frame_seven.line_length, &test.all.fire.frame_seven.endian);
	test.all.fire.frame_eight.img = mlx_xpm_file_to_image(test.mlx, "textures/flame_8.xpm", &test.all.fire.frame_eight.x, &test.all.fire.frame_eight.y);
    test.all.fire.frame_eight.addr = mlx_get_data_addr(test.all.fire.frame_eight.img, &test.all.fire.frame_eight.bits_per_pixel, &test.all.fire.frame_eight.line_length, &test.all.fire.frame_eight.endian);

////////////

    test.collec.newspaper.img = mlx_xpm_file_to_image(test.mlx, "textures/newspaper.xpm", &test.collec.newspaper.x, &test.collec.newspaper.y);
    test.collec.newspaper.addr = mlx_get_data_addr(test.collec.newspaper.img, &test.collec.newspaper.bits_per_pixel, &test.collec.newspaper.line_length, &test.collec.newspaper.endian);
	test.collec.wanted.img = mlx_xpm_file_to_image(test.mlx, "textures/wanted.xpm", &test.collec.wanted.x, &test.collec.wanted.y);
    test.collec.wanted.addr = mlx_get_data_addr(test.collec.wanted.img, &test.collec.wanted.bits_per_pixel, &test.collec.wanted.line_length, &test.collec.wanted.endian);
	test.collec.murder_article.img = mlx_xpm_file_to_image(test.mlx, "textures/murder_article.xpm", &test.collec.murder_article.x, &test.collec.murder_article.y);
    test.collec.murder_article.addr = mlx_get_data_addr(test.collec.murder_article.img, &test.collec.murder_article.bits_per_pixel, &test.collec.murder_article.line_length, &test.collec.murder_article.endian);

    test.all.exit.exit_half_left.img = mlx_xpm_file_to_image(test.mlx, "textures/CUT_ladder.xpm", &test.all.exit.exit_half_left.x, &test.all.exit.exit_half_left.y);
    test.all.exit.exit_half_left.addr = mlx_get_data_addr(test.all.exit.exit_half_left.img, &test.all.exit.exit_half_left.bits_per_pixel, &test.all.exit.exit_half_left.line_length, &test.all.exit.exit_half_left.endian);
	test.all.exit.exit_half_right.img = mlx_xpm_file_to_image(test.mlx, "textures/CUT_ladder_right.xpm", &test.all.exit.exit_half_right.x, &test.all.exit.exit_half_right.y);
    test.all.exit.exit_half_right.addr = mlx_get_data_addr(test.all.exit.exit_half_right.img, &test.all.exit.exit_half_right.bits_per_pixel, &test.all.exit.exit_half_right.line_length, &test.all.exit.exit_half_right.endian);
	test.all.exit.trapdoor_right.img = mlx_xpm_file_to_image(test.mlx, "textures/FINAL2_right.xpm", &test.all.exit.trapdoor_right.x, &test.all.exit.trapdoor_right.y);
    test.all.exit.trapdoor_right.addr = mlx_get_data_addr(test.all.exit.trapdoor_right.img, &test.all.exit.trapdoor_right.bits_per_pixel, &test.all.exit.trapdoor_right.line_length, &test.all.exit.trapdoor_right.endian);
	test.all.exit.trapdoor_left.img = mlx_xpm_file_to_image(test.mlx, "textures/FINAL2_left.xpm", &test.all.exit.trapdoor_left.x, &test.all.exit.trapdoor_left.y);
    test.all.exit.trapdoor_left.addr = mlx_get_data_addr(test.all.exit.trapdoor_left.img, &test.all.exit.trapdoor_left.bits_per_pixel, &test.all.exit.trapdoor_left.line_length, &test.all.exit.trapdoor_left.endian);
	test.all.exit.open_to_right.img = mlx_xpm_file_to_image(test.mlx, "textures/trapdoor_oriented_right.xpm", &test.all.exit.open_to_right.x, &test.all.exit.open_to_right.y);
    test.all.exit.open_to_right.addr = mlx_get_data_addr(test.all.exit.open_to_right.img, &test.all.exit.open_to_right.bits_per_pixel, &test.all.exit.open_to_right.line_length, &test.all.exit.open_to_right.endian);
	test.all.exit.open_to_left.img = mlx_xpm_file_to_image(test.mlx, "textures/trapdoor_oriented_left.xpm", &test.all.exit.open_to_left.x, &test.all.exit.open_to_left.y);
    test.all.exit.open_to_left.addr = mlx_get_data_addr(test.all.exit.open_to_left.img, &test.all.exit.open_to_left.bits_per_pixel, &test.all.exit.open_to_left.line_length, &test.all.exit.open_to_left.endian);

	test.player.frontside.img = mlx_xpm_file_to_image(test.mlx, "textures/detective_frontside.xpm", &test.player.frontside.x, &test.player.frontside.y);
	test.player.frontside.addr = mlx_get_data_addr(test.player.frontside.img, &test.player.frontside.bits_per_pixel, &test.player.frontside.line_length, &test.player.frontside.endian);
	test.player.backside.img = mlx_xpm_file_to_image(test.mlx, "textures/detective_backside.xpm", &test.player.backside.x, &test.player.backside.y);
	test.player.backside.addr = mlx_get_data_addr(test.player.backside.img, &test.player.backside.bits_per_pixel, &test.player.backside.line_length, &test.player.backside.endian);
	test.player.rightside.img = mlx_xpm_file_to_image(test.mlx, "textures/detective_sideright.xpm", &test.player.rightside.x, &test.player.rightside.y);
	test.player.rightside.addr = mlx_get_data_addr(test.player.rightside.img, &test.player.rightside.bits_per_pixel, &test.player.rightside.line_length, &test.player.rightside.endian);
	test.player.leftside.img = mlx_xpm_file_to_image(test.mlx, "textures/detective_sideleft.xpm", &test.player.leftside.x, &test.player.leftside.y);
	test.player.leftside.addr = mlx_get_data_addr(test.player.leftside.img, &test.player.leftside.bits_per_pixel, &test.player.leftside.line_length, &test.player.leftside.endian);
	test.player.dmg_front.img = mlx_xpm_file_to_image(test.mlx, "textures/damages_front.xpm", &test.player.dmg_front.x, &test.player.dmg_front.y);
	test.player.dmg_front.addr = mlx_get_data_addr(test.player.dmg_front.img, &test.player.dmg_front.bits_per_pixel, &test.player.dmg_front.line_length, &test.player.dmg_front.endian);
	test.player.dmg_back.img = mlx_xpm_file_to_image(test.mlx, "textures/damages_back.xpm", &test.player.dmg_back.x, &test.player.dmg_back.y);
	test.player.dmg_back.addr = mlx_get_data_addr(test.player.dmg_back.img, &test.player.dmg_back.bits_per_pixel, &test.player.dmg_back.line_length, &test.player.dmg_back.endian);
	test.player.dmg_right.img = mlx_xpm_file_to_image(test.mlx, "textures/damages_sideright.xpm", &test.player.dmg_right.x, &test.player.dmg_right.y);
	test.player.dmg_right.addr = mlx_get_data_addr(test.player.dmg_right.img, &test.player.dmg_right.bits_per_pixel, &test.player.dmg_right.line_length, &test.player.dmg_right.endian);
	test.player.dmg_left.img = mlx_xpm_file_to_image(test.mlx, "textures/damages_sideleft.xpm", &test.player.dmg_left.x, &test.player.dmg_left.y);
	test.player.dmg_left.addr = mlx_get_data_addr(test.player.dmg_left.img, &test.player.dmg_left.bits_per_pixel, &test.player.dmg_left.line_length, &test.player.dmg_left.endian);
	
    test.button.e_key.img = mlx_xpm_file_to_image(test.mlx, "textures/key_e.xpm", &test.button.e_key.x, &test.button.e_key.y);
    test.button.e_key.addr = mlx_get_data_addr(test.button.e_key.img, &test.button.e_key.bits_per_pixel, &test.button.e_key.line_length, &test.button.e_key.endian);
	test.button.p_key.img = mlx_xpm_file_to_image(test.mlx, "textures/key_p.xpm", &test.button.p_key.x, &test.button.p_key.y);
    test.button.p_key.addr = mlx_get_data_addr(test.button.p_key.img, &test.button.p_key.bits_per_pixel, &test.button.p_key.line_length, &test.button.p_key.endian);
	test.button.o_key.img = mlx_xpm_file_to_image(test.mlx, "textures/key_o.xpm", &test.button.o_key.x, &test.button.o_key.y);
    test.button.o_key.addr = mlx_get_data_addr(test.button.o_key.img, &test.button.o_key.bits_per_pixel, &test.button.o_key.line_length, &test.button.o_key.endian);

	test.dialog_box.right.img = mlx_xpm_file_to_image(test.mlx, "textures/dialog_box_right.xpm", &test.dialog_box.right.x, &test.dialog_box.right.y);
    test.dialog_box.right.addr = mlx_get_data_addr(test.dialog_box.right.img, &test.dialog_box.right.bits_per_pixel, &test.dialog_box.right.line_length, &test.dialog_box.right.endian);
	test.dialog_box.mid.img = mlx_xpm_file_to_image(test.mlx, "textures/dialog_box_mid.xpm", &test.dialog_box.mid.x, &test.dialog_box.mid.y);
    test.dialog_box.mid.addr = mlx_get_data_addr(test.dialog_box.mid.img, &test.dialog_box.mid.bits_per_pixel, &test.dialog_box.mid.line_length, &test.dialog_box.mid.endian);
	test.dialog_box.left.img = mlx_xpm_file_to_image(test.mlx, "textures/dialog_box_left.xpm", &test.dialog_box.left.x, &test.dialog_box.left.y);
    test.dialog_box.left.addr = mlx_get_data_addr(test.dialog_box.left.img, &test.dialog_box.left.bits_per_pixel, &test.dialog_box.left.line_length, &test.dialog_box.left.endian);

	test.stats.full_heart.img = mlx_xpm_file_to_image(test.mlx, "textures/white_full_heart.xpm", &test.stats.full_heart.x, &test.stats.full_heart.y);
	test.stats.full_heart.addr = mlx_get_data_addr(test.stats.full_heart.img, &test.stats.full_heart.bits_per_pixel, &test.stats.full_heart.line_length, &test.stats.full_heart.endian);
	test.stats.empty_heart.img = mlx_xpm_file_to_image(test.mlx, "textures/white_empty_heart.xpm", &test.stats.empty_heart.x, &test.stats.empty_heart.y);
	test.stats.empty_heart.addr = mlx_get_data_addr(test.stats.empty_heart.img, &test.stats.empty_heart.bits_per_pixel, &test.stats.empty_heart.line_length, &test.stats.empty_heart.endian);
	test.stats.typeface_life.img = mlx_xpm_file_to_image(test.mlx, "textures/typeface_life_2.xpm", &test.stats.typeface_life.x, &test.stats.typeface_life.y);
	test.stats.typeface_life.addr = mlx_get_data_addr(test.stats.typeface_life.img, &test.stats.typeface_life.bits_per_pixel, &test.stats.typeface_life.line_length, &test.stats.typeface_life.endian);
	test.stats.glass.img = mlx_xpm_file_to_image(test.mlx, "textures/glass_rotated.xpm", &test.stats.glass.x, &test.stats.glass.y);
	test.stats.glass.addr = mlx_get_data_addr(test.stats.glass.img, &test.stats.glass.bits_per_pixel, &test.stats.glass.line_length, &test.stats.glass.endian);
	test.stats.step.img = mlx_xpm_file_to_image(test.mlx, "textures/shoes.xpm", &test.stats.step.x, &test.stats.step.y);
	test.stats.step.addr = mlx_get_data_addr(test.stats.step.img, &test.stats.step.bits_per_pixel, &test.stats.step.line_length, &test.stats.step.endian);

	test.all.spike.img = mlx_xpm_file_to_image(test.mlx, "textures/spike.xpm", &test.all.spike.x, &test.all.spike.y);
    test.all.spike.addr = mlx_get_data_addr(test.all.spike.img, &test.all.spike.bits_per_pixel, &test.all.spike.line_length, &test.all.spike.endian);
	mlx_hook(test.win, 2, 1L << 0, &handle_keypress, &test);
    // render(&test);
	mlx_loop_hook(test.mlx, render, &test);
    mlx_loop(test.mlx);
    return (0);
}
