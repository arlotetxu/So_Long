//
// Created by Jose Manuel Florido Perena on 6/2/23.
//
#include "../inc/so_long.h"

void	ft_do_mov(t_coord prev_coord, t_coord next_coord, t_gen_p general)
{
	general.map[prev_coord.y][prev_coord.x] = '0';
	general.map[next_coord.y][next_coord.x] = 'P';
	ft_paint_map(general);
}

int	ft_check_map_value(t_coord prev_coord, t_coord next_coord, t_gen_p general)
{
	char	map_value;

	map_value = general.map[next_coord.y][next_coord.x];
	if (map_value == '0' || map_value == 'c' || map_value == 'C')
	{
		ft_do_mov(prev_coord, next_coord, general);
		return (1);
	}
	else if ((map_value == 'e' || map_value == 'E') && ft_count_c(general.map) == 0)
		ft_close(&general);
	return (0);
}

int	ft_check_mov(int key_num, t_gen_p general)
{
	t_coord	start_p;
	t_coord	next_p;
	int		check_print;

	start_p = ft_start_posit(general.map);
	next_p = start_p;
	check_print = 0;
	if (key_num == 123)
		next_p.x = next_p.x - 1;
	else if (key_num == 124)
		next_p.x = next_p.x + 1;
	else if (key_num == 125)
		next_p.y = next_p.y + 1;
	else if (key_num == 126)
		next_p.y = next_p.y - 1;
	check_print = ft_check_map_value(start_p, next_p, general);
	return (check_print);
}

int	ft_input_key(int key_num, t_gen_p *general)
{
	int			check_move;
	static int	count;

	if (!count)
		count = 0;
	check_move = 0;
	if (key_num == 53 || key_num == 123 || key_num == 124
		|| key_num == 125 || key_num == 126)
	{
		if (key_num == 53)
			ft_close(general);
		else if (key_num == 123)
			check_move = ft_check_mov(key_num, *general);
		else if (key_num == 124)
			check_move = ft_check_mov(key_num, *general);
		else if (key_num == 125)
			check_move = ft_check_mov(key_num, *general);
		else if (key_num == 126)
			check_move = ft_check_mov(key_num, *general);
		if (check_move == 1)
			count++;
		printf("Num_mov: %d -- Key: %d\n", count, key_num); //TODO no permitido el printf
	}
	return (0);
}
