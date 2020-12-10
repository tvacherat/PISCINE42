/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 12:07:01 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/17 14:21:51 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# define FALSE 0
# define TRUE 1

# include <unistd.h>

typedef struct	s_opp
{
	char	op;
	int		(*f)(int a, int b);
}				t_opp;

int				ft_atoi(char *str);
void			ft_putnbr(int nbr);
int				ft_strcmp(char *s1, char *s2);
short			check_params(int argc, char **argv);

int				addition(int a, int b);
int				substraction(int a, int b);
int				modulo(int a, int b);
int				division(int a, int b);
int				multiplication(int a, int b);

int				main(int argc, char **argv);

#endif
