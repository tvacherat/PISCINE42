/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 11:46:42 by lebourre          #+#    #+#             */
/*   Updated: 2020/09/22 11:19:59 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"
// Fonction main
// - Allocation de la map
// - Check des arguments
// - Initialisation et verification de la map et de sa taille
// - Lancement de l'algorithme de recherche de solution et verification de la validite de la grille
// - Affichage de la grille resolue et liberation de la memoire allouee
int	main(int ac, char **av)
{
	t_map *map;

	if (!(map = malloc(sizeof(t_map))))
		write(1, "Error\n", 6);
	else if (ac != 2 || check_args(av[1], map) == -1)
		write(1, "Error\n", 6);
	else if (map->size != 4 || !(map->views = get_views(av[1], map->size))
		|| !(map->tower = set_map(map->size)))
		write(1, "Error\n", 6);
	else if (process(map) == N)
	{
		write(1, "Error\n", 6);
		free(map); // J'ai oublie ici d'appeler free_map au lieu de free :(((
	}
	else
	{
		display_map(*map);
		free_map(map);
	}
	return (0);
}
