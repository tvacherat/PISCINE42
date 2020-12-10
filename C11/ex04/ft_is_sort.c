/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 10:44:11 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/17 14:27:23 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	sort;

	i = 0;
	sort = 0;
	if (!tab || length < 2)
		return (1);
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
		{
			sort == 0 ? sort = 1 : 0;
			if (sort != 1)
				return (0);
		}
		else if ((*f)(tab[i], tab[i + 1]) < 0)
		{
			sort == 0 ? sort = -1 : 0;
			if (sort != -1)
				return (0);
		}
		i++;
	}
	return (1);
}
