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

DIR = ../ft_printf

INCLUDES = -I$(DIR)/includes -I.

DEPEND_SOURCES = ft_printf_test_utils.c

MANDATORY_FLAGS = c d i p s u x_lower x_upper mixed

.PHONY: mandatory $(MANDATORY_FLAGS)

mandatory: $(MANDATORY_FLAGS)

$(MANDATORY_FLAGS): $(DIR)/$(NAME)
	@$(CC) $(CFLAGS) $(TEST_CFLAGS) \
		-I . -o printf $(DEPEND_SOURCES) \
		$(foreach i, $@, mandatory/$(i)/printf.c) \
		&& ./printf > printf.out \
		&& rm -rf printf printf.dSYM
	@$(CC) $(CFLAGS) $(TEST_CFLAGS) \
		-L$(DIR) -lftprintf $(INCLUDES) \
		-o ft_printf $(DEPEND_SOURCES) \
		$(foreach i, $@, mandatory/$(i)/ft_printf.c) \
		&& ./ft_printf > ft_printf.out \
		&& rm -rf ft_printf ft_printf.dSYM
	@diff printf.out ft_printf.out
	@diff printf.ret ft_printf.ret

$(DIR)/$(NAME):
	@make -C $(DIR)
