/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:06:29 by llion             #+#    #+#             */
/*   Updated: 2023/05/14 12:42:52 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_player	*init_player(t_cub *c, int i, int j)
{
	t_player	*player;
	mlx_image_t	*img;

	player = ft_calloc(1, sizeof(t_player));
	player->img = mlx_new_image(c->mlx, c->tilesize, c->tilesize);
	player->x_start = i;
	player->y_start = j;
	player->ang = 0;
	return (player);
}
