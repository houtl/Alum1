/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luperez <luperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 12:30:50 by thou              #+#    #+#             */
/*   Updated: 2017/04/02 16:48:51 by luperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H

# define MAX_SUB 3

# include "libft.h"

typedef struct	s_bdd
{
	int			ia;
}				t_bdd;

char			*ft_mapchecker(int fd);
int				*initmap(char *str);
void			print_map(int *map);
void			game_start(int *map, char *str);
void			clear_screen(void);
int				starter(void);
char			*question(int player_id, char *reponse);
void			win(int player_id);
t_bdd			*new_bdd(void);
t_bdd			*bdd();
void			ia_turn(int player_id, int *map);
int				*get_last_line(int *map);
int				is_valid(char *reponse, int *map);
int				get_response(char *question);

#endif
