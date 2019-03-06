/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:10:21 by vmuradia          #+#    #+#             */
/*   Updated: 2019/03/05 16:17:31 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h> //delete this bitch later

int	main(void)
{
	t_farm farm;

	find_ants(farm);
}

int find_ants(t_farm farm)
{
	char *line;
	char **data;

	get_next_line(0, &line);
	farm.ants = ft_atoi(line);
	if (farm.ants <= 0)
		ft_error(1);
	printf ("The number of ants is %d\n", farm.ants);
	while (ft_strncmp(line, "##start", 7) != 0)
	{
		free(line);
		get_next_line(0, &line);
	}
	get_next_line(0, &line);
	data = ft_strsplit(line, ' ');
	farm.start = ft_atoi(data[0]);
	farm.coords_of_start.x = ft_atoi(data[1]);
	farm.coords_of_start.y = ft_atoi(data[2]);
	printf("The ants are in the room number %d, the coords are x %d and y %d\n", farm.start, farm.coords_of_start.x, farm.coords_of_start.y);
	free_2d((void*)data, 3);
	free(line);
	find_end(farm, line);
	return (1);
}

int find_end(t_farm farm, char *line)
{
	char **data;

	while(ft_strncmp(line, "##end", 5) != 0)
	{
		free(line);
		get_next_line(0, &line);
	}
	get_next_line(0, &line);
	data = ft_strsplit(line, ' ');
	farm.end = ft_atoi(data[0]);
	farm.coords_of_end.x = ft_atoi(data[1]);
	farm.coords_of_end.y = ft_atoi(data[2]);
	if (farm.start == farm.end)
		ft_error(2);
	printf("We are going to room %d coords x %d and y %d\n", farm.end, farm.coords_of_end.x, farm.coords_of_end.y);
	return (1);
}

void	ft_error(int code)
{
	if (code == 1)
		ft_putendl ("Not enough ants, try again!");
	else if (code == 2)
		ft_putendl("The same start and end, not going to work!");
	exit(code);
}