/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasekai <akasekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:01:43 by akasekai          #+#    #+#             */
/*   Updated: 2024/08/30 19:16:15 by akasekai         ###   ########.fr       */
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
}			t_pos;

typedef struct s_map
{
	char	**tab;
	t_pos	player;
	t_pos	exit;
	void	*mlx;
	void	*win;
    int     face;
    int     col;
	int		length;
	int		height;
	char	*img[81];
}			t_map;

typedef struct s_args
{
    int x;
    int y;
    char    *NO;
    char    *SO;
    char    *WE;
    char    *EA;
    char    *S;
    char    *F;
    char    *C;
    
}   t_args;

// int	check_newline(char *str);
// int	check_rectangle(t_map *map);
// t_map	*check_col(t_map *map);
// void	get_index(t_map *map);
// int	parse(t_map *map, int fd);



#endif