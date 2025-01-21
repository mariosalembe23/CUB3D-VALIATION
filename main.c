/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalembe <msalembe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:11:45 by msalembe          #+#    #+#             */
/*   Updated: 2025/01/21 11:23:55 by msalembe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

int	allocate_map(t_map_data *map_data, char **all_info)
{
	int	i;
	int	len;
	int	pos;

	len = mat_len(all_info);
	pos = len - map_data->sizeMap;
	i = 0;
	map_data->map = (char **)malloc(sizeof(char *) * (map_data->sizeMap + 1));
	if (!map_data->map)
	{
		printf("Error allocating map\n");
		return (0);
	}
	while (i < map_data->sizeMap)
	{
		map_data->map[i] = ft_strdup(all_info[pos]);
		i++;
		pos++;
	}
	map_data->map[i] = NULL;
	return (1);
}

static int	init_check(char **all_info, t_map_data *map_data)
{
	if (!verify_data_textures(all_info, map_data)
		|| !verify_color_data(map_data, all_info))
		return (1);
	if (!read_map(all_info, map_data))
		return (1);
	if (!allocate_map(map_data, all_info))
		return (1);
	if (!verify_deep(map_data->map, map_data->sizeMap))
		return (1);
	// if (!check_textures(&map_data))
	// 	return (1);
	
	return (0);
}

char	*initial_read(char *file)
{
	int		fd;
	char	*current_line;
	char	*buffer[4024];

	*buffer = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		perror("Error openning file\n");
	while (1)
	{
		current_line = get_next_line(fd);
		if (current_line == NULL)
		{
			close(fd);
			break ;
		}
		*buffer = ft_strjoin(*buffer, current_line);
		free(current_line);
	}
	free(current_line);
	return (*buffer);
}

int	main(int ac, char **av)
{
	char		*file;
	char		*map_line;
	t_map_data	map_data;
	char		**all_info;
	char		*buffer;

	map_data.NO = NULL;
	map_data.EA = NULL;
	map_data.C = NULL;
	map_data.SO = NULL;
	map_data.WE = NULL;
	map_data.F = NULL;
	map_data.sizeMap = 0;
	map_data.map = NULL;

	(void)ac;
	if (ac != 2)
	{
		printf("Error\n");
		return (1);
	}
	file = av[1];
	if (!check_extension(file))
		return (1);
	buffer = initial_read(file);
	map_line = ft_strdup(buffer);
	all_info = ft_split(map_line, '\n');
	free(map_line);
	free(buffer);
	if (init_check(all_info, &map_data))
		return (1);
	printf("\033[32mThis map is valid \033[0m\n");

	// TESTING
	printf("NO: %s\n", map_data.NO);
	printf("SO: %s\n", map_data.SO);
	printf("WE: %s\n", map_data.WE);
	printf("EA: %s\n", map_data.EA);
	printf("F: %s\n", map_data.F);
	printf("C: %s\n", map_data.C);
	for (int i = 0; i < map_data.sizeMap; i++)
		printf("%s\n", map_data.map[i]);
	return (0);
}
