/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:33:04 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/16 14:40:03 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <libgen.h>
# include <string.h>

# define BUFF_SIZE 28000

int		ft_strlen(char *str);
void	print_stdin();
void	ft_cat(char *filename, char *prog_name);
void	display_error(char *filename, char *progname);
int		main(int argc, char **argv);

#endif
