/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luperez <luperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 16:45:32 by luperez           #+#    #+#             */
/*   Updated: 2017/04/02 17:02:12 by luperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int		get_response(char *question)
{
	char *rep;

	rep = NULL;
	while (!rep || \
		(rep[0] != 'y' && rep[0] != 'Y' && rep[0] != 'n' && rep[0] != 'N'))
	{
		if (rep)
			free(rep);
		ft_putstr(question);
		ft_putendl(" [yY/nN]");
		get_next_line(0, &rep);
	}
	free(rep);
	if (rep[0] == 'y' || rep[0] == 'Y')
		return (1);
	return (0);
}
