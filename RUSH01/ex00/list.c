/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 15:55:32 by lebourre          #+#    #+#             */
/*   Updated: 2020/09/22 11:15:37 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

// Fonction booleenne qui va restirer une valeur dans une t_list:
// - On verifie que cette valeur se trouve bien dans la liste et que celle-ci a une taille > 0
// - On alterne l'element que l'on veut sortir de la liste avec le dernier element de celle-ci
// - On reduit la taille de la liste de 1 ce qui va "ejecter" l'element que l'on a voulu retirer
// - Si la taille de la liste est de 1, on retourne Y afin de placer la tour restante dans la fonction precedente.
short	rm_list_value(t_list *list, short value)
{
	short i;
	short tmp;

	if (list->size == 0 || is_in_list(list, value) == N)
		return (N);
	else if (list->values[list->size - 1] != value)
	{
		tmp = list->values[list->size - 1];
		list->values[list->size - 1] = value;
		i = 0;
		while (i < list->size)
		{
			if (list->values[i] == value)
				list->values[i] = tmp;
			i++;
		}
	}
	list->size -= 1;
	if (list->size == 1)
		return (Y);
	return (N);
}

// Fonction booleenne qui determine si la valeur envoyee en parametre est contenue dans 
// la liste envoyee en parametre
short	is_in_list(t_list *list, short value)
{
	short i;

	i = 0;
	while (i < list->size)
	{
		if (list->values[i] == value)
			return (Y);
		i++;
	}
	return (N);
}

// Fonction d'initialisation d'une t_list
// On remplie la liste avec les valeur allant de 1 a la taille de la grille
t_list	*init_list(short size_max)
{
	t_list	*list;
	short	i;

	i = 0;
	if (!(list = malloc(sizeof(t_list))))
		return (0);
	if (!(list->values = malloc(sizeof(short) * size_max)))
		return (0);
	while (i < size_max)
	{
		list->values[i] = i + 1;
		i++;
	}
	list->size = size_max;
	return (list);
}

// fonction qui retourne la valeur maximum contenue dans la t_list emvoyee en parametre
short	get_max(t_list *list)
{
	short	i;
	short	max;

	i = 0;
	max = 0;
	while (i < list->size)
	{
		max < list->values[i] ? max = list->values[i] : 0;
		i++;
	}
	return (max);
}
