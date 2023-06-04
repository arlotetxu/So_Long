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
# include "../libft/libft.h"

typedef struct	s_window {
	int		width_win;
	int		height_win;
	char	*title_win;
}				t_window;

//Struct to save a vector
typedef struct	s_coord{
	int		x;
	int		y;
}				t_coord;

//Struct to store the general program data
typedef struct	s_general {
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
}				t_gen_p;

// Struct to save all the data related to the images
typedef struct	s_image {
	void	*img;
	int		width_im;
	int		height_im;
}				t_image;
//put your functions here
//DEFINES TO GET THE DIFFERENT CHARACTERS TEXTURES
# define WALL "textures/bricks.xpm"
# define FREE_ "textures/grass_redim.xpm"
# define POO "textures/poo.xpm"
# define TOILET "textures/toilet.xpm"
# define EXIT "textures/exit.xpm"
//UTILS
char	**ft_map_2_array(char *map_route);
t_coord	ft_map_size(char **map);
t_coord	ft_start_posit(char **map);
int		ft_count_c(char **map);
//CHECKS
int		ft_check_maps_rectangle(char **map);
int		ft_check_map_leaks(char **map);
int		ft_check_std_elements(char **map);
int		ft_check_nostd_elements(char **map);
char	**ft_flood_fill(char **map);
void	ft_fill_map(char **map, t_coord size, t_coord start);
char	**ft_dupli_map(char **map, t_coord size);
int		ft_check_map_valid(char **map, t_coord size);
int		ft_check_map_ext(char *map_route);
//CREATING THE WINDOW & IMAGES
void	ft_so_long(t_gen_p general_p);
void	ft_paint_map(t_gen_p general_p);
void	ft_pass_image(char map_char, t_gen_p general_p, int x, int y);
void	ft_place_texture(t_gen_p general_p, char *texture, int x, int y);
//MOVEMENTS
int		ft_input_key(int key_num, t_gen_p *general);
int		ft_check_mov(int key_num, t_gen_p general);
int		ft_check_map_value(t_coord prev_coord, t_coord next_coord,
			t_gen_p general);
void	ft_do_mov(t_coord prev_coord, t_coord next_coord, t_gen_p general);
//EXIT
void	ft_exiting(char **str);
int		ft_close(t_gen_p *general);
int		ft_check_map_value(t_coord prev_coord, t_coord next_coord, t_gen_p general);
void	ft_do_mov(t_coord prev_coord, t_coord next_coord, t_gen_p general);

#endif //SO_LONG_H