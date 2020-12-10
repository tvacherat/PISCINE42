/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 19:11:09 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/22 15:55:43 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_hexdump.h"

void	read_input(unsigned short opt)
{
	char					c;
	static unsigned long	count = 0;
	static unsigned short	index = 0;
	static char				actu[17] = {0};

	while (read(0, &c, 1))
	{
		actu[index] = c;
		index++;
		if (index == 16)
		{
			disp_line(count, actu, opt, 16);
			index = 0;
			count += 16;
		}
	}
	actu[index] = 0;
	index > 0 ? disp_line(count, actu, opt, index) : 0;
	count += index;
	count > 0 ? display_count(count, opt) : 0;
}

void	manage(t_file file, unsigned long *count, unsigned short last
		, unsigned short opt)
{
	unsigned int			i_file;
	static unsigned short	i_actu = 0;
	static char				actu[17] = {0};

	i_file = 0;
	if (last == TRUE)
	{
		i_actu > 0 ? disp_line(*count, actu, opt, i_actu) : 0;
		*count += i_actu;
		i_actu = 0;
		return ;
	}
	while (i_file < file.bytes)
	{
		fill_actu(file, actu, &i_file, &i_actu);
		if (i_actu == 16)
		{
			disp_line(*count, actu, opt, i_actu);
			*count += 16;
			actu[0] = 0;
			i_actu = 0;
		}
	}
}

void	start(t_file *list, int nb_files, char *prog_name, unsigned short opt)
{
	static unsigned long	count = 0;
	static int				i = -1;

	while (++i < nb_files)
	{
		if (list[i].fd < 0)
			display_error(list[i], prog_name);
		else
		{
			while ((list[i].bytes = read(list[i].fd, list[i].stream
				, BUFF_SIZE)))
			{
				if (list[i].bytes == -1)
				{
					display_r_error(list[i].filename, prog_name);
					break ;
				}
				manage(list[i], &count, FALSE, opt);
			}
		}
	}
	manage(list[0], &count, TRUE, opt);
	count > 0 ? display_count(count, opt) : 0;
}

int		main(int argc, char **argv)
{
	t_file			*file_list;
	unsigned short	opt;
	unsigned int	size;

	if (argc == 1 || (argc == 2 && ft_strcmp(argv[1], "-C") == 0))
	{
		read_input(argc == 2 ? 1 : 0);
		return (0);
	}
	opt = ft_strcmp(argv[1], "-C") != 0 ? 0 : 1;
	size = opt == 1 ? argc - 2 : argc - 1;
	file_list = get_file_list(size, argv, opt);
	if (check_args(file_list, size, argv[0]) == TRUE)
		start(file_list, size, argv[0], opt);
	free_file_list(size, file_list);
	return (0);
}
