/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_header.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhaukile <jhaukile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:32:49 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/03/03 09:40:06 by jhaukile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_HEADER_H
# define FILLIT_HEADER_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_etris
{
	char				str[22];
	uint64_t			num;
	uint64_t			orig;
	char				id;
	int					height;
	int					width;
	int					pos;
}t_etris;

typedef struct s_help
{
	char				str[22];
	int					x;
	int					y;
	int					i;
	int					pieces;
	int					fd;
	int					size;
}t_help;

void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_putstr(char const *s);
void	ft_strdel(char **as);
size_t	ft_strlen(const char *s);
char	*ft_strnew(size_t size);
int		error_checks(char *argv, t_help *h);
void	read_to_struct(char *file, t_help *help, t_etris *tetr);
int		solver(t_etris *tetr, t_help *help, uint16_t *map, int pos);
void	map_print(t_help *help, t_etris *tetr);
void	exit_error(char *str);

#endif
