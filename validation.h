/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalembe <msalembe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:36:58 by msalembe          #+#    #+#             */
/*   Updated: 2025/01/21 08:38:08 by msalembe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include "gnl/get_next_line.h"
# include <ctype.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_map_data
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*F;
	char	*C;
	char	**map;
	int		sizeMap;
}			t_map_data;

int			mat_len(char **mat);
int			verify_data_textures(char **all_info, t_map_data *map_data);
int			verify_color_data(t_map_data *map_data, char **map_line);
int			line_valid(char *str);
int			is_map_line(const char *line);
int			check_extension(char *filename);
int			read_map(char **all_info, t_map_data *map_data);
int			verify_deep(char **map, int sizeMap);
int			check_textures(t_map_data *data);

#endif