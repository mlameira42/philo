# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/09 17:57:04 by mlameira          #+#    #+#              #
#    Updated: 2025/05/09 17:59:02 by mlameira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo

SRC =	main.c								\
		philo.c	ft_free.c	eat.c			\
		mutex_init.c time.c	utils.c	threads.c

OBJ_DIR = objects
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))


CFLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	cc $(CFLAGS) -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	cc ${CFLAGS} ${OBJ} -o ${NAME}

$(OBJ_DIR)/%.o: ./%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -fr $(OBJ)
	rm -fr $(OBJ_DIR)

fclean: clean
	rm -fr $(NAME)

re : fclean all

.PHONY: all clean fclean re