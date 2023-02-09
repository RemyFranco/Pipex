# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 14:31:18 by rfranco           #+#    #+#              #
#    Updated: 2023/01/31 18:23:52 by rfranco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Executable
NAME =			pipex

### Compilation flags
CC =			gcc
CFLAGS =		-Wall -Werror -Wextra
# CFLAGS +=		-g3 -fsanitize=address
INC_LIBFT =		-L $(LIBFT_DIR) -lft
INC_HEADERS =	-I $(H_DIR)
RM =			rm -rf

### Directories
H_DIR =			inc
LIBFT_DIR =		Libft
SRCS_DIR =		srcs
OBJS_DIR =		objs

### Libraries
LIBFT =			$(LIBFT_DIR)/libft.a

### Files
SRCS_F =		main.c			\
				args_parsing.c	\
				ft_ppxsplit.c	\
				child.c			\
				
SRCS =			$(addprefix $(SRCS_DIR)/, $(SRCS_F))

OBJS_F =		$(SRCS_F:.c=.o)
OBJS =			$(addprefix $(OBJS_DIR)/, $(OBJS_F))

all: $(OBJS_DIR) $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INC_LIBFT) -o $@ $(OBJS) 

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) $(INC_HEADERS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re