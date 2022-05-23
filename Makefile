NAME = pipex

SRCS		= 	main.c \



OBJS			= $(SRCS:.c=.o)
CC				= clang
# FLAGS 		= -Wall -Werror -Wextra
SANITIZE		= -g3 -fsanitize=address

%.o : %.c
			$(CC) -c $(CFLAGS) $< -o $@
	
$(NAME) : 		$(OBJS)
				make -C libft
				$(CC) $(OBJS) $(FLAGS) libft/libft.a -o $(NAME)		

all : 			$(NAME)

clean :
				make clean -C libft
				/bin/rm -rf $(OBJS)

fclean : clean
				make fclean -C libft
				/bin/rm -rf $(NAME)

debug : 		$(OBJS)
				$(CC) $(OBJS) $(FLAGS) $(SANITIZE) libft/libft.a  -o $(NAME)
				# lldb ./$(NAME)


re : fclean all
.PHONY			: all clean fclean re