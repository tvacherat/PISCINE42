void	ft_putchar(char c);

void	print_line(int x, char a, char b, char c)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			ft_putchar(a);
		else if (i == x - 1)
			ft_putchar(c);
		else
			ft_putchar(b);
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	i = 0;
	if (x <= 0 || y <= 0)
		return ;
	while (i < y)
	{
		if (i == 0)
			print_line(x, '/', '*', '\\');
		else if (i == y - 1)
			print_line(x, '\\', '*', '/');
		else
			print_line(x, '*', ' ', '*');
		i++;
	}
}
