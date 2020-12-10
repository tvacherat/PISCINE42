/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:23:02 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/21 18:51:27 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>

# define BUFF_SIZE 28000
# define FALSE 0
# define TRUE 1

typedef struct	s_file
{
	char			*filename;
	char			stream[BUFF_SIZE];
	ssize_t			bytes;
	int				fd;
	unsigned short	err;
	unsigned long	size;
}				t_file;

void			read_input(unsigned short opt);
void			manage(t_file file, unsigned long *count, unsigned short last
				, unsigned short opt);
void			start(t_file *list, int nb_files, char *prog_name
				, unsigned short opt);
int				main(int argc, char **argv);

void			display_error(t_file file, char *prog_name);
void			display_r_error(char *filename, char *prog_name);
void			display_count(unsigned long count, unsigned short opt);
void			display_text(char *str, unsigned int output);
int				check_args(t_file *list, unsigned int size, char *prog_name);

void			get_line_count(char *line, unsigned long count
				, unsigned short index, unsigned short opt);
void			get_line_hex(char *line, char *actu, unsigned short opt
				, unsigned short actu_size);
void			get_line_txt(char *line, char *actu, unsigned int index
				, unsigned short actu_size);
void			disp_line(unsigned long count, char *actu, unsigned short opt
				, unsigned short actu_size);
void			fill_actu(t_file file, char *actu, unsigned int *i_file
				, unsigned short *i_actu);

unsigned long	get_file_size(char *filename);
void			free_file_list(unsigned int argc, t_file *list);
char			*ft_strcpy(char *s1);
t_file			*get_file_list(unsigned int argc, char **argv
				, unsigned short opt);

char			*putnbr_base(unsigned long nbr, char *base);
unsigned int	ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
void			ft_strncpy(char *dest, char *src, unsigned int size);
int				ft_strncmp(char *s1, char *s2, unsigned int size);

#endif
