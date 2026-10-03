#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int		fd;
    char	*line;
    int		line_num;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Failed to open file");
        return (1);
    }
    line_num = 1;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("[Line %d]: %s", line_num++, line);
        free(line);
    }
    close(fd);
    return (0);
}
