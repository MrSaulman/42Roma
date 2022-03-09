#include "get_next_line.h"

int main ()
{
    int fd = 0;
    char **line;
    int ret;

    fd = open ("/Users/asalvemi/CLionProjects/get_next_line/test.txt", O_RDONLY);

    ret = get_next_line(fd, line);
    printf("line:%s \nreturn:%d \n", line[0], ret);
}

