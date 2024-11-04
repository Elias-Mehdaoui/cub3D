#include "../../includes/cub3d.h"

// int tab_len
// int    check_args(char **file, t_args args)
// {

// }

int init_args(int fd, t_args *args)
{
    int i;
    char *str;
    char **file;

    i = 0;
    str = recup_gnl(fd);
    printf("%s\n", str);
	if (!close(fd) || !str)
		return (ft_printf("Error\n%s\n", ERR), free(str), 0);
    file = ft_split(str, '\n');
    free(str);
    if (!file)
        return(1);
    // if (check_args(file, args))
    //     return(2);
    i = 0;
    while(file)
    {
        printf("%s\n", file[i]);
        i++;
    }
}