/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:53:11 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/03/07 12:46:11 by rvuorenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_header.h"

void	coordminmax(char *str, char *pos, t_help *help)
{
	help->x = 0;
	pos[0] = 3;
	pos[1] = 0;
	pos[2] = 3;
	pos[3] = 0;
	while (help->x < 20)
	{
		if (str[help->x] == '#')
		{
			if (help->x % 5 < pos[0])
				pos[0] = help->x % 5;
			if (help->x % 5 > pos[1])
				pos[1] = help->x % 5;
			if (help->x / 5 < pos[2])
				pos[2] = help->x / 5;
			if (help->x / 5 > pos[3])
				pos[3] = help->x / 5;
		}
		help->x++;
	}
}

void	check_piece(t_etris *tetr, t_help *help)
{
	char	pos[4];

	coordminmax(tetr->str, pos, help);
	tetr->width = pos[1] - pos[0] + 1;
	tetr->height = pos[3] - pos[2] + 1;
	tetr->num = 0;
	help->y = 0;
	while (help->y < tetr->height)
	{
		help->x = 0;
		while (help->x < tetr->width)
		{
			if (tetr->str[(pos[0] + help->x) + (pos[2] + help->y) * 5] == '#')
				tetr->num |= (1UL << (16 * (help->y + 1) - 1 - help->x));
			help->x++;
		}
		help->y++;
	}
	tetr->orig = tetr->num;
}

void	read_to_struct(char *file, t_help *help, t_etris *tetr)
{
	size_t	res;

	help->i = 0;
	help->fd = open(file, O_RDONLY);
	if (help->fd == -1)
		exit_error("error\n");
	while (help->i < help->pieces)
	{
		res = read(help->fd, help->str, 21);
		help->str[res] = '\0';
		ft_memmove((void *)&tetr[help->i].str[0], (void *)help->str, res + 1);
		tetr[help->i].id = help->i + 65;
		tetr[help->i].pos = 0;
		check_piece(&tetr[help->i], help);
		help->i++;
	}
	close(help->fd);
	if (tetr[help->pieces - 1].str[20] != '\0')
		exit_error("error\n");
}
