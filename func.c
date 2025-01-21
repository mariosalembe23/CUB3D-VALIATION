/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalembe <msalembe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:03:53 by msalembe          #+#    #+#             */
/*   Updated: 2025/01/21 09:29:18 by msalembe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	utils_check_texture(t_map_data *data)
{
	int	fd;

	fd = open(data->WE, O_RDONLY);
	if (fd == -1)
	{
		printf("Invaid WE texture\n");
		close(fd);
		return (0);
	}
	close(fd);
	fd = open(data->EA, O_RDONLY);
	if (fd == -1)
	{
		printf("Invaid EA texture\n");
		close(fd);
		return (0);
	}
	return (1);
}

int	check_textures(t_map_data *data)
{
	int	fd;

	fd = open(data->NO, O_RDONLY);
	if (fd == -1)
	{
		printf("Invaid NO texture\n");
		close(fd);
		return (0);
	}
	close(fd);
	fd = open(data->SO, O_RDONLY);
	if (fd == -1)
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

int	read_map(char **all_info, t_map_data *map_data)
{
	int	len;

	len = mat_len(all_info);
	map_data->sizeMap = 0;
	while (len-- > 0)
	{
		if (!line_valid(all_info[len]) && is_map_line(all_info[len]))
		{
			printf("\033[31mInvalid map\033[0m\n");
			printf("\033[31m%s\033[30m\n", all_info[len]);
			return (0);
		}
		if (is_map_line(all_info[len]))
			map_data->sizeMap++;
	}
	return (1);
}
