/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalembe <msalembe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:03:53 by msalembe          #+#    #+#             */
/*   Updated: 2025/01/20 11:04:37 by msalembe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	utils_check_texture(t_map_data *data)
{
	int	fd;

	if ((fd = open(data->WE, O_RDONLY)) == -1)
	{
		printf("Invaid WE texture\n");
		close(fd);
		return (0);
	}
	if ((fd = open(data->EA, O_RDONLY)) == -1)
	{
		printf("Invaid EA texture\n");
		close(fd);
		return (0);
	}
	return (1);
}

int	check_textures(t_map_data *data)
{
	int fd;

	if ((fd = open(data->NO, O_RDONLY)) == -1)
	{
		printf("Invaid NO texture\n");
		close(fd);
		return (0);
	}
	if ((fd = open(data->SO, O_RDONLY)) == -1)
	{
		printf("Invaid SO texture\n");
		close(fd);
		return (0);
	}
	if (!utils_check_texture(data))
		return (0);
	close(fd);
	return (1);
}