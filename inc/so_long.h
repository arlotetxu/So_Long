//
// Created by Jose Manuel Florido Pereña on 1/4/23.
//

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../Get_Next_line/get_next_line.h"

typedef struct	s_window {
	int		width_win;
	int		height_win;
	char	*title_win;
}				t_window;

//Estructura para guardar coordenadas
typedef struct	s_coord{
	int		x;
	int		y;
}				t_coord;

typedef struct	s_image {
	void	*img;
//	char	*addr;
//	int		bits_per_pixel;
//	int		line_length;
//	int		endian;
	int		width_im;
	int		height_im;
}				t_image;
//put your functions here
//UTILS
char	**ft_map_2_array(char *map_route);
t_coord	ft_map_size(char **map);
int		ft_map_rows(char **map);
int		ft_map_columns(char **map);
t_coord	ft_start_posit(char **map);
//CHECKS
int		ft_check_maps_rectangle(char **map);
int		ft_check_map_leaks(char **map);
int		ft_check_std_elements(char **map);
int		ft_check_nostd_elements(char **map);
char	**ft_flood_fill(char **map);
void	ft_fill_map(char **map, t_coord size, t_coord start);
char	**ft_dupli_map(char **map, t_coord size);
int		ft_check_map_valid(char **map, t_coord size);

//EXIT
void	ft_exiting(char **str);
void	ft_error_exit(void);

#endif //SO_LONG_H