# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 14:31:18 by rfranco           #+#    #+#              #
#    Updated: 2023/02/13 15:39:36 by rfranco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Executable
NAME =			pipex
NAME_B =		pipex_bonus

### Compilation flags
CC =			gcc
CFLAGS =		-Wall -Werror -Wextra
# CFLAGS +=		-g3 -fsanitize=address
INC_LIBFT =		-L $(LIBFT_DIR) -lft
INC_HEADERS =	-I $(H_DIR)
RM =			rm -rf

### Directories
H_DIR =			inc
LIBFT_DIR =		libft
SRCS_DIR =		srcs
BSRCS_DIR =		srcs_bonus
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


BSRCS_F =		main_bonus.c			\
				args_parsing_bonus.c	\
				ft_ppxsplit_bonus.c		\
				utils_bonus.c			\
				child_bonus.c			\

BSRCS =			$(addprefix $(BSRCS_DIR)/, $(BSRCS_F))

BOBJS_F =		$(BSRCS_F:.c=.o)
BOBJS =			$(addprefix $(OBJS_DIR)/, $(BOBJS_F))

all: $(OBJS_DIR) $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INC_LIBFT) -o $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) $(INC_HEADERS) -c $< -o $@

bonus: $(OBJS_DIR) $(LIBFT) $(NAME_B)

$(NAME_B): $(BOBJS)
	$(CC) $(CFLAGS) $(INC_LIBFT) -o $(NAME_B) $(BOBJS)

$(OBJS_DIR)/%.o: $(BSRCS_DIR)/%.c
	$(CC) $(CFLAGS) $(INC_HEADERS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME) $(NAME_B)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re