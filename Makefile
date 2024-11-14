# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 14:43:22 by toferrei          #+#    #+#              #
#    Updated: 2024/11/14 12:14:09 by toferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = $(addsuffix .c, $(addprefix src/, $(SRC_DIR)))

LIBFT			=	libft/
LIBFT_A			=	$(LIBFT)libft.a

PRINTF			=	Ft_Printf/
PRINTF_A		=	$(PRINTF)libftprintf.a

CLIENT_NAME		=	client
CLIENT_SOURCES	=	client.c
	
SERVER_NAME		=	server
SERVER_SOURCES	=	server.c

SOURCES			=	$(SERVER_SOURCES) $(CLIENT_SOURCES)
NAMES			=	$(SERVER_NAME) $(CLIENT_NAME)

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g

all: $(NAMES)

$(NAMES):
	$(MAKE) -s -C $(LIBFT)
	$(MAKE) -s -C $(PRINTF)
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(CLIENT_SOURCES) $(LIBFT_A) $(PRINTF_A)
	$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SERVER_SOURCES) $(LIBFT_A) $(PRINTF_A)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(NAMES)

fclean: clean
	$(MAKE) -s -C $(LIBFT) fclean
	$(MAKE) -s -C $(PRINTF) clean

re: fclean all

.PHONY: all clean fclean re

