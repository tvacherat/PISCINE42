/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:44:33 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/12 17:16:01 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	unsigned int	i;

	i = 0;
	if (argc)
	{
		while (argv[0][i])
			i++;
	}
	write(1, argv[0], i);
	write(1, "\n", 1);
	return (0);
}
