/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 21:55:00 by adstuder          #+#    #+#             */
/*   Updated: 2018/05/15 20:40:07 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUFF_SIZE 21

typedef struct	s_tetri
{
	int				id;
	char			*piece;
	char			minsq;
	struct s_tetri	*next;
}					t_tetri;

t_tetri		*init_db(void);
char		*ft_get_next_piece(int fd);
int			ft_check_char(char *buf, char hashtag, char point, char backslash);
void		fill_lst2(t_tetri *tmp);
void		fill_lst(t_tetri **start, int i);
void		addlink(t_tetri **start);
char		*tetridetector(char *str);
char		*subdetector(char *str, int i, int k, char *pc);
char		*library_generator(int id, char *str);
int			tetricmp(char *str, t_tetri *start);
int			ft_detection_error(int fd, char *str);
int			ft_send_error(int id_piece, char *id);
char		*ft_check_file(char *argv, char *str);
char		*ft_smallest_square(int nb_piece, char *map);
char		**ft_piece(unsigned int nb_piece, char *id_piece, t_tetri *list);

#endif
