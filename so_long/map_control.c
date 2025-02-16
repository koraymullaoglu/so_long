#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int ft_strlen_sl(char *str)
{
    int i;

    i = 0;
    if (str == NULL)
        return (0);
    while(str[i])
        i++;
    return (i);
}

void    xpm_isexist()
{
    int fd_chr;
    int fd_bg;
    int fd_c;
    int fd_ex;
    int fd_w;

    fd_chr = open("assets/player.xpm", O_RDWR);
    fd_bg = open("assets/player.xpm", O_RDWR);
    fd_c = open("assets/player.xpm", O_RDWR);
    fd_ex = open("assets/player.xpm", O_RDWR);
    fd_w = open("assets/player.xpm", O_RDWR);
    if (fd_chr <= 0 || fd_bg <= 0 || fd_c <= 0 || fd_ex <= 0 || fd_w <= 0)
    {
        write(2, "XPM not found\n", 14);
        close(fd_chr);
        close(fd_bg);
        close(fd_c);
        close(fd_ex);
        close(fd_w);
        exit(1);
    }
    close(fd_chr);
    close(fd_bg);
    close(fd_c);
    close(fd_ex);
    close(fd_w);
}

void map_path_control(char *path)
{
    int len;

    len = ft_strlen_sl(path);
    if (!(path[len - 1] == 'r' && path[len - 2] == 'e' && path[len - 3] == 'b' && path[len - 4] == '.'))
    {
        write(2, "Not .ber file\n", 14);
        exit(1);
    }
}

void    map_file_exits(char *path)
{
    int fd;

    fd = open(path, O_RDWR);
    if (fd <= 0)
    {
        write(2,"mapfile not exist\n", 18);
        close(fd);
        exit(1);
    }
    close(fd);
}