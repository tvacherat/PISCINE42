/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 10:37:01 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/17 14:27:22 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!tab || length < 0)
		return (0);
	while (i < length)
	{
		(*f)(tab[i]) != 0 ? count++ : 0;
		i++;
	}
	return (count);
}
