/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 18:19:31 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/22 11:40:34 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

// Fonction de recheche des valeures isolees sur les lignes et colonnes:
// - Pour chaques valeures de la liste de la tour aux coordonnees x et y envoyees en parametre
// , on verifie qu'elles ne sont pas les seules sur la ligne ou colonne,
// sinon on fixe la taille de la tour avec cette taille.
void	look_for_lonely_value(t_map *map, short x, short y)
{
	short	i;
	short	j;
	short	in_column;
	short	in_row;

	i = -1;
	while (++i < map->tower[x][y].list->size)
	{
		j = -1;
		in_column = 0;
		in_row = 0;
		while (++j < map->size && in_column == 0)
			if (is_in_list(map->tower[j][y].list
			, map->tower[x][y].list->values[i]) == Y && j != x)
				in_column = 1;
		j = -1;
		while (++j < map->size && in_row == 0)
			if (is_in_list(map->tower[x][j].list
			, map->tower[x][y].list->values[i]) == Y && j != y)
				in_row = 1;
		if (in_row == 0 || in_column == 0)
			return (set_tower_height(map, x, y,
				map->tower[x][y].list->values[i]));
	}
}

// Fonction de determination des valeures max pour la tour aux coordonnes x et y envoyees en parametre
void	get_max_value(t_map *map, short x, short y)
{
	short max_cu;
	short max_cd;
	short max_rl;
	short max_rr;

	max_cu = map->size - map->views[CU][y] + x + 1;
	max_cd = map->size - map->views[CD][y] + (map->size - x);
	max_rl = map->size - map->views[RL][x] + y + 1;
	max_rr = map->size - map->views[RR][x] + (map->size - y);
	if (max_cu <= max_cd && max_cu <= max_rl && max_cu <= max_rr)
		rm_max(map, x, y, max_cu);
	else if (max_cd <= max_cu && max_cd <= max_rl && max_cd <= max_rr)
		rm_max(map, x, y, max_cd);
	else if (max_rl <= max_cu && max_rl <= max_cd && max_rl <= max_rr)
		rm_max(map, x, y, max_rl);
	else
		rm_max(map, x, y, max_rr);
}

// Fonction de parcours de la map afin de determiner les valeures max pour chaque tour.
// Appel de get_max_values (juste au dessus) pour chaque element de la map
void	find_max_sizes(t_map *map)
{
	short	i;
	short	j;

	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			get_max_value(map, i, j);
			j++;
		}
		i++;
	}
}

// Fonction de parcoursde la map afin de determiner les valeures isolees pour chaque tour.
// Appel de find_lonely_values (juste au dessus) pour chaque element de la map.
// On repete ceci autant de fois que la taille de la map car la fixation d'une taille peut
// entrainer l'isolation d'une valeure dans une case testee juste avant..
void	find_lonely_values(t_map *map)
{
	short	i;
	short	j;
	short	k;

	k = 0;
	while (k < map->size)
	{
		i = 0;
		while (i < map->size)
		{
			j = 0;
			while (j < map->size)
			{
				look_for_lonely_value(map, i, j);
				j++;
			}
			i++;
		}
		k++;
	}
}
