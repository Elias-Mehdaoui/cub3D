/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 05:02:29 by emehdaou          #+#    #+#             */
/*   Updated: 2024/11/07 06:44:21 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


// void print_tab(t_args *args)
// {
// 	int i;

// 	i = 0;
// 	while(i < 4)
// 	{
// 		printf("args->path[%i] = %s\n", i, args->path[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while(i < 3)
// 	{
// 		printf("floor[%i] == %i\n", i, args->floor[i]);
// 		printf("celling[%i] == %i\n", i, args->celling[i]);
// 		i++;
// 	}
// }
int	check_cardinals(char **tab, t_args *args, int index)
{
	int		i;

	i = 0;
	printf("tab[0] = %s\nindex = %i\n", tab[0], index);
	if (!(!ft_strcmp(tab[0], "NO") && index == 0) && !(!ft_strcmp(tab[0], "SO") && index == 1)
		&& !(!ft_strcmp(tab[0], "WE") && index == 2) && !(!ft_strcmp(tab[0], "EA") && index == 3))
		return (ft_printf("Error Cardinals\n"), 2);
	i = 0;
	while (tab[1][i])
	{
		if (!ft_isprint(tab[1][i]))
			return (ft_printf("Error path printable\n"), free_tab(tab), 1);
		i++;
	}
	args->path[index] = tab[1];
	return (0);
}

int store_rgb(char **rgb, t_args *args, int index)
{
	int i;
	int j;
	
	i = 0;
    while(rgb[i])
	{
		j = 0;
        while(rgb[i][j])
        {
            if (!ft_isdigit(rgb[i][j]))
                return (ft_printf("Error rgb\n"), 4);
			j++;
        }
		if (index == 4)
			args->floor[i] = ft_atoi(rgb[i]);
		else 
			args->celling[i] = ft_atoi(rgb[i]);
		i++;
	}
	return (0);	
}

int check_rgb(char *str, t_args *args, int index)
{
	int		i;
    int j;
    char **tab;
    char **rgb;

    tab = ft_split(str, ' ');
    if (len_tab(tab) != 2)
        return (free_tab(tab), ft_printf("Error taille Floor/Celling\n"), 1);
	printf("tab[0] == %s\n", tab[0]);
    if ((ft_strcmp(tab[0], "F") || index != 4) && (ft_strcmp(tab[0], "C") || index != 5))
            return (ft_printf("Error Floor/Celling\n"), 2);
    rgb = ft_split(tab[1], ',');
    if (len_tab(rgb) != 3)
        return (free_tab(rgb), free_tab(tab), ft_printf("Error taille Floor/Celling\n"), 1);
    if (store_rgb(rgb, args, index))
		return(printf("Error rgb\n"), 4);
	return (0);

}

int check_args(char **file, t_args *args, t_map *map)
{
	int	i;
    char **tmp;

	i = 0;
	while (i < 4)
	{
        tmp = ft_split(file[i], ' ');
        if (len_tab(tmp) != 2)
            return (free_tab(tmp), ft_printf("Error taille cardinals\n"), 1);
		if (check_cardinals(tmp, args, i))
			return (2);
		i++;
	}
	i = 4;
	while (i < 6)
	{
		if (check_rgb(file[i], args, i))
			return (4);
		i++;
	}
	if (check_map(file, args, map))
		return (5);
	return (0);
}

int	init_args(int fd, t_args *args, t_map *map)
{
	char *str;
	char **file;

	str = recup_gnl(fd);
	if (!close(fd) || !str)
		return (ft_printf("Error\n%s\n", ERR), free(str), 0);
	printf("str = %s\n", str);
	if (check_newline(str))
		return(printf("Error double newline"), 3);
	file = ft_split(str, '\n');
	free(str);
	if (!file)
		return (1);
	if (check_args(file, args, map))
		return (2);
}