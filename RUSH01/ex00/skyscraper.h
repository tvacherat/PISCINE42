/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscraper.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 18:15:17 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/22 11:44:32 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKYSCRAPER_H
# define SKYSCRAPER_H

# include <unistd.h>
# include <stdlib.h>

# define CU 0
# define CD 1
# define RL 2
# define RR 3
# define Y 1
# define N 0

// Structure t_list qui contient 
// - un tableau de valeures potentielles
// - la taille de celui-ci
typedef struct	s_list
{
	unsigned short *values;
	unsigned short size;
}				t_list;

// Structure t_tower qui contient: 
// - une hauteur (initialisee a 0 au debut du programme)
// - une hauteure potentielle (dont on s'est finalement pas servi et qu'il aurait fallu retirer...)
// - une t_list
typedef struct	s_tower
{
	unsigned short	height;
	unsigned short	tmp_height;
	t_list			*list;
}				t_tower;

// Structure t_map qui contient:
// - Une grille n * n de t_tower
// - une grille 4 * n contenant les vues recues en argument
// - la taille n de la map
typedef	struct	s_map
{
	t_tower			**tower;
	short			**views;
	unsigned short	size;
}				t_map;

short			check_args(char *str, t_map *map);
short			check_values(char *str, unsigned short count, t_map *map);
void			debug(t_map *map, short i, short j);
short			check_map(t_map *map);

void			get_max_value(t_map *map, short x, short y);
void			find_max_sizes(t_map *map);
void			look_for_lonely_value(t_map *map, short x, short y);
void			find_lonely_values(t_map *map);

short			rm_list_value(t_list *list, short value);
short			is_in_list(t_list *list, short value);
t_list			*init_list(short size_max);
short			get_max(t_list *list);

t_tower			init_tower(short size);
t_tower			**set_map(short size);
void			set_tower_height(t_map *map, short x, short y, short height);
void			rm_min(t_map *map, short x, short y, short min);
void			rm_max(t_map *map, short x, short y, short max);

short			**get_views(char *str, unsigned short size);
void			free_map(t_map *map);
void			display_map(t_map map);
short			process(t_map *map);

void			fix_rl_visions
				(t_map *map, short *max, short *index, short *count);
void			fix_rt_visions
				(t_map *map, short *max, short *index, short *count);
void			fix_cu_visions
				(t_map *map, short *max, short *index, short *count);
void			fix_cd_visions
				(t_map *map, short *max, short *index, short *count);
void			fix_visions(t_map *map);

#endif
