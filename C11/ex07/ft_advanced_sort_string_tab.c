/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 14:16:49 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/17 14:27:30 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	str_swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		j = 0;
		while (tab[j + 1])
		{
			if ((*cmp)(tab[j], tab[j + 1]) > 0)
				str_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}
