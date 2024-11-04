#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
    int fd;
    t_map map;
    t_args args;

    // if (argc == 3)
    //     tobmp();
    
    fd = open(argv[1], O_RDWR);
    if (fd == -1)
        return(ft_printf("Error fd\n"));
    init_args(fd, &args);


    // if (!parse(&map, fd))
    //     return(0);
    

}