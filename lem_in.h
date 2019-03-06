/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:09:00 by vmuradia          #+#    #+#             */
/*   Updated: 2019/03/05 16:15:23 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "./libft/libft.h"
# include "stdio.h"
# include "stdlib.h"

typedef struct  s_coord
{
    int         x;
    int         y;
}               t_coord;

typedef struct s_farm
{
    int         ants;
    int         rooms;
    int         start;
    int         end;
    t_coord     coords_of_start;
    t_coord     coords_of_end; 
}               t_farm;

int     find_ants(t_farm farm);
int     find_end(t_farm farm, char *line);
void	ft_error(int code);

#endif
