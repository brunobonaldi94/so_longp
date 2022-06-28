/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:48:30 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/06/25 00:35:16 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATION_H
# define MAP_VALIDATION_H

# define MAP_EMPTY_SPACE_CHAR '0'
# define MAP_WALL_CHAR '1'
# define MAP_COLLECTIBLE_CHAR 'C'
# define MAP_EXIT_CHAR 'E'
# define MAP_PLAYER_CHAR 'P'

typedef struct s_map_dimensions
{
	int		rows;
	int 	columns;
	char	**map_matrix;
}	t_map_dimensions;

typedef struct s_valid_components
{
	int					has_exit;
	int					has_collectible;
	int					has_player_starting_position;
	int					has_valid_char;
	int					has_minimal_components;
	t_map_dimensions	map_dimensions;
	int					is_rect;
	int					is_surrounded_by_wall;
	int					is_valid_map;
}	t_valid_components;

int		read_map(char *file_path);
void	init_map_components(t_valid_components *map_components);
int		is_valid_map_component(int component);
int		is_valid_component(int component);

int		check_is_valid_map(t_valid_components *map_components);
void	check_map_validators(t_valid_components *map_components,
			char *map_line, int is_eof);
void	check_is_surrounded_by_wall(t_valid_components *map_components,
			t_map_dimensions current_map_dimensions, char component);
void	check_is_rectangule(t_valid_components *map_components,
			t_map_dimensions current_map_dimensions, int is_eof);
void	check_minimal_components(t_valid_components *map_components,
			char component);
#endif //MAP_VALIDATION_H