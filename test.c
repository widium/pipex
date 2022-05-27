# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

// int main(void)
// {
//     int fd;

//     fd = open("zebi.txt", O_RDONLY | O_WRONLY);

//     printf("Je suis la\n");
//     dup2(fd, STDOUT_FILENO);
//     close(fd);
//     printf("ta tante\n");
// }