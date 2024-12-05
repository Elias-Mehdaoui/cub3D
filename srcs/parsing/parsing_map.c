#include "../../includes/cub3d.h"




int	check_col(t_map *map)
{
	int			i;
	int			j;
	static int	tmp[100] = {0};

	i = 0;
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
		{
			if (!ft_strchr(" 01NSEW", map->tab[i][j]))
				return (1);
			tmp[ft_strchr(" 01NSEW", map->tab[i][j])[0] - 48]++;
			j++;
		}
		i++;
	}
	if (tmp['N' - 48] + tmp['W' - 48] + tmp['E' - 48] + tmp['S' - 48] != 1)
		return (free_tab(tmp), 2);
	return (0);
}

void	get_index(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
		{
			if (ft_strchr("NSEW", map->tab[i][j]))
			{
				map->player.y = i;
				map->player.x = j;
				map->player.face = ft_strchr("NSEW", map->tab[i][j])[0];
				map->tab[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}
void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		printf("%s\n", tab[i++]);
}

int check_wall(char **tab)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while(tab[i])
	{
		j = 0;
		while(tab[i][j])
		{
			if (tab[i][j] == '0')
				if (is_border(tab, i, j))
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i + 1] && str[i] == '\n' && str[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	check_map(char **file, t_args *args, t_map *map)
{
	int i;
	char **tmp;

	i = 0;
	int j = 7;
	map->tab = file + 6;
	if (check_col(map))
		return(ft_printf("Error check_col %i\n", 1));
	get_index(map);
	if (check_wall(map->tab))
		return(ft_printf("Error map\n"), 1);
	
}
