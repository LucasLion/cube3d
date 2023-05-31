/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 03:15:02 by llion             #+#    #+#             */
/*   Updated: 2023/05/31 12:10:50 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "../libft/include/libft.h"
#include "../include/MLX42.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "MLX42.h"

#define PI 3.14159
#define DEFINITION 8
#define FOV 20
#define DEPTH 1
#define SCREEN_HEIGHT 1080
#define SCREEN_WIDTH 1960
#define SPEED 8
#define OFFSET_MAP_2D 80

//#include "MLX42_Int.h"
//#include "MLX42_input.h"

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_rays
{
	float 				ang;
	double				len;
	t_point				wall;
	char				dir;
	long unsigned int	color;	
}				t_rays;


typedef struct	s_textures
{
	char			*NO;
	char			*SO;
	char			*WE;
	char			*EA;
	unsigned long	floor;
	unsigned long	ceiling;
	int		nb_elems;
}				t_textures;

typedef struct	s_player
{
	t_point		p_pos;
	t_point		m_pos;
	float		player_x_dif;
	float		player_y_dif;
	int			is_moving;
	float		ang;
	float		speed;

}				t_player;

typedef struct	s_cub
{
	int					screen_width;
	int					screen_height;
	int					map_width;
	int					map_height;
	int					tilesize_H;
	int					tilesize_H_2d;
	int					tilesize_V;
	int					tilesize_V_2d;
	int					view_ang;
	mlx_t				*mlx;
	char				**map;
	long unsigned int	color;
	t_textures			*t;	
	int					nb_line_map_start;
	t_player			*player;
	mlx_image_t			*img2d;
	mlx_image_t			*img3d;
	mlx_texture_t		**textures;
	t_rays				*rays;
	
}				t_cub;

int				ft_error(char *str);
int				get_nb_lines_in_map_file(int fd, char **argv);
int				get_nb_line_map_start(char **f, t_cub *c);
char			**get_file(char **argv);
char			**get_description(char **map);
char			**get_map(char **file, int i);
uint32_t		rgb_to_hexa(uint8_t red, uint8_t green, uint8_t blue, uint8_t transp);
t_textures		*get_textures(char **file);

/* ----------- PARSING ----------- */

int		parse_infos(char **infos, t_cub *c);
int		parse_elems_in_map(char **map);
int		parsing(char **file, t_cub *c);
int		parse_borders(char **map);
int		parse_number_players(char **map);
int		parse_file(int argc, char **argv);


/* ----------- DISPLAY ----------- */

void		put_square(t_cub *c, int x, int y, long int color);
int			display_2d_map(t_cub *c);
int			display_3d_map(t_cub *c);
t_player	*init_player(t_cub *c);

/* ----------- MOVEMENT ----------- */

void		move_player(mlx_key_data_t keydata, void *param);
void		check_movement(t_player *c);
void		ft_hook(void *param);
int			player_out(t_cub *c);


/* ----------- LINE----------- */

void 		draw_line(t_cub *c, int x, int y);
void 		draw_one_line(t_cub *cub, mlx_image_t *image, t_point start, t_point end, long unsigned int c);
void 		draw_one_line_3d(mlx_image_t *image, t_point start, t_point end);
int			wall_or_empty(t_cub *c, int x , int y);
void 		draw_rays(t_cub *c);

/* ----------- FIND PIXEL ----------- */

unsigned long int find_color_pixel(t_cub *c, int i, int l_h, int p);
unsigned long get_color_pixel(mlx_texture_t *texture, int x_texture, int y_texture);
unsigned long int get_color_v2(mlx_texture_t *t, int pixel );
unsigned long int get_pixel_north(t_cub *c, int i, int l_h, int p);

#endif
