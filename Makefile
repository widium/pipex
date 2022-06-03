# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 10:52:36 by ebennace          #+#    #+#              #
#    Updated: 2022/06/03 14:00:06 by ebennace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS		= 	main.c \
				init.c \
				recover.c \
				parsing.c \
				test.c \
				command.c \
				pipe.c \



OBJS			= $(SRCS:.c=.o)
CC				= gcc
# FLAGS 		= -Wall -Werror -Wextra
FLAGS			= -g3 
SANITIZE 		= -fsanitize=address

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


re : fclean all
.PHONY			: all clean fclean re