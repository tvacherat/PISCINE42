/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 09:05:49 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/22 15:11:15 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tail.h"

int	main(int argc, char **argv)
{
	unsigned long	size;
	t_file			*list;
	unsigned short	arg;
	char			*prog_name;

	if (argc == 1 || (argc == 2 && is_number(argv[1] + 2) == TRUE)
		|| (argc == 3 && is_number(argv[2]) == TRUE))
	{
		print_stdin(get_size(argc == 2 ? argv[1] + 2 : argv[2]));
		return (0);
	}
	else if (check_args(argc, argv) == FALSE)
		return (0);
	else
	{
		arg = ft_strlen(argv[1]) == 2 ? 3 : 2;
		size = get_size(ft_strlen(argv[1]) == 2 ? argv[2] : argv[1] + 2);
		list = get_file_list(argc - arg, argv, arg);
		prog_name = ft_strcpy(basename(argv[0]));
		start(list, argc - arg, size, prog_name);
		free_file_list(list, argc - arg);
		free(prog_name);
	}
	return (0);
}
