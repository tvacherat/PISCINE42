/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 18:13:16 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/22 11:01:23 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"


// Fonction booleenne qui, en fin de programme, parcours la map et determine si celle-ci est valide ou si il reste des cases a remplir
// dans certains cas rares.
short	check_map(t_map *map)
{
	short	i;
	short	j;

	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			if (map->tower[i][j].list->size > 2)
				return (N);
			else if (map->tower[i][j].height == 0)
			{
				debug(map, i, j);
				find_lonely_values(map);
			}
			j++;
		}
		i++;
	}
	return (Y);
}

// Fonction booleenne qui, en debut de programme, va verifier la conformite des caracteres envoyes en arguments
// et va verifier si la taille de de la map est bien de 4 * 4
short	check_values(char *str, unsigned short count, t_map *map)
{
	unsigned short i;

	if (count != 16)
		return (-1);
	map->size = count / 4;
	i = 0;
	while (str[i])
	{
		if (str[i] != 32 && (str[i] - 48 < 1 || str[i] - 48 > map->size))
			return (-1);
		i++;
	}
	return (0);
}

// Fonction qui, en debut de programme, va verifier la conformite des caracteres et le bon placement des espaces.
short	check_args(char *str, t_map *map)
{
	unsigned short i;
	unsigned short count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((str[i] < 48 || str[i] > 57) && str[i] != 32)
			return (-1);
		else if (str[i] != 32)
		{
			if (str[i + 1] != 32 && str[i + 1] != 0)
				return (-1);
			count++;
		}
		else if (i == 0 || str[i + 1] == 32 || str[i + 1] == 0)
			return (-1);
		i++;
	}
	if (check_values(str, count, map) == -1)
		return (-1);
	return (0);
}

// Fonction de fin de programme qui va resoudre les cas non geres par l'algorithme de resolution.
void	debug(t_map *map, short i, short j)
{
	i == 0 && map->tower[0][3].height == 4
		? set_tower_height(map, i, j, 3) : 0;
	i == 3 && map->tower[0][0].height == 4
		? set_tower_height(map, i, j, 3) : 0;
	j == 0 && map->tower[3][0].height == 4
		? set_tower_height(map, i, j, 3) : 0;
	j == 3 && map->tower[0][0].height == 4
		? set_tower_height(map, i, j, 3) : 0;
}
