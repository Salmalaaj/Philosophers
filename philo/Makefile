SRCS = philo.c

FLAGS	= -Wall -Wextra -Werror -g -pthread
OBJS	= $(SRCS:.c=.o)

NAME	= philosophers

RM		= @rm -f

$(NAME): $(OBJS)
	cc $(FLAGS) $(SRCS) -o $(NAME)

all:	$(NAME) 
	
clean:
	${RM} ${NAME} 

fclean:	clean
	${RM} ${OBJS}

re:		fclean all