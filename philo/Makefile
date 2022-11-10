# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 12:07:03 by slaajour          #+#    #+#              #
#    Updated: 2022/11/10 10:05:47 by slaajour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = philo.c args_stuff.c timing.c routine.c

FLAGS	= -Wall -Wextra -Werror -pthread
OBJS	= $(SRCS:.c=.o)

DEBUG = -fsanitize=thread -g

NAME	= philosophers

RM		= @rm -f

$(NAME): $(OBJS)
	@cc $(FLAGS) $(SRCS) -o $(NAME) 

all:	$(NAME) 
	
clean:
	${RM} ${NAME} 

fclean:	clean
	${RM} ${OBJS}

re:		fclean all