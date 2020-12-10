/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 18:18:41 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/10 15:59:55 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!(*to_find) || !to_find)
		return (str);
	while (str[i])
	{
		j = 0;
		while (to_find[j] && to_find[j] == str[i] && str[i])
		{
			j++;
			i++;
		}
		if (!to_find[j])
			return (&str[i - j]);
		str[i] ? i -= j - 1 : 0;
	}
	return (0);
}
