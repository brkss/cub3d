/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:30:49 by bberkass          #+#    #+#             */
/*   Updated: 2022/12/16 20:32:40 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "header.h"
# include "./libft.h"

# define WEST_TEXTURE 1
# define EAST_TEXTURE 2
# define SOUTH_TEXTURE 3
# define NORTH_TEXTURE 4
# define FLOOR_COLOR 5
# define CEILLING_COLOR 6
# define EMPTY_LINE -1

typedef struct s_mapdata
{
	int		*ceilling_color;
	int		*floor_color;
	char	*north_tx;
	char	*west_tx;
	char	*east_tx;
	char	*south_tx;
	char	**map;
	int		player_x;
	int		player_y;

}	t_mapdata;

void		free_doubles(char **str);
int			check_color_range(int color);
int			arr_len(char **arr);
int			check_color_format(char *color);
void		__init_mapdata(t_mapdata *data);

int			is_color(char *line);
int			is_texture(char *line);
int			is_map_info(char *line);
int			got_all_data(t_mapdata *data);
void		assign_colors(int *res, char **colors);

int			ft_arrlen(char **map);
int			is_player(char c);
int			is_tile(char c);

int			check_args(int ac, char **av);
char		*get_next_line(int fd);
t_list		*read_map(char *filename);
int			check_extension(char *filename);
t_mapdata	*scan_scene(t_list *head);
char		**convert_map(t_list *map_chain);
int			check_map(t_mapdata *data);

#endif
