/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 05:02:29 by emehdaou          #+#    #+#             */
/*   Updated: 2024/11/05 05:14:00 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_path(char **tab, t_args *args, int index)
{
	int		i;

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

int	check_cardinals(char **card)
{
	int		i;

	i = 0;
	printf("card[0] = %s\n", card[0]);
	if (ft_strcmp(card[0], "NO") && ft_strcmp(card[0], "SO")
		&& ft_strcmp(card[0], "WE") && ft_strcmp(card[0], "EA"))
		return (ft_printf("Error Cardinals\n"), 2);
	return (0);
}

int check_rgb(char *str, t_args *args)
{
	int		i;
    int j;
    char **tab;
    char **rgb;

    tab = ft_split(str, ' ');
    if (len_tab(tab) != 2)
        return (free_tab(tab), ft_printf("Error taille Floor/Celling\n"), 1);
    if (ft_strcmp(tab[0], "F") && ft_strcmp(tab[0], "C"))
            return (ft_printf("Error Floor/Celling\n"), 2);
    rgb = ft_split(tab[1], ',');
    if (len_tab(rgb) != 3)
        return (free_tab(rgb), free_tab(tab), ft_printf("Error taille Floor/Celling\n"), 1);
	i = -1;
    j = -1;
    while(rgb[++i][++j])
        while(rgb[++i][++j])
        {
            if (!ft_isnum(rgb[i][j]))
                return (4);
        }
    
	return (0);

}

int check_args(char **file, t_args *args)
{
	int	i;
	int	j;
    char **tmp;

	j = 0;
	i = 0;
	while (i < 4)
	{
        tmp = ft_split(file[i], ' ');
        if (len_tab(tmp) != 2)
            return (free_tab(tmp), ft_printf("Error taille cardinals\n"), 1);
		if (check_cardinals(tmp))
			return (2);
		if (check_path(tmp, args, i))
			return (3);
		i++;
	}
	while (i < 6)
		if (check_rgb(file[i++], args))
			return (4);
	return (0);
}

int	init_args(int fd, t_args *args)
{
	int i;
	char *str;
	char **file;

	i = 0;
	str = recup_gnl(fd);
	if (!close(fd) || !str)
		return (ft_printf("Error\n%s\n", ERR), free(str), 0);
	file = ft_split(str, '\n');
	free(str);
	if (!file)
		return (1);
	if (check_args(file, args))
		return (2);
	printf("path[0] = %s\n", args->path[0]);
}