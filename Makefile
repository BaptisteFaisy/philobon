# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 16:27:46 by bfaisy            #+#    #+#              #
#    Updated: 2024/04/17 16:10:35 by bfaisy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

CC			= 	cc
RM			=   rm -f
CFLAGS		=	-Wall -Werror -Wextra #-fsanitize=thread -g3 -pthread 

SRCS		=	philo.c arguments_check.c utils.c display_message.c time.c \
				initialize.c control.c routine.c destroy_and_free.c put_nbr.c
OBJS		=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re