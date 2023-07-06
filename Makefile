# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 13:36:13 by yetay             #+#    #+#              #
#    Updated: 2023/07/06 16:00:36 by yetay            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wno-integer-overflow
TEST_CFLAGS =
RM = rm -rf

NAME = libftprintf.a

DIR = ../ft_printf

INCLUDES = -I$(DIR) -I$(DIR)/libft -I.

DEPEND_SOURCES = ft_printf_test_utils.c tests_main.c

CONVERSION_FLAGS = percent c d i p s u x_lower x_upper

MANDATORY_FLAGS = $(addprefix mandatory/, $(CONVERSION_FLAGS) mixed)

BONUS_SETS = b1 b2 bonus_all

BONUS_FLAGS = $(foreach f, $(CONVERSION_FLAGS), bonus_test_$(f).c)

TEST_OUTFILES = printf.out printf.ret ft_printf.out ft_printf.ret

.PHONY: mandatory mmsg $(MANDATORY_FLAGS) \
	bonus bmsg $(BONUS_SETS) $(BONUS_FLAGS) \
	$(CONVERSION_FLAGS) fclean

mandatory: mmsg $(MANDATORY_FLAGS)

mmsg:
	@echo "MANDATORY TESTS"

$(MANDATORY_FLAGS): %: %/test.c $(DEPEND_SOURCES) $(DIR)/$(NAME) test_compare
	@$(CC) $(CFLAGS) $(TEST_CFLAGS) \
		$(INCLUDES) \
		-L$(DIR) -L$(DIR)/libft -lftprintf -lft \
		-o ft_printf_test $(DEPEND_SOURCES) $< \
		&& ./ft_printf_test \
		&& chmod u+rw $(TEST_OUTFILES) \
		&& $(RM) ft_printf_test ft_printf_test.dSYM
	@./test_compare $(patsubst mandatory/%, mandatory_%, $@) \
		&& bash rename.sh $(patsubst mandatory/%, mandatory_%, $@)

bonus: bmsg bonus_all

bmsg:
	@echo "BONUS TESTS"

bonus_all: $(BONUS_FLAGS)

$(BONUS_FLAGS): test_builder test_compare
	@./test_builder $(patsubst bonus_test_%.c, %, $@) \
		&& chmod u+rw auto_test.c \
		&& mv auto_test.c $@
	@$(CC) $(CFLAGS) $(TEST_CFLAGS) \
		$(INCLUDES) \
		-L$(DIR) -L$(DIR)/libft -lftprintf -lft \
		-o ft_printf_test $(DEPEND_SOURCES) $@ \
		&& $(RM) $@ \
		&& ./ft_printf_test \
		&& chmod u+rw $(TEST_OUTFILES) \
		&& $(RM) ft_printf_test ft_printf_test.dSYM
	@./test_compare $(patsubst bonus_test_%.c, bonus_%, $@) \
		&& bash rename.sh $(patsubst bonus_test_%.c, bonus_%, $@)

$(CONVERSION_FLAGS):

test_compare: test_compare.c
	@$(CC) $(CFLAGS) $(TEST_CFLAGS) -o $@ $<

test_builder: test_builder.c ft_printf_test_utils.c
	@$(CC) -I. ft_printf_test_utils.c -o $@ $<

$(DIR)/$(NAME):
	@make -C $(DIR)

fclean:
	@$(RM) test_compare test_compare.dSYM
	@$(RM) test_builder test_builder.dSYM
	@$(RM) diffs
