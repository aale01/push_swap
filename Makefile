NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -gdwarf-4 -o3

MAKEFLAGS += -s

SRCSDIR = mandatory
SRCS = main.c 					\
       ft_init_stacks.c			\
       ft_init_chunks.c			\
       ft_set_arr.c				\
       ft_close.c				\
       ft_exec_sort.c 			\
       ft_sort_single_chunk.c	\
       ft_utils.c				\
       swap.c					\
       push.c					\
       rotate.c					\
       reverse_rotate.c			\
       ft_impera.c				\
       ft_sort_chunks.c			\
       ft_del_cmds.c			\

OBJDIR = mandatory/obj
OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

BONUS_SRCSDIR = bonus
BONUS_SRCS = main.c				\
			 ft_init_stacks.c	\
			 ft_close.c			\
			 ft_read_cmds.c		\
			 ft_execute_cmds.c	\
			 swap.c				\
			 push.c				\
			 rotate.c			\
			 reverse_rotate.c	\
			 ft_check_sort.c	\

BONUS_OBJDIR = bonus/obj
BONUS_OBJS = $(patsubst %.c,$(BONUS_OBJDIR)/%.o,$(BONUS_SRCS))

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)

GREEN = \033[32m
RED = \033[31m
RESET = \033[0m

all:
	if [ -f $(BONUS_NAME) ]; then \
		rm -rf $(BONUS_NAME); \
		rm -rf $(BONUS_OBJDIR); \
		printf "$(RED)$(BONUS_NAME) and objects deleted!$(RESET)\n"; \
	fi
	$(MAKE) $(NAME)

$(NAME): $(OBJS)
	if [ ! -f $(LIBFT_LIB) ]; then \
		$(MAKE) -C $(LIBFT_DIR); \
	fi
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)
	printf "\n\033[1A\033[K"
	printf "$(GREEN)$(NAME) compiled!\n$(RESET)"

$(OBJDIR)/%.o: $(SRCSDIR)/%.c
	mkdir -p $(dir $@)
	printf "$(GREEN)Generating $(NAME) objects... %-33.33s\r$(RESET)" $@
	$(CC) $(CFLAGS) $(LIBFT_INC) -c $< -o $@

$(BONUS_NAME): $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT_LIB) -o $(BONUS_NAME)
	printf "\n\033[1A\033[K"
	printf "$(GREEN)$(BONUS_NAME) compiled!\n$(RESET)"

$(BONUS_OBJDIR)/%.o: $(BONUS_SRCSDIR)/%.c
	mkdir -p $(dir $@)
	printf "$(GREEN)Generating $(BONUS_NAME) objects... %-33.33s\r$(RESET)" $@
	$(CC) $(CFLAGS) $(LIBFT_INC) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJS)
	printf "$(RED)$(NAME) objects deleted!$(RESET)\n"

fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	if [ -f $(NAME) ]; then \
		rm -rf $(NAME); \
		rm -rf $(OBJDIR); \
		printf "$(RED)$(NAME) and objects deleted!$(RESET)\n"; \
	elif [ -f $(BONUS_NAME) ]; then \
		rm -rf $(BONUS_NAME); \
		rm -rf $(BONUS_OBJDIR); \
		printf "$(RED)$(BONUS_NAME) and objects deleted!$(RESET)\n"; \
	fi

re: fclean all

bonus:
	if [ -f $(NAME) ]; then \
		rm -rf $(NAME); \
		rm -rf $(OBJDIR); \
		printf "$(RED)$(NAME) and objects deleted!$(RESET)\n"; \
	fi
	$(MAKE) $(BONUS_NAME)

.PHONY: all clean fclean re bonus
