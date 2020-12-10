/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 18:51:09 by ebarguil          #+#    #+#             */
/*   Updated: 2020/09/30 11:56:14 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_02_H
# define RUSH_02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFF_SIZE 16384
# define FALSE 0
# define TRUE 1
# define DICT "numbers.dict"

typedef struct		s_num
{
	short			hund;
	short			tens;
	short			unit;
}					t_num;

typedef struct		s_dict
{
	char			*key;
	char			*val;
}					t_dict;

typedef struct		s_file
{
	char			*name;
	int				fd;
	ssize_t			bytes;
	char			*buff;
	unsigned long	size;
	short			must_free;
}					t_file;

short				check_file(t_file *file);
short				check_nbr(char *str);
short				check_buff(t_file *file);
short				check_keys(t_dict *list, int size);
short				check_dict(t_dict *list, int size);

unsigned int		ft_strlen(char *str);
int					ft_strcmp(char *s1, char *s2);
unsigned long		get_file_size(char *filename);
unsigned int		nb_len(char *str);
unsigned int		word_len(char *str);

void				free_dict(t_dict *list, unsigned int size);
char				*set_key(t_file *file, int i);
char				*set_val(t_file *file, int i);
t_dict				set_next_dict(t_file *file, unsigned int i);
t_dict				*set_dict(t_file *file);

short				check_biggest_value(t_dict *list, int d_size, int nb_size);
char				*get_val(t_dict *list, int size, char *key);
int					get_dict_size(t_file *file);
short				is_key(char *str, t_dict *list, int size);

short				process(t_file *file, char *nbr);
short				rush(t_dict *dict, int size, char *nbr);
t_num				*splash(char *nbr, short unit, short tens, short hund);
short				find_easy(t_dict *dict, int size, char *nbr, int nb_size);

t_file				init_file(int argc, char **argv);
t_num				*init_num(t_num *tab, int size);
char				*get_nbr_stdin(void);
char				*get_nbr(char *str);
short				is_last_char(char *str);

void				display_rank(t_dict *dict, int d_size, int index, char *nbr);
void				display(t_dict *dict, int d_size, t_num *num, char *nbr);
void				display_tens(t_dict *dict, int d_size, short tens);
void				display_unit(t_dict *dict, int d_size, short nb);
void				display_spec(t_dict *dict, int d_size, short tens
					, short unit);

#endif
