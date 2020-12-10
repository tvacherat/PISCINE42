/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 09:06:15 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/24 10:16:53 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <libgen.h>
# include <string.h>
# include <fcntl.h>

# define BUFF_SIZE 28000
# define FALSE 0
# define TRUE 1

typedef struct	s_file
{
	char			*filename;
	int				fd;
	unsigned short	err;
	unsigned long	size;
}				t_file;

unsigned int	ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
short			is_number(char *str);
short			check_args(int argc, char **argv);
unsigned long	get_size(char *str);

unsigned long	get_file_size(char *filename);
void			free_file_list(t_file *list, unsigned int size);
char			*ft_strcpy(char *s1);
t_file			*get_file_list(unsigned int size, char **argv
				, unsigned short start);

void			display_error(t_file file, char *prog_name);
void			display_text(char *str, unsigned int output);
void			display_header(char *filename);
void			disp_file(t_file file);
void			disp_tail(t_file file, unsigned long tail_size);

void			display_input_tail(long tail);
void			print_stdin(long tail);
void			start(t_file *list, unsigned short list_size
				, unsigned long tail_size, char *prog_name);

#endif
