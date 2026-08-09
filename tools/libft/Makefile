NAME = libft.a

AR = ar crs

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

MAKEFLAGS += -s

SRCS =	ft_atoi.c			\
		ft_bzero.c			\
		ft_calloc.c     	\
		ft_isalnum.c    	\
		ft_isalpha.c    	\
		ft_isascii.c    	\
		ft_isdigit.c    	\
		ft_isprint.c    	\
		ft_itoa.c			\
		ft_memchr.c     	\
		ft_memcmp.c     	\
		ft_memcpy.c     	\
		ft_memmove.c    	\
		ft_memset.c     	\
		ft_putchar_fd.c 	\
		ft_putendl_fd.c 	\
		ft_putnbr_fd.c  	\
		ft_putstr_fd.c  	\
		ft_split.c      	\
		ft_strchr.c     	\
		ft_strdup.c     	\
		ft_striteri.c   	\
		ft_strjoin.c    	\
		ft_strlcat.c    	\
		ft_strlcpy.c    	\
		ft_strlen.c     	\
		ft_strmapi.c    	\
		ft_strncmp.c    	\
		ft_strnstr.c    	\
		ft_strtrim.c    	\
		ft_strrchr.c    	\
		ft_substr.c     	\
		ft_tolower.c    	\
		ft_toupper.c    	\
		ft_lstadd_back.c  	\
        ft_lstadd_front.c 	\
        ft_lstclear.c     	\
        ft_lstdelone.c    	\
        ft_lstiter.c      	\
        ft_lstlast.c      	\
        ft_lstmap.c       	\
        ft_lstnew.c       	\
        ft_lstsize.c

OBJDIR = obj
OBJS = $(SRCS:%.c=	$(OBJDIR)/%.o)

FT_PRINTF_SRCS = 	ft_printf/ft_abs.c			\
					ft_printf/ft_arg_char.c		\
					ft_printf/ft_arg_hexa.c		\
					ft_printf/ft_arg_int.c 		\
					ft_printf/ft_arg_ptr.c		\
					ft_printf/ft_arg_str.c		\
					ft_printf/ft_arg_uint.c		\
					ft_printf/ft_atoi_size.c	\
					ft_printf/ft_max.c			\
					ft_printf/ft_printf.c		\
					ft_printf/ft_printf_utils.c	\
					ft_printf/ft_putnbr_base.c	\
					ft_printf/ft_putnchar.c		\
					ft_printf/ft_putposnbr.c	\
					ft_printf/ft_search.c		\
					ft_printf/ft_strnchr.c

PRINTFDIR = ft_printf
FT_PRINTF_OBJS = $(FT_PRINTF_SRCS:$(PRINTFDIR)/%.c=$(PRINTFDIR)/$(OBJDIR)/%.o)

GREEN = \033[32m
RED = \033[31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF_OBJS)
	$(AR) $@ $^
	printf "\n\033[1A\033[K"
	printf "$(GREEN)$(NAME) archive created!\n$(RESET)"

$(OBJDIR)/%.o: %.c
	mkdir -p $(dir $@)
	printf "$(GREEN)Generating $(NAME) objects... %-33.33s\r$(RESET)" $@
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTFDIR)/$(OBJDIR)/%.o: $(PRINTFDIR)/%.c
	mkdir -p $(dir $@)
	printf "$(GREEN)Generating $(NAME) objects... %-33.33s\r$(RESET)" $@
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJDIR) $(PRINTFDIR)/$(OBJDIR)
	printf "$(RED)$(NAME) objects deleted!$(RESET)\n"

fclean:
	rm -rf $(NAME)
	rm -rf $(OBJDIR) $(PRINTFDIR)/$(OBJDIR)
	printf "$(RED)$(NAME) and objects deleted!$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
