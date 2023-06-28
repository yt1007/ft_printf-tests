# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 13:36:13 by yetay             #+#    #+#              #
#    Updated: 2023/06/28 18:23:46 by yetay            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = 
TEST_CFLAGS = -fsanitize=address -ggdb

NAME = libftprintf.a

DIR = ../20230620

INCLUDES = -I$(DIR)/libft -I$(DIR)

DEPEND_SOURCES = libft/ft_putendl_fd.c libft/ft_putnbr_fd.c \
			     libft/ft_putstr_fd.c

TEST_SOURCES = main.c

.PHONY: mandatory

mandatory:
	make -C $(DIR)
	@echo "Running tests for ft_printf."
	@$(CC) $(CFLAGS) $(TEST_CFLAGS) \
		-L$(DIR) -lftprintf $(INCLUDES) \
		-o ft_printf $(addprefix $(DIR)/, $(DEPEND_SOURCES)) $(TEST_SOURCES) \
		&& ./ft_printf \
		&& rm -rf ft_printf ft_printf.*/ stdout.*printf
