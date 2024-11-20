/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:01:43 by akasekai          #+#    #+#             */
/*   Updated: 2024/11/07 06:41:18 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define ERR "Map must be valid"

# include "../libft/libft.h"

typedef struct s_pos
{
	int		x;
	int		y;
	char	face;
}			t_pos;

typedef struct s_map
{
	char	**tab;
	t_pos	player;
	t_pos	exit;
	void	*mlx;
	void	*win;
}			t_map;

typedef struct s_args
{
	char	*path[4];
	int		floor[3];
	int		celling[3];
}			t_args;

int			init_args(int fd, t_args *args, t_map *map);
int			check_newline(char *str);
int			check_map(char **file, t_args *args, t_map *map);

#endif