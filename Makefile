# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 13:36:13 by yetay             #+#    #+#              #
#    Updated: 2023/07/10 12:58:49 by yetay            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wno-integer-overflow
TEST_CFLAGS = 
RM = rm -rf

NAME = ft_printf_tests

STATIC_LIBS = ftprintf
LIB_AFNAMES = libftprintf.a
LIB_DIRS = ../ft_printf
USE_LIBS = $(addprefix -L, $(LIB_DIRS)) $(addprefix -l, $(STATIC_LIBS))

INC_DIRS = ../ft_printf .
INCLUDES = $(addprefix -I, $(INC_DIRS))

UTIL_SOURCES = ft_printf_test_utils.c
MAIN_SOURCES = tests_main.c
TEST_SOURCES = $(UTIL_SOURCES) $(MAIN_SOURCES)

COMPARE = test_compare
COMP_SOURCES = test_compare.c

BUILDER = test_builder
BLDR_SOURCER = test_builder.c

CONVERSION_FLAGS = percent c d i p s u x_lower x_upper

MANDATORY_FLAGS = $(addprefix mandatory/, $(CONVERSION_FLAGS) mixed)

BONUS_SETS = b1 b2 bonus_all
BONUS_FLAGS = $(foreach f, $(CONVERSION_FLAGS), bonus_test_$(f).c)

TEST_OUTFILES = printf.out printf.ret ft_printf.out ft_printf.ret

.PHONY: all mandatory mprep $(MANDATORY_FLAGS) \
	bonus bprep $(BONUS_SETS) $(BONUS_FLAGS) \
	$(CONVERSION_FLAGS) fclean

all: mandatory bonus

mandatory: mprep $(MANDATORY_FLAGS)

mprep:
	@make -C $(word 1, $(LIB_DIRS)) fclean
	@make -C $(word 1, $(LIB_DIRS))
	@echo "MANDATORY TESTS"

$(MANDATORY_FLAGS): %: %/test.c $(TEST_SOURCES) $(LIB_AFNAMES) $(COMPARE)
	@$(CC) $(CFLAGS) $(TEST_CFLAGS) $(INCLUDES) $(USE_LIBS) \
		-o $(NAME) $(TEST_SOURCES) $< \
		&& ./$(NAME) \
		&& chmod u+rw $(TEST_OUTFILES) \
		&& $(RM) $(NAME) $(NAME).dSYM
	@./$(COMPARE) $(patsubst mandatory/%, mandatory_%, $@) \
		&& bash rename.sh $(patsubst mandatory/%, mandatory_%, $@)

bonus: bprep $(MANDATORY_FLAGS) bonus_all

bprep:
	@make -C $(word 1, $(LIB_DIRS)) fclean
	@make -C $(word 1, $(LIB_DIRS)) bonus
	@echo "BONUS TESTS"

bonus_all: $(BONUS_FLAGS)

$(BONUS_FLAGS): $(BUILDER) $(TEST_SOURCES) $(COMPARE)
	@./$(BUILDER) $(patsubst bonus_test_%.c, %, $@) \
		&& chmod u+rw auto_test.c \
		&& mv auto_test.c $@
	@$(CC) $(CFLAGS) $(TEST_CFLAGS) $(INCLUDES) $(USE_LIBS) \
		-o $(NAME) $(TEST_SOURCES) $@ \
		&& ./$(NAME) \
		&& chmod u+rw $(TEST_OUTFILES) \
		&& $(RM) $(NAME) $(NAME).dSYM
	@./$(COMPARE) $(patsubst bonus_test_%.c, bonus_%, $@) \
		&& bash rename.sh $(patsubst bonus_test_%.c, bonus_%, $@)

$(word 1, $(LIB_AFNAMES)): $(word 1, $(LIB_DIRS))
	@make -C $(word 1, $(LIB_DIRS))

$(word 2, $(LIB_AFNAMES)): $(word 2, $(LIB_DIRS))
	@make -C $(word 2, $(LIB_DIRS))

$(BUILDER): %: %.c $(UTIL_SOURCES)
	@$(CC) -I. $(UTIL_SOURCES) -o $@ $<

$(COMPARE): %: %.c
	@$(CC) $(CFLAGS) $(TEST_CFLAGS) -o $@ $<

clean:
	@$(RM) $(COMPARE) $(COMPARE).dSYM
	@$(RM) $(BONUS_FLAGS)
	@$(RM) $(BUILDER) $(BUILDER).dSYM
	@$(RM) diffs

fclean: clean
	@make -C $(word 1, $(LIB_DIRS)) fclean
	@make -C $(word 2, $(LIB_DIRS)) fclean

re: fclean mandatory
