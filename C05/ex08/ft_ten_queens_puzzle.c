/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 14:55:24 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/13 16:43:08 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define SIZE 10

int		reset(int (*chessboard)[SIZE][SIZE], int *count, int *k)
{
	int				new_count;
	unsigned int	i;
	unsigned int	j;

	new_count = *count;
	i = 0;
	*count = 0;
	*k = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			(*chessboard)[i][j] = 0;
			j++;
		}
		i++;
	}
	return (new_count);
}

void	display(int chessboard[SIZE][SIZE], int *count)
{
	int		i;
	int		j;
	char	c;

	j = -1;
	*count += 1;
	while (++j < SIZE)
	{
		i = -1;
		while (++i < SIZE)
		{
			c = i + 48;
			if (chessboard[i][j] == 1)
				write(1, &c, 1);
		}
	}
	write(1, "\n", 1);
}

void	update_chessboard(int (*chessboard)[SIZE][SIZE], int x, int y)
{
	int	k;

	k = 0;
	while (k < SIZE)
	{
		(*chessboard)[x][k] != -2 ? (*chessboard)[x][k] = -1 : 0;
		(*chessboard)[k][y] != -2 ? (*chessboard)[k][y] = -1 : 0;
		if (y - x + k < SIZE && y - x + k >= 0
			&& (*chessboard)[k][y - x + k] != -2)
			(*chessboard)[k][y - x + k] = -1;
		if (y + x - k < SIZE && y + x - k >= 0
			&& (*chessboard)[y + x - k][k] != -2)
			(*chessboard)[y + x - k][k] = -1;
		k++;
	}
	(*chessboard)[x][y] = 1;
}

void	back_track(int (*chessboard)[SIZE][SIZE], int x, int y)
{
	int	i;
	int	j;

	j = -1;
	while (--x >= 0)
		(*chessboard)[x][y] == 1 ? (*chessboard)[x][y] = -2 : 0;
	while (++j < SIZE)
	{
		i = -1;
		while (++i < SIZE)
			(*chessboard)[i][j] == -1 ? (*chessboard)[i][j] = 0 : 0;
	}
	j = -1;
	while (++j < SIZE)
	{
		i = -1;
		while (++i < SIZE)
		{
			(*chessboard)[i][j] == 1 ? update_chessboard(chessboard, i, j) : 0;
			j > y && (*chessboard)[i][j] == -2 ? (*chessboard)[i][j] = 0 : 0;
		}
	}
}

int		ft_ten_queens_puzzle(void)
{
	static int	chessboard[SIZE][SIZE] = {0};
	static int	count = 0;
	static int	x = 0;
	int			y;

	y = 0;
	while (chessboard[y][x] != 0 && y < SIZE && x < SIZE)
		y++;
	if (chessboard[y][x] == 0 && y < SIZE && x < SIZE)
	{
		update_chessboard(&chessboard, y, x++);
		return (ft_ten_queens_puzzle());
	}
	else if (y == SIZE && x != 0)
	{
		back_track(&chessboard, y, --x);
		return (ft_ten_queens_puzzle());
	}
	else if (y != SIZE && x != 0)
	{
		display(chessboard, &count);
		back_track(&chessboard, SIZE, --x);
		return (ft_ten_queens_puzzle());
	}
	return (reset(&chessboard, &count, &x));
}
