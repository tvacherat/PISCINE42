/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 12:50:46 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/22 11:24:15 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

// Fonction d'affichage de la grille
void	display_map(t_map map)
{
	unsigned short	i;
	unsigned short	j;
	char			c;

	i = 0;
	while (i < map.size)
	{
		j = 0;
		while (j < map.size)
		{
			c = map.tower[i][j].height + 48;
			write(1, &c, 1);
			j != map.size - 1 ? write(1, " ", 1) : 0;
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

// Lancement de la procedure de recherche de solution
// - Recherche des valeures max
// - Recheche de valeures isolees sur les lignes ou colonnes
// - Fix_visions sera detaille dans son fichier
// - Si check_map retourne N, la grille est invalide
short	process(t_map *map)
{
	short	i;

	i = 0;
	find_max_sizes(map);
	find_lonely_values(map);
	while (i < map->size)
	{
		fix_visions(map);
		find_lonely_values(map);
		i++;
	}
	if (check_map(map) == N)
		return (N);
	return (Y);
}

// - Fonction de liberation de la memoire allouee
void	free_map(t_map *map)
{
	short	i;

	i = 0;
	while (i < map->size)
	{
		// J'ai oublie de free les list->values :((((
		free(map->tower[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		free(map->views[i]);
		i++;
	}
	free(map->views);
	free(map->tower);
	free(map);
}

short	**get_views(char *str, unsigned short size)
{
	static short	i = -1;
	static short	j = 0;
	static short	k = 0;
	short			**views;

	if (!(views = malloc(sizeof(short *) * 4)))
		return (0);
	while (++i < 4)
	{
		if (!(views[i] = malloc(sizeof(short) * size)))
			return (0);
	}
	i = -1;
	while (str[++i])
	{
		if (str[i] > 47 && str[i] < 58)
		{
			views[j][k] = str[i] - 48;
			k++;
			k == size ? j++ : 0;
			k == size ? k = 0 : 0;
		}
	}
	return (views);
}
