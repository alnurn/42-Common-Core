# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+         #
#        mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+            #
#    Created: 2026/07/14 15:55:24 by mgumberi          #+#    #+#              #
#    Updated: 2026/08/25 00:00:00 by anurmach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC := srcs
HEADERS := headers
LIBFT_DIR := libft
TOKENIZER := tokenizer
ENV := env
BUILTINS := builtins
VALIDATOR := validator
PARSER := parser
EXPANDER := expander
EXECUTOR := executor
SIGNALS := signals
UTILS := utils

CC := cc
CFLAGS := -Wall -Wextra -Werror -I $(HEADERS)
READLINE := -lreadline
RM := rm -f

SRCS := $(SRC)/main.c \
		$(SRC)/main2.c \
		$(SRC)/$(TOKENIZER)/tokenizer.c \
		$(SRC)/$(TOKENIZER)/tokenizer_utils.c \
		$(SRC)/$(TOKENIZER)/tokenizer_utils2.c \
		$(SRC)/$(TOKENIZER)/tok_lstnew.c \
		$(SRC)/$(TOKENIZER)/tok_lstlast.c \
		$(SRC)/$(TOKENIZER)/tok_lstdelone.c \
		$(SRC)/$(TOKENIZER)/tok_lstclear.c \
		$(SRC)/$(TOKENIZER)/tok_lstadd_back.c \
		$(SRC)/$(VALIDATOR)/validator.c \
		$(SRC)/$(VALIDATOR)/syntax_checks.c \
		$(SRC)/$(PARSER)/parser.c \
		$(SRC)/$(PARSER)/parser_cmd.c \
		$(SRC)/$(PARSER)/parser_utils.c \
		$(SRC)/$(PARSER)/parser_free.c \
		$(SRC)/$(EXPANDER)/expander.c \
		$(SRC)/$(EXPANDER)/expand_word.c \
		$(SRC)/$(EXPANDER)/expand_split.c \
		$(SRC)/$(EXPANDER)/expand_quotes.c \
		$(SRC)/$(EXPANDER)/expand_var.c \
		$(SRC)/$(EXPANDER)/expand_target.c \
		$(SRC)/$(EXPANDER)/expand_heredoc.c \
		$(SRC)/$(EXPANDER)/expand_heredoc_line.c \
		$(SRC)/$(EXECUTOR)/executor.c \
		$(SRC)/$(EXECUTOR)/executor_single.c \
		$(SRC)/$(EXECUTOR)/executor_multi.c \
		$(SRC)/$(EXECUTOR)/executor_child.c \
		$(SRC)/$(EXECUTOR)/executor_redir.c \
		$(SRC)/$(EXECUTOR)/executor_heredoc.c \
		$(SRC)/$(EXECUTOR)/executor_heredoc_read.c \
		$(SRC)/$(EXECUTOR)/executor_path.c \
		$(SRC)/$(EXECUTOR)/executor_builtin.c \
		$(SRC)/$(EXECUTOR)/executor_wait.c \
		$(SRC)/$(SIGNALS)/signals.c \
		$(SRC)/$(SIGNALS)/signals_exec.c \
		$(SRC)/$(UTILS)/arr_utils.c \
		$(SRC)/$(UTILS)/utils.c \
		$(SRC)/$(ENV)/environment.c \
		$(SRC)/$(ENV)/env_lstnew.c \
		$(SRC)/$(ENV)/env_lstlast.c \
		$(SRC)/$(ENV)/env_lstdelone.c \
		$(SRC)/$(ENV)/env_lstclear.c \
		$(SRC)/$(ENV)/env_lstadd_back.c \
		$(SRC)/$(ENV)/env_lstremove.c \
		$(SRC)/$(ENV)/env_set.c \
		$(SRC)/$(ENV)/env_build.c \
		$(SRC)/$(BUILTINS)/builtin_echo.c \
		$(SRC)/$(BUILTINS)/builtin_pwd.c \
		$(SRC)/$(BUILTINS)/builtin_cd.c \
		$(SRC)/$(BUILTINS)/builtin_env.c \
		$(SRC)/$(BUILTINS)/builtin_export.c \
		$(SRC)/$(BUILTINS)/builtin_export_utils.c \
		$(SRC)/$(BUILTINS)/builtin_export_sorted.c \
		$(SRC)/$(BUILTINS)/builtin_export_print.c \
		$(SRC)/$(BUILTINS)/builtin_unset.c \
		$(SRC)/$(BUILTINS)/builtin_exit.c

MINISHELL := minishell
LIBFT := libft.a
OBJS := $(SRCS:.c=.o)

all : $(MINISHELL)

$(MINISHELL) : $(LIBFT) $(OBJS)
		$(CC) $(OBJS) $(LIBFT) -o $@ $(READLINE)

$(SRC)/%.o : $(SRC)/%.c
		$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) : FORCE
	$(MAKE) -C $(LIBFT_DIR)
	@cmp -s $(LIBFT_DIR)/$(LIBFT) $(LIBFT) || cp $(LIBFT_DIR)/$(LIBFT) .

FORCE:

clean:
		$(MAKE) clean -C $(LIBFT_DIR)
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(MINISHELL)
		$(RM) $(LIBFT)
		$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re FORCE
