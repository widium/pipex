# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 10:52:36 by ebennace          #+#    #+#              #
#    Updated: 2022/06/16 18:23:10 by ebennace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS		= 	get_next_line/get_next_line.c \
				main.c \
				src/init.c \
				src/recover.c \
				src/parsing.c \
				src/command.c \
				src/pipe.c \
				src/redirection.c \
				src/all.c \
				src/file.c \
				utils/verbose.c \
				utils/utils.c \
				utils/free_all.c \
				utils/exit.c \
				utils/cpy.c \



OBJS			= $(SRCS:.c=.o)
CC				= clang
# FLAGS 		= -Wall -Werror -Wextra
FLAGS			= -g3 
SANITIZE 		= -fsanitize=address
LEAKS 			= -fsanitize=leak

%.o : %.c
			$(CC) -c $(FLAGS) $< -o $@
	
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
				$(CC) $(OBJS) $(FLAGS) $(SANITIZE) -g3 libft/libft.a  -o $(NAME)
				gdb $(NAME)
				
sanitize :		$(OBJS)
				$(CC) $(OBJS) $(FLAGS) $(SANITIZE) libft/libft.a  -o $(NAME)

leak :			$(OBJS)
				$(CC) $(OBJS) $(FLAGS) $(LEAKS) libft/libft.a  -o $(NAME)


re : fclean all
.PHONY			: all clean fclean re leak sanitize