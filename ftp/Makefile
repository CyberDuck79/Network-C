# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/18 11:52:41 by fhenrion          #+#    #+#              #
#    Updated: 2020/02/18 16:28:47 by fhenrion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ftp_server

SRC_NAME = server cmd_ini cmd_parsing cmd_ls cmd_get cmd_put cmd_pwd cmd_cd \
cmd_quit cmd_unknown log
SRC = $(addsuffix .c,$(SRC_NAME))
SRC_O = $(addsuffix .o,$(SRC_NAME))

CC = gcc
CFLAGS = -Werror -Wall -Wextra

.PHONY: clean fclean all re bonus

all: $(NAME)

$(NAME): $(SRC_O)
	$(CC) $(CFLAGS) -I. $^ -o $@
	@echo "\033[0;32mCompilation OK\033[0m"

%.o : %.c
	$(CC) -c $(CFLAGS) -I. $< -o $@

clean:
	@/bin/rm -f $(SRC_O)
	@echo "\033[0;32mObjects files cleaning OK\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[0;32mLibrary cleaning OK\033[0m"

re: fclean $(NAME)
