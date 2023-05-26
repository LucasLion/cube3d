/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:43:09 by llion             #+#    #+#             */
/*   Updated: 2023/05/26 14:36:09 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_square(t_cub *c, int x, int y, long int color)
{
	int	i;
	int	j;
	mlx_image_t	*img;

	i = 0;
	img = mlx_new_image(c->mlx, c->tilesize_H_2d, c->tilesize_V_2d);
	
	
	while (i < c->tilesize_H_2d - 1)
	{
		j = 0;
		while (j < c->tilesize_V_2d - 1)
		{
	git 		mlx_put_pixel(img, i, j, color); 
			j++;
		}
		i++;
	}
	if (!img || (mlx_image_to_window(c->mlx, img, 80 + y * c->tilesize_H_2d , 80 + x * c->tilesize_V_2d < 0)))
		return ;
	img->instances[0].z = 1;
}

int	display_2d_map(t_cub *c)
{
	int			i;
	int 		j;
	int cases = 0; // a enlenver

	i = 0;
	while (c->map[i])
	{
		j = 0;
		while (c->map[i][j])
		{
			if (c->map[i][j] == '0' || c->map[i][j] == 'W' || c->map[i][j] == 'E' \
				|| c->map[i][j] == 'S' || c->map[i][j] == 'N')
			{
				put_square(c, i, j, 0xffffff55);
				if (c->map[i][j] != '0')
				{
					c->player->m_pos.x = i;
					c->player->m_pos.y = j;
				}
				cases++;
				printf("case %d\n", cases);
			}
			else if (c->map[i][j] == '1')
			{
				put_square(c, i, j, 0x00000055);
				cases++;
				printf("case %d\n", cases);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	draw_ceiling(t_cub *c, t_point start, t_point end)
{
	t_point sta_ceil;
	t_point end_ceil;
	long unsigned int	color;
	color = 0xfffffff;

	sta_ceil.y = 0;
	sta_ceil.x = start.x;
	end_ceil.y = start.y;
	end_ceil.x = start.x;
	draw_one_line(c, c->img3d, sta_ceil, end_ceil, color);
}

void	draw_floor(t_cub *c, t_point start, t_point end)
{
	t_point sta_floor;
	t_point end_floor;
	long unsigned int	color;
	color = 0xffffffff;

	sta_floor.y = end.y;
	sta_floor.x = start.x;
	end_floor.y = SCREEN_HEIGHT;
	end_floor.x = start.x;
	draw_one_line(c, c->img3d, sta_floor, end_floor, color);
}

int	display_3d_map(t_cub *c)
{
	int					i;
	int					j;
	int					line_height;
	t_point				start;
	t_point				end;

	start.x = 0;
	i = c->view_ang - 1;
	if (c->img3d)
		mlx_delete_image(c->mlx, c->img3d);
	c->img3d = mlx_new_image(c->mlx, SCREEN_WIDTH , SCREEN_HEIGHT);
	if (!c->img3d || (mlx_image_to_window(c->mlx, c->img3d, 0, 0) < 0))
		return 0;
	c->img3d->instances[0].z = 0;
	while(i >= 0)
	{
		j = 0;
		while(j <= SCREEN_WIDTH / c->view_ang)
		{
			float ratio = 0.2; //valeur aui doit dependre de la taille de la map
			//line_height = SCREEN_WIDTH / c->rays_len[i] * (c->map_height * ratio);
			line_height = SCREEN_HEIGHT / c->rays_len[i] * c->tilesize_V * 8;
			start.y = ((SCREEN_HEIGHT) - line_height) / 2;
			end.x = start.x;
			end.y = line_height + start.y;
			draw_one_line(c, c->img3d, start, end, c->color_tab[i]);
			draw_ceiling(c, start, end);
			draw_floor(c, start, end);
			j++;
			start.x++;
		}
		i--;
	}
	return (1);
}
