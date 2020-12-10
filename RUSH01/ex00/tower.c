/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tower.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 15:54:08 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/22 11:58:30 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

// Fonction qui va retirer toutes les valeures inferieures au parametre min d'une t_list de la tour au coordonnes x et y
// - Si la taille de la tour a deja ete determinee, on quitte la fonction
// - Tant que le min de fait pas partie de la list, on l'augmente
// - On supprime toutes les valeures de la liste inferieures a min et si rm_list_value renvoie Y, c'est que lq liste est de taille 1,
// dance ce cas lq on fixe la taille de la tour au coordonnes x et y recues en parametre
void	rm_min(t_map *map, short x, short y, short min)
{
	short i;

	i = 1;
	if (map->tower[x][y].height != 0)
		return ;
	while (min < map->size && is_in_list(map->tower[x][y].list, min) == N)
		min++;
	while (i < min)
	{
		if (rm_list_value(map->tower[x][y].list, i) == Y)
			set_tower_height(map, x, y, map->tower[x][y].list->values[0]);
		i++;
	}
}

// Meme chose que rm_min mais pour les valeures max.
// Tant que max ne fait pas partie de la liste, on le diminue
void	rm_max(t_map *map, short x, short y, short max)
{
	short i;

	if (map->tower[x][y].height != 0)
		return ;
	while (max > 1 && is_in_list(map->tower[x][y].list, max) == N)
		max--;
	i = max + 1;
	while (i <= map->size)
	{
		if (rm_list_value(map->tower[x][y].list, i) == Y)
			set_tower_height(map, x, y, map->tower[x][y].list->values[0]);
		i++;
	}
}

// Fonction d'initialisation des t_tower
t_tower	init_tower(short size)
{
	t_tower	tower;

	tower.height = 0;
	tower.tmp_height = 0;
	tower.list = init_list(size);
	return (tower);
}

// Fonction d'allocation et d'initialisation de la map
t_tower	**set_map(short size)
{
	short	i;
	short	j;
	t_tower	**map;

	i = -1;
	if (!(map = malloc(sizeof(t_tower *) * size)))
		return (0);
	while (++i < size)
	{
		if (!(map[i] = malloc(sizeof(t_tower) * size)))
		{
			free(map);
			return (0);
		}
	}
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			map[i][j] = init_tower(size);
	}
	return (map);
}

// Fonction de fixation de la taille de la tour aux coordonnes x et y recues en parametre.
// - Si la taille de la tour a deja ete fixee ou si la valeur que l'on veut fixer 
// n'existe pas dans la liste, on quitte la fonction
// - On fixe la taille de la tour a la valeur height recue en parametre
// - on fixe la taille de la list a 0;
// - On parcours les lignes et colonnes afin de supprimer height des listes de la ligne et de la la colonne
// - Si rm_list_value retourne Y, alors on fixe la taille de la tour.
void	set_tower_height(t_map *map, short x, short y, short height)
{
	short	i;

	i = 0;
	if (map->tower[x][y].height != 0
		|| is_in_list(map->tower[x][y].list, height) == N)
		return ;
	map->tower[x][y].height = height;
	map->tower[x][y].list->size = 0;
	while (i < map->size)
	{
		if (rm_list_value(map->tower[i][y].list, height) == Y)
			set_tower_height(map, i, y, map->tower[i][y].list->values[0]);
		if (rm_list_value(map->tower[x][i].list, height) == Y)
			set_tower_height(map, x, i, map->tower[i][y].list->values[0]);
		i++;
	}
}
