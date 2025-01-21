/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalembe <msalembe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:41:36 by msalembe          #+#    #+#             */
/*   Updated: 2025/01/21 08:37:34 by msalembe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

int	line_valid(char *str)
{
	int	len;

	while (*str == ' ' || *str == '\t')
		str++;
	len = strlen(str);
	if (*str != '1' || str[len - 1] != '1')
	{
		return (0);
	}
	return (1);
}

int	is_map_line(const char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '0' && line[i] != '1' && !isspace(line[i])
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_extension(char *filename)
{
	char	*extension;

	extension = ft_strchr(filename, '.');
	if (!extension)
	{
		printf("Invalid file extension\n");
		return (0);
	}
	extension++;
	if (ft_strncmp(extension, "cub", 3) != 0)
	{
		printf("Invalid file extension\n");
		return (0);
	}
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
			printf("Invalid map\n");
			printf("%s\n", all_info[len]);
			return (0);
		}
		if (is_map_line(all_info[len]))
			map_data->sizeMap++;
	}
	return (1);
}

int	verify_deep(char **map, int sizeMap)
{
	int	i;
	int	x;

	i = 0;
	while (i < sizeMap)
	{
		x = 0;
		while (map[i][x] != '\0')
		{
			if ((i > 0 && (map[i - 1][x] == ' ' || map[i - 1][x] == '\0')
					&& (map[i][x] == '0')) || (i < sizeMap - 1 && (map[i
						+ 1][x] == '\0' || map[i + 1][x] == ' ')
					&& map[i][x] == '0'))
			{
				printf("\033[31mMap not closed at (%d, %d)\033[0m\n", i, x);
				printf("\033[31mAt line: %s\033[0m\n", map[i]);
				return (0);
			}
			if ((x > 0 && (map[i][x] == '0' && map[i][x - 1] == ' '))
				|| (map[i][x] == '0' && map[i][x + 1] == ' '))
			{
				printf("\033[31mMap not closed at (%d, %d)\033[0m\n", i, x);
				printf("\033[31mAt line: %s\033[0m\n", map[i]);
				return (0);
			}
			x++;
		}
		i++;
	}
	return (1);
}
