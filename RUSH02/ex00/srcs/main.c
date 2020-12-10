/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 09:03:30 by mviala            #+#    #+#             */
/*   Updated: 2020/09/27 23:15:59 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush_02.h"

int	main(int argc, char **argv)
{
	t_file	file;
	char	*nbr;

	file = init_file(argc, argv);
	if (argc > 3 || (argc == 2 && check_nbr(argv[1]) == FALSE)
		|| (argc == 3 && check_nbr(argv[2]) == FALSE))
		write(1, "Error\n", 6);
	else if (check_file(&file) == FALSE)
	{
		file.must_free == TRUE ? free(file.buff) : 0;
		write(1, "Error\n", 6);
	}
	else if (argc == 1)
	{
		if (!(nbr = get_nbr_stdin()))
			write(1, "Error\n", 6);
		else if (process(&file, nbr) == FALSE)
			write(1, "Dict Error\n", 11);
		free(nbr);
	}
	else if (process(&file, argc == 3 ? get_nbr(argv[2]) : get_nbr(argv[1]))
		== FALSE)
		write(1, "Dict Error\n", 11);
	return (0);
}
