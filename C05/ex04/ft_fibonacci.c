/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 14:10:19 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/13 16:42:08 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0 || index == 0)
		return (index < 0 ? -1 : 0);
	else
		return (index == 1 ? 1 : ft_fibonacci(index - 1)
			+ ft_fibonacci(index - 2));
}
