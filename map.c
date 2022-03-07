/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:04:22 by jhaukile          #+#    #+#             */
/*   Updated: 2022/03/07 12:44:54 by rvuorenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_header.h"

void	map_start(char **map, t_help *help)
{
	help->x = 0;
	while (help->x < help->size)
	{
		help->y = 0;
		while (help->y < help->size)
		{
			map[help->x][help->y] = '.';
			help->y++;
		}
		help->x++;
	}
}

char	**map_create(t_help *help)
{
	char	**map;

	map = (char **)malloc(sizeof(char *) * (help->size + 1));
	if (!map)
		exit_error("error\n");
	map[help->size] = NULL;
	help->x = 0;
	while (help->x < help->size)
	{
		map[help->x] = ft_strnew((size_t)help->size);
		if (!map[help->x])
			exit_error("error\n");
		help->x++;
	}
	map_start(map, help);
	return (map);
}

void	map_set_id(t_etris *tetr, t_help *help, char **map)
{
	help->x = 0;
	while (help->x < help->pieces)
	{
		help->i = help->size - 1;
		help->y = 16 - help->size;
		while (help->y < 64)
		{
			if (help->i < 0)
			{
				tetr[help->x].pos++;
				help->i = help->size - 1;
				help->y += 16 - help->size;
			}
			if (tetr[help->x].num & (1UL << help->y))
				map[tetr[help->x].pos][help->i] = tetr[help->x].id;
			help->y++;
			help->i--;
		}
		help->x++;
	}
}

void	map_print_clear(char **map, t_help *help)
{
	help->x = 0;
	while (help->x < help->size)
	{
		ft_putstr(map[help->x]);
		ft_putstr("\n");
		ft_strdel(&map[help->x]);
		help->x++;
	}
	ft_strdel(&map[help->x]);
	free(map);
}

void	map_print(t_help *help, t_etris *tetr)
{
	char	**map;

	map = map_create(help);
	map_set_id(tetr, help, map);
	map_print_clear(map, help);
}
