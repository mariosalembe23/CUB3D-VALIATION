/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalembe <msalembe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:31:12 by msalembe          #+#    #+#             */
/*   Updated: 2025/01/20 11:10:36 by msalembe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

int	mat_len(char **mat)
{
	int	i;

	i = 0;
	while (mat && mat[i])
		i++;
	return (i);
}

static int	find_colors(char **map_line, char **color, char *type)
{
	int		i;
	char	**line;

	i = -1;
	while (map_line[++i])
	{
		while (map_line[i][0] == ' ')
			map_line[i]++;
		if (ft_strncmp(map_line[i], type, 1) == 0)
		{
			line = ft_split(map_line[i], ' ');
			if (!line[1] || mat_len(line) > 2)
			{
				free(line);
				return (0);
			}
			*color = ft_strdup(line[1]);
			free(line);
			return (1);
		}
	}
	return (0);
}

static int	find_textures(char **map_line, char **coordenate, char *zone)
{
	int		i;
	char	**line;

	i = -1;
	while (map_line[++i])
	{
		while (map_line[i][0] == ' ')
			map_line[i]++;
		if (ft_strncmp(map_line[i], zone, 2) == 0)
		{
			line = ft_split(map_line[i], ' ');
			if (!line[1] || mat_len(line) > 2)
			{
				free(line);
				return (0);
			}
			*coordenate = ft_strdup(line[1]);
			free(line);
			return (1);
		}
	}
	return (0);
}

int	verify_data_textures(char **all_info, t_map_data *map_data)
{
	if (!find_textures(all_info, &map_data->NO, "NO"))
	{
		printf("NO adress not found\n");
		return (0);
	}
	if (!find_textures(all_info, &map_data->SO, "SO"))
	{
		printf("SO adress not found\n");
		return (0);
	}
	if (!find_textures(all_info, &map_data->WE, "WE"))
	{
		printf("WE adress not found\n");
		return (0);
	}
	if (!find_textures(all_info, &map_data->EA, "EA"))
	{
		printf("EA adress not found\n");
		return (0);
	}
	return (1);
}

int	verify_color_data(t_map_data *map_data, char **map_line)
{
	if (!find_colors(map_line, &map_data->F, "F"))
	{
		printf("Floor Color adress not found\n");
		return (0);
	}
	if (!find_colors(map_line, &map_data->C, "C"))
	{
		printf("Celling Color adress not found\n");
		return (0);
	}
	return (1);
}