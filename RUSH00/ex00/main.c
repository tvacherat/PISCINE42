void	ft_putchar(char c);
void	rush(int x, int y);

int		ft_atoi(char *str)
{
	int	i;
	int	is_negative;
	int	nb;

	i = 0;
	is_negative = 1;
	nb = 0;
	while (((str[i] > 8 && str[i] < 14) || str[i] == ' ') && str[i] != 0)
		i++;
	while ((str[i] == '+' || str[i] == '-') && str[i] != 0)
	{
		if (str[i] == '-')
			is_negative *= -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != 0)
	{
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	return (nb * is_negative);
}

int		main(int argc, char **argv)
{
	if (argc > 2)
		rush(ft_atoi(argv[1]), ft_atoi(argv[2]));
	else
		rush(5, 5);
	return (0);
}
