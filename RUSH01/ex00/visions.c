/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 13:55:03 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/22 12:20:33 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

// Fonctions de resolution des vues.
// - Les valeures recues en arguments servent uniquement a contourner la norme car on a le droit 
// qu'a 5 variables par fonction et celle-ci en necessite 6.
// - max correspond a la hauteur maximum rencontre sur chauque ligne ou colonne.
// - index va servir pour connaitre la premiere case ou la tour n'a pas ete fixee sur la ligne ou colonne.
// - count va servir pour determiner le nombre de vues actuelles.
// - i parours les index de **views en fonction la vue traitee;
// - j parcours les colonnes ou les lignes de **tower en fonction de la vue traitee;
// - bh (pour "behind", faute de place) sert a detminer le nombres de cases derriere la tour de taille map->size
// -------------------------------------------------------------------------------------------------------------
// Toutes ces variables vont nous permettre de savoir si, pour chaque vues (une par fonction)
// , il ne reste qu'un building a voir (voir dernier if de chaque fonction). Si c'est le cas, on determine que la valeure minimume
// de la premiere case vide rencontree correspond a 
// la valeur max de sa liste de valeures (d'ou get_max) - le nombre de cases derriere le building de taille map-Size.
// J'aurais peut-etre pu faire plus simple, je sais :)

// Fixation de la vue RL (ROW LEFT), donc parcours de gauche a droite avec j
void	fix_rl_visions(t_map *map, short *max, short *index, short *count)
{
	short	i;
	short	j;
	short	bh;

	i = -1;
	while (++i < map->size)
	{
		j = -1;
		*count = 0;
		*max = 0;
		bh = 0;
		*index = -1;
		while (++j < map->size)
		{
			*max == map->size ? bh++ : 0;
			map->tower[i][j].height == 0 && *index == -1 ? *index = j : 0;
			map->tower[i][j].height > *max ? *count += 1 : 0;
			map->tower[i][j].height > *max ? *max = map->tower[i][j].height : 0;
		}
		if (*index >= 0 && map->views[RL][i] - *count == 1)
			rm_min(map, i, *index, get_max(map->tower[i][*index].list) - bh);
	}
}

// Fixation de la vu RR (ROW RIGHT), donc parcours de droite a gauche avec j
void	fix_rr_visions(t_map *map, short *max, short *index, short *count)
{
	short	i;
	short	j;
	short	bh;

	i = -1;
	while (++i < map->size)
	{
		j = map->size;
		*count = 0;
		*max = 0;
		bh = 0;
		*index = -1;
		while (--j >= 0)
		{
			*max == map->size ? bh++ : 0;
			map->tower[i][j].height == 0 && *index == -1 ? *index = j : 0;
			map->tower[i][j].height > *max ? *count += 1 : 0;
			map->tower[i][j].height > *max ? *max = map->tower[i][j].height : 0;
		}
		if (*index >= 0 && map->views[RR][i] - *count == 1)
			rm_min(map, i, *index, get_max(map->tower[i][*index].list) - bh);
	}
}

// Fixation de la vu CU (Column Up), donc parcours de haut en bas avec j
void	fix_cu_visions(t_map *map, short *max, short *index, short *count)
{
	short	i;
	short	j;
	short	bh;

	i = -1;
	while (++i < map->size)
	{
		j = -1;
		*count = 0;
		*max = 0;
		bh = 0;
		*index = -1;
		while (++j < map->size)
		{
			*max == map->size ? bh++ : 0;
			map->tower[j][i].height == 0 && *index == -1 ? *index = j : 0;
			map->tower[j][i].height > *max ? *count += 1 : 0;
			map->tower[j][i].height > *max ? *max = map->tower[j][i].height : 0;
		}
		if (*index >= 0 && map->views[CU][i] - *count == 1)
			rm_min(map, *index, i, get_max(map->tower[*index][i].list) - bh);
	}
}

// Fixation de la vu CD (Column Down), donc parcours de bas en haut avec j
void	fix_cd_visions(t_map *map, short *max, short *index, short *count)
{
	short	i;
	short	j;
	short	bh;

	i = -1;
	while (++i < map->size)
	{
		j = map->size;
		*count = 0;
		*max = 0;
		bh = 0;
		*index = -1;
		while (--j >= 0)
		{
			*max == map->size ? bh++ : 0;
			map->tower[j][i].height == 0 && *index == -1 ? *index = j : 0;
			map->tower[j][i].height > *max ? *count += 1 : 0;
			map->tower[j][i].height > *max ? *max = map->tower[j][i].height : 0;
		}
		if (*index >= 0 && map->views[CD][i] - *count == 1)
			rm_min(map, *index, i, get_max(map->tower[*index][i].list) - bh);
	}
}

// Fonction d'appel des quatres fonctions ci dessous et c'est cette fonction qui transmet certaines 
// des variables donc on a besoin dans les fix_visions, oui je sais c'est pas propre :)
void	fix_visions(t_map *map)
{
	short	max;
	short	index;
	short	count;

	fix_cu_visions(map, &max, &index, &count);
	fix_cd_visions(map, &max, &index, &count);
	fix_rl_visions(map, &max, &index, &count);
	fix_rr_visions(map, &max, &index, &count);
}
