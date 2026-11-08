NAME = libftprintf.a
CC = cc
AR = ar rcs
TEST_O = a.out
test: DEBUG = -g
all: DEBUG =
CFLAGS = -Wall -Wextra -Werror
NEUTRAL = \033[0;0m
RED = \033[0;31m
YELLOW = \033[0;33m
GREEN = \033[0;32m
BLUE = \033[0;34m

SRCS = libft/ft_atoi.c \
	   libft/ft_bzero.c \
	   libft/ft_calloc.c \
	   libft/ft_isalnum.c \
	   libft/ft_isalpha.c \
	   libft/ft_isascii.c \
	   libft/ft_isdigit.c \
	   libft/ft_isprint.c \
	   libft/ft_itoa.c \
	   libft/ft_itoh.c \
	   libft/ft_lstadd_back.c \
	   libft/ft_lstadd_front.c \
	   libft/ft_lstclear.c \
	   libft/ft_lstdelone.c \
	   libft/ft_lstiter.c \
	   libft/ft_lstlast.c \
	   libft/ft_lstmap.c \
	   libft/ft_lstnew.c \
	   libft/ft_lstsize.c \
	   libft/ft_memchr.c \
	   libft/ft_memcmp.c \
	   libft/ft_memcpy.c \
	   libft/ft_memmove.c \
	   libft/ft_memset.c \
	   libft/ft_ptoh.c \
	   libft/ft_putchar_fd.c \
	   libft/ft_putendl_fd.c \
	   libft/ft_putnbr_fd.c \
	   libft/ft_putstr_fd.c \
	   libft/ft_split.c \
	   libft/ft_strchr.c \
	   libft/ft_strdup.c \
	   libft/ft_strfind.c \
	   libft/ft_striteri.c \
	   libft/ft_strjoin.c \
	   libft/ft_strlcat.c \
	   libft/ft_strlcpy.c \
	   libft/ft_strlen.c \
	   libft/ft_strmapi.c \
	   libft/ft_strncmp.c \
	   libft/ft_strnstr.c \
	   libft/ft_strrchr.c \
	   libft/ft_strtrim.c \
	   libft/ft_substr.c \
	   libft/ft_tolower.c \
	   libft/ft_toupper.c \
	   buffft/ft_buff_append.c \
	   buffft/ft_buff_append_2.c \
	   buffft/ft_buff_assign.c \
	   buffft/ft_buff_destroy.c \
	   buffft/ft_buff_double_size.c \
	   buffft/ft_buff_erase.c \
	   buffft/ft_buff_init.c \
	   buffft/ft_buff_insert.c \
	   buffft/ft_buff_insert_2.c \
	   buffft/ft_buff_print.c
PRINTF_SRCS = printfft/ft_printf_parse.c \
			  printfft/ft_printf_parse_2.c \
			  printfft/ft_printf.c
PRINTF_BONUS_SRCS = printfft_bonus/ft_printf.c \
					printfft_bonus/ft_printf_parse.c \
					printfft_bonus/ft_printf_parse_2.c \
					printfft_bonus/ft_printf_parse_format.c
OBJS = $(SRCS:.c=.o)
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)
PRINTF_BONUS_OBJS = $(PRINTF_BONUS_SRCS:.c=.o)

all: $(NAME)

re: fclean all

test: $(OBJS) $(PRINTF_BONUS_OBJS)
	@$(CC) $(CFLAGS) -I. $(DEBUG) main.c $^ -o $(TEST_O)
	@printf "${YELLOW}Building ${BLUE}$@\n${NEUTRAL}"
	@printf "${GREEN}Testing...\n${NEUTRAL}"
	@valgrind ./$(TEST_O)
	@printf "${GREEN}Tests ended...\n${NEUTRAL}"

$(NAME): $(OBJS) $(PRINTF_OBJS)
	@$(AR) $@ $^
	@printf "${YELLOW}Building library ${BLUE}${NAME}\n${NEUTRAL}"

bonus: $(OBJS) $(PRINTF_BONUS_OBJS)
	@$(AR) $(NAME) $^
	@printf "${YELLOW}Building library ${BLUE}${NAME} with bonus\n${NEUTRAL}"

%.o: %.c
	@$(CC) $(CFLAGS) -I. $(DEBUG) -o $@ -c $^
	@printf "${YELLOW}Compiling object file ${BLUE}$@\n${NEUTRAL}"

fclean: clean
	@rm -f $(NAME) $(TEST_O)
	@printf "${RED}Deleting archives and binaries\n${NEUTRAL}"

clean:
	@rm -f $(OBJS) $(PRINTF_OBJS) $(PRINTF_BONUS_OBJS)
	@printf "${RED}Deleting object files\n${NEUTRAL}"

.PHONY: ftest test all fclean clean re bonus
