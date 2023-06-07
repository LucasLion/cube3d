/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:43:09 by llion             #+#    #+#             */
/*   Updated: 2023/06/07 11:11:41 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_square(t_cub *c, int x, int y, long int color)
{
	int	i;
	int	j;
	mlx_image_t	*img;

	i = 0;
	img = mlx_new_image(c->mlx, c->tilesize_2d, c->tilesize_2d);
	
	while (i < c->tilesize_2d)
	{
		j = 0;
		while (j < c->tilesize_2d)
		{
			mlx_put_pixel(img, i, j, color); 
			j++;
		}
		i++;
	}
	if (!img || (mlx_image_to_window(c->mlx, img, y * c->tilesize_2d + 50 , x * c->tilesize_2d + 50 ))< 0)
		return ;
	img->instances[0].z = 1;
}

void	put_square_big(t_cub *c, int x, int y, long int color)
{
	int	i;
	int	j;
	mlx_image_t	*img;

	i = 0;
	img = mlx_new_image(c->mlx, c->tilesize, c->tilesize);
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
	if (!img || (mlx_image_to_window(c->mlx, img, y * c->tilesize , x * c->tilesize ))< 0)
		return ;
	img->instances[0].z = 1;
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
				{
					c->player->m_pos.x = i;
					c->player->m_pos.y = j;
				}
			}
			else if (c->map[i][j] == '1' )
				put_square(c, i, j, 0x000000ff);
			else if (c->map[i][j] == '2')
				put_square(c, i, j, 0xff0000ff);
			j++;
		}
		i++;
	}
	return (1);
}

