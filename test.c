# include "pipex.h"


void add_input(t_command *command, char *input)
{
    char *input_space;
    char *flags_input;
    
    input_space = ft_strjoin(" ", input);
    flags_input = ft_strjoin(command->flags, input_space);
    command->flags = flags_input;
    command->complete[1] = flags_input;
}

// int main(void)
// {
//     int fd;

//     fd = open("zebi.txt", O_RDONLY | O_WRONLY);

//     printf("Je suis la\n");
//     dup2(fd, STDOUT_FILENO);
//     close(fd);
//     printf("ta tante\n");
// }