# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/13 16:01:52 by ebennace          #+#    #+#              #
#    Updated: 2022/04/18 12:05:01 by ebennace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_isdigit.c \
	   ft_isalpha.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_strlen.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strncmp.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strnstr.c \
	   ft_atoi.c \
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putnbr_fd.c \
	   ft_putendl_fd.c \
	   ft_strjoin.c \
	   ft_substr.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_strtrim.c \
	   ft_split.c \




OBJS			= $(SRCS:.c=.o)

BONUS			= ft_lstnew.c \
				  ft_lstsize.c \
				  ft_lstadd_front.c \
				  ft_lstlast.c \
				  ft_lstadd_back.c \
				  ft_lstdelone.c \
				  ft_lstclear.c \
				  ft_lstiter.c \
				  ft_lstmap.c \

BONUS_OBJS		= $(BONUS:.c=.o)

FLAGS 			= -Wall -Wextra -Werror -I.

$(NAME) : $(OBJS)
				ar src  $(NAME) $(OBJS)

%.o: %.c
	clang -c $(FLAGS) -o $@ $^

all : $(NAME)

clean :
				/bin/rm -rf *.o

fclean : clean
				/bin/rm -rf $(NAME)

re : fclean all

bonus:			$(OBJS) $(BONUS_OBJS)
						ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
