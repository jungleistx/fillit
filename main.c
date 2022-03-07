/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:07:31 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/03/02 15:09:03 by rvuorenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_header.h"

void	exit_error(char *str)
{
	ft_putstr(str);
	exit(-1);
}

void	reset_map_tetr(uint16_t *map, t_etris *tetr, t_help *help)
{
	help->i = 0;
	while (help->i < 16)
		map[help->i++] = 0;
	help->i = -1;
	while (++help->i < help->pieces)
	{
		tetr[help->i].num = tetr[help->i].orig;
		tetr[help->i].pos = 0;
	}
}

void	min_map_size(t_help *help)
{
	help->size = 2;
	while (help->size * help->size < help->pieces * 4)
		help->size++;
}

int	main(int argc, char *argv[])
{
	t_help		help;
	t_etris		tetr[26];
	uint16_t	map[16];

	if (argc != 2)
		exit_error("usage: ./fillit [file_name]\n");
	if (!error_checks(argv[1], &help))
		exit_error("error\n");
	read_to_struct(argv[1], &help, tetr);
	min_map_size(&help);
	reset_map_tetr(map, tetr, &help);
	while (!solver(tetr, &help, map, 0))
	{
		reset_map_tetr(map, tetr, &help);
		help.size++;
	}
	map_print(&help, tetr);
	return (0);
}
