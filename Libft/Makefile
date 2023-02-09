# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 10:49:16 by rfranco           #+#    #+#              #
#    Updated: 2023/01/21 14:48:10 by rfranco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Setup
NAME =			libft.a
CC =			gcc
CFLAGS =		-Wall -Wextra -Werror
AR =			ar rcs
RM = 			rm -rf

# HEADERS
H_DIR =			inc

# SOURCES
## Main directory
SRCS_DIR =		srcs
## Sub-directories
SUB_DIRS =		ctype				\
				string				\
				type_conversion		\
				output				\
				linked_list			\
				alloc				\

## To tell Make that it should search for source files in those directories
VPATH = $(addprefix $(SRCS_DIR)/, $(SUB_DIRS)/)

## Source files
### ctype sub-directory
SRCS =			ft_islower.c		\
				ft_isupper.c		\
				ft_isalpha.c		\
				ft_isdigit.c		\
				ft_isalnum.c		\
				ft_isascii.c		\
				ft_isprint.c		\
				ft_toupper.c		\
				ft_tolower.c		\
				
### string sub-directory
SRCS +=			ft_memset.c			\
				ft_bzero.c			\
				ft_memcpy.c			\
				ft_memmove.c		\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_strlen.c			\
				ft_strlcpy.c		\
				ft_strlcat.c		\
				ft_strchr.c			\
				ft_strrchr.c		\
				ft_strncmp.c		\
				ft_strnstr.c		\
				ft_strdup.c			\
				ft_substr.c			\
				ft_strjoin.c		\
				ft_strtrim.c		\
				ft_split.c			\
				ft_strmapi.c		\
				ft_striteri.c		\
				
### type_conversion sub-directory
SRCS +=			ft_atoi.c			\
				ft_atol.c			\
				ft_itoa.c			\

### output sub-directory
SRCS +=			ft_putchar_fd.c		\
				ft_putstr_fd.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c		\

### linked_list sub-directory
SRCS +=			ft_lstnew.c			\
				ft_lstadd_front.c	\
				ft_lstsize.c		\
				ft_lstlast.c		\
				ft_lstadd_back.c	\
				ft_lstdelone.c		\
				ft_lstclear.c		\
				ft_lstiter.c		\
				ft_lstmap.c			\
				
### alloc sub-directory
SRCS +=			ft_calloc.c			\

# OBJECTS
OBJS_DIR = 		objs
OBJS =			$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

# TARGETS
all: $(OBJS_DIR) $(NAME)  

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -I$(H_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re