# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 13:36:13 by yetay             #+#    #+#              #
#    Updated: 2023/07/05 14:24:54 by yetay            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = 
TEST_CFLAGS = -fsanitize=address -ggdb

NAME = libftprintf.a

DIR = ../ft_printf

INCLUDES = -I$(DIR) -I$(DIR)/libft -I.

DEPEND_SOURCES = ft_printf_test_utils.c

MANDATORY_FLAGS = percent c d i p s u x_lower x_upper mixed

.PHONY: mandatory $(MANDATORY_FLAGS)

mandatory: $(MANDATORY_FLAGS)

$(MANDATORY_FLAGS): $(DIR)/$(NAME)
	@$(CC) $(CFLAGS) $(TEST_CFLAGS) \
		$(INCLUDES) \
		-L$(DIR) -L$(DIR)/libft -lftprintf -lft \
		-o ft_printf_test $(DEPEND_SOURCES) \
		$(foreach i, $@, mandatory/$(i)/test.c) \
		&& ./ft_printf_test \
		&& rm -rf ft_printf_test ft_printf_test.dSYM
	@diff -a printf.out ft_printf.out
	@diff -a printf.ret ft_printf.ret

$(DIR)/$(NAME):
	@make -C $(DIR)
