#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int		ft_atoi(char *str)
{
	int i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

int		ft_check_argv(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] != 43 && str[i] != 45 && !(str[i] >= 48 && str[i] <= 57))
			return(1);
		i++;
	}
	return (0);
}

void	pattern_genrator(int row, int column, int density)
{
	int random_number;
	const int max = 99;
	const int min = 0;
	int i;
	int j;
	
	random_number = 0;
	i = 0;
	density < 0 ? density = 0 : 0; //make sure density is >= 0 et <= 100
	density > 100 ?	density = 100 : 0;
	srand(time(NULL)); // Initialize random number
	printf("%d-ox\n", row);
	while (i < row)
	{
		j = 0;
		while (j < column)
		{
			random_number = (rand() % (max - min + 1)) + min; // Generate random number
			random_number < density ? printf("o") : printf("-"); // Genrate "o" or "-"
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	int row;
	int column;
	int density;
	int i;

	i = 1;
	if (argc != 4)
	{
		printf("[ERROR] Please indicate number of rows, columns and the density wanted\n\n");
		return (0);
	}
	while (i < argc)
	{
		if (ft_check_argv(argv[i]) != 0)
		{
			printf("[ERROR] Please make sure argv[%d] is an integer\n\n", i);
			return (0);
		}
		i++;
	}
	if ((row = ft_atoi(argv[1])) < 1)
	{
		printf("[ERROR] Please make sure argv[1] is greater than 1");
		return (0);
	}
	if ((column = ft_atoi(argv[2])) < 1)
	{
		printf("[ERROR] Please make sure argv[2] is greater than 1");
		return (0);
	}
	density = ft_atoi(argv[3]);
	
	pattern_genrator(row, column, density);
	return (0);
}
