# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 19:34:15 by marcgar2          #+#    #+#              #
#    Updated: 2025/01/20 19:34:15 by marcgar2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

PRINTF_DIR = ./ft_printf
INCLUDE = ./inc/push_swap.h
LIBFT_DIR = ./libft
MOVES_DIR = ./moves
UTILS_DIR = ./utils
BG = \e[4;32m	# BOLD GREEN
PRPL = \e[0;35m # PURPLE
NC = \e[0m 		# NO COLOR

PRINTF_SRC = $(PRINTF_DIR)/ft_atoi.c \
				$(PRINTF_DIR)/ft_itoa.c \
				$(PRINTF_DIR)/ft_print_ptr.c \
				$(PRINTF_DIR)/ft_printchar.c \
				$(PRINTF_DIR)/ft_printf_utils.c \
				$(PRINTF_DIR)/ft_printf.c \
				$(PRINTF_DIR)/ft_printhex.c \
				$(PRINTF_DIR)/ft_printprcnt.c \
				$(PRINTF_DIR)/ft_printunsign.c 

LIBFT_SRC = $(LIBFT_DIR)/ft_bzero.c \
			$(LIBFT_DIR)/ft_calloc.c \
			$(LIBFT_DIR)/ft_memchr.c \
			$(LIBFT_DIR)/ft_memcmp.c \
			$(LIBFT_DIR)/ft_memcpy.c \
			$(LIBFT_DIR)/ft_memmove.c \
			$(LIBFT_DIR)/ft_memset.c \
			$(LIBFT_DIR)/ft_strchr.c \
			$(LIBFT_DIR)/ft_strdup.c \
			$(LIBFT_DIR)/ft_striteri.c \
			$(LIBFT_DIR)/ft_strlcat.c \
			$(LIBFT_DIR)/ft_strlcpy.c \
			$(LIBFT_DIR)/ft_strncmp.c \
			$(LIBFT_DIR)/ft_strnstr.c \
			$(LIBFT_DIR)/ft_strrchr.c \
			$(LIBFT_DIR)/ft_tolower.c \
			$(LIBFT_DIR)/ft_toupper.c \
			$(LIBFT_DIR)/ft_putchar_fd.c \
			$(LIBFT_DIR)/ft_putstr_fd.c \
			$(LIBFT_DIR)/ft_putnbr_fd.c \
			$(LIBFT_DIR)/ft_putendl_fd.c \
			$(LIBFT_DIR)/ft_split.c \
			$(LIBFT_DIR)/ft_strjoin.c \
			$(LIBFT_DIR)/ft_strtrim.c \
			$(LIBFT_DIR)/ft_substr.c \
			$(LIBFT_DIR)/ft_strmapi.c \
			$(LIBFT_DIR)/ft_strlen.c \
			$(LIBFT_DIR)/ft_isdigit.c \
			$(LIBFT_DIR)/ft_isalpha.c \
			$(LIBFT_DIR)/ft_isprint.c \
			$(LIBFT_DIR)/ft_isascii.c \
			$(LIBFT_DIR)/ft_isalnum.c

MOVES_SRC = $(MOVES_DIR)/push.c \
			$(MOVES_DIR)/rotate.c \
			$(MOVES_DIR)/rv_rotate.c \
			$(MOVES_DIR)/sort_stacks.c \
			$(MOVES_DIR)/sort_three_elem.c \
			$(MOVES_DIR)/swap.c 

UTILS_SRC = $(UTILS_DIR)/errors_handling.c \
			$(UTILS_DIR)/init_a_b.c \
			$(UTILS_DIR)/init_b_a.c \
			$(UTILS_DIR)/push_swap_main.c \
			$(UTILS_DIR)/split.c \
			$(UTILS_DIR)/stack_init.c \
			$(UTILS_DIR)/stack_utils.c

SRCS = $(PRINTF_SRC) $(LIBFT_SRC) $(MOVES_SRC) $(UTILS_SRC)
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(PRPL)[OK]${NC}"

%.o: %.c
	@echo "$(BG)Compilando push_mierdas...${NC}"
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(PRPL)[OK]${NC}"

clean:
	@echo "$(BG)Limpiando objetos de mierda...${NC}"
	$(RM) $(OBJ)

fclean: clean
	@echo "$(BG)Limpiando el binario de mierda...${NC}"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re