/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:43:09 by llion             #+#    #+#             */
/*   Updated: 2023/05/23 12:27:08 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_square(t_cub *c, int x, int y, long int color)
{
	int	i;
	int	j;
	mlx_image_t	*img;

	i = 0;
	img = mlx_new_image(c->mlx, c->tilesize, c->tilesize);
	if (!img || (mlx_image_to_window(c->mlx, img, y * c->tilesize, x * c->tilesize) < 0))
		return ;
	while (i < c->tilesize - 1)
	{
		j = 0;
		while (j < c->tilesize - 1)
		{
			mlx_put_pixel(img, i, j, color); 
			j++;
		}
		i++;
	}
}

int	display_2d_map(t_cub *c)
{
	int			i;
	int 		j;

	i = 0;
	while (c->map[i])
	{
		j = 0;
		while (c->map[i][j])
		{
			if (c->map[i][j] == '0' || c->map[i][j] == 'W' || c->map[i][j] == 'E' \
				|| c->map[i][j] == 'S' || c->map[i][j] == 'N')
			{
				put_square(c, i, j, 0xffffffff);
				if (c->map[i][j] != '0')
					c->player = init_player(c, i, j);
			}
			else if (c->map[i][j] == '1')
				put_square(c, i, j, 0x000000ff);
			j++;
		}
		i++;
	}
	return (1);
}

int	display_3d_map(t_cub *c)
{
	int			i;
	int			j;
	int			line_height;
	t_point		start;
	t_point		end;

	start.y = c->map_height;
	start.x = 0;
	i = 0;
	j = 0;
	while(i < c->view_ang)
	{
		j = 0;
		while(j < c->map_width / c->view_ang * c->tilesize)
		{
			line_height = c->map_height * c->map_width / c->rays_len[i] * c->screen_height;
			if (line_height > c->map_height )
				line_height = c->map_height;
			printf("lineH : %d", line_height);
			printf("map height %d et map wodth %d", c->map_height, c->map_width);
			end.x = start.x;
			end.y = start.y + line_height;
			draw_one_line_3d(c->img, start, end);
			j++;
		}
		start.x += c->map_width / c->view_ang * c->tilesize;
		i++;
	}
	return (1);
}

int	display(t_cub *c)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	display_2d_map(c);
	return (1);
}
