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
			if (!ft_strchr("01NSEW", map->tab[i][j]))
				return (0);
			tmp[ft_strchr("01NSEW", map->tab[i][j])[0] - 48]++;
			j++;
		}
		i++;
	}
	if (tmp['N' - 48] + tmp['W' - 48] + tmp['E' - 48] + tmp['S' - 48] != 1)
		return (1);
	return (0);
}



// void	print_tab(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	while (tab[i])
// 		printf("%s\n", tab[i++]);
// }

int	check_map(char **file, int i, t_args *args, t_map *map)
{
	int j;
	int k;
	char **tmp;

	k = 0;
	// map->tab = malloc(sizeof(char *) * len_tab(file));
	tmp = file + 6;
	// while(file[i])
	// {
	// 	j = 0;
	// 	map->tab[k] = ft_strdup(file[i]);
	// 	i++;
	// 	k++;
	// }
	while (tmp[k])
		printf("tmp[%i] = %s\n", k, tmp[k++]);
	
	// if (check_col(map))
	// 	return(printf("Error check_col\n"), 1);
}
