/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 12:06:30 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/17 14:22:20 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/do_op.h"

int	addition(int a, int b)
{
	return (a + b);
}

int	substraction(int a, int b)
{
	return (a - b);
}

int	modulo(int a, int b)
{
	return (a % b);
}

int	division(int a, int b)
{
	return (a / b);
}

int	multiplication(int a, int b)
{
	return (a * b);
}
