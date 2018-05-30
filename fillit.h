/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 21:55:00 by adstuder          #+#    #+#             */
/*   Updated: 2018/05/30 17:39:40 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# define BUFF_SIZE 21

typedef struct		s_tetri
{
	int				id;
	char			*piece;
	char			minsq;
	struct s_tetri	*next;
}					t_tetri;

t_tetri				*init_db(void);
char				*get_next_piece(int fd);
int					check_char(char *buf, int ret);
void				fill_lst2(t_tetri *tmp);
void				fill_lst(t_tetri **start, int i);
void				addlink(t_tetri **start);
char				*tetridetector(char *str);
char				*subdetector(char *str, int i, int k, char *pc);
char				*library_generator(int id, char *str);
int					tetricmp(char *str, t_tetri *start);
int					detection_error(int fd, char *str);
char				*check_file(char *argv, char *str);
char				**piece(char *id_piece, t_tetri *list, char **piece);
char				*place_piece(char *piece, char c, char *sq, int start);
char				*erase_piece(char *sq, char c);
int					min_square_finder(int len);
char				*create_square(int size);
char				**tab_lib_creator(char *id_piece, t_tetri *list);
int					get_square_size(char *sq);
char				*tetrisolver(char *sq, char c, int start,
					char **tab_pieces);
int					get_start(char *sq, char c);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
char				*print_error(void);

#endif
