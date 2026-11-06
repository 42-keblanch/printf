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

SRCS = libft/ft_calloc.c \
	   libft/ft_itoa.c \
	   libft/ft_itoh.c \
	   libft/ft_memcpy.c \
	   libft/ft_ptoh.c \
	   libft/ft_putstr_fd.c \
	   libft/ft_strdup.c \
	   libft/ft_strfind.c \
	   libft/ft_strlcpy.c \
	   libft/ft_strlen.c \
	   libft/ft_strncmp.c \
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
	   buffft/ft_buff_print.c \
	   buffft/ft_buff_substr.c
PRINTF_SRCS = printfft/ft_printf_parse.c \
			  printfft/ft_printf_parse_2.c \
			  printfft/ft_printf.c
PRINTF_BONUS_SRCS = printfft_bonus/ft_printf.c \
					printfft_bonus/ft_printf_parse.c \
					printfft_bonus/ft_printf_parse_2.c \
					printfft_bonus/ft_printf_parse_spec.c
OBJS = $(SRCS:.c=.o)
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)
PRINTF_BONUS_OBJS = $(PRINTF_BONUS_SRCS:.c=.o)

all: $(NAME)

re: fclean all

test: $(OBJS) $(PRINTF_BONUS_OBJS)
	@$(CC) $(CFLAGS) $(DEBUG) main.c $^ -o $(TEST_O)
	@printf "${YELLOW}Building ${BLUE}$@\n${NEUTRAL}"
	@printf "${GREEN}Testing...\n${NEUTRAL}"
	@./$(TEST_O) | cat -e
	@printf "${GREEN}Tests ended...\n${NEUTRAL}"

$(NAME): $(OBJS) $(PRINTF_OBJS)
	@$(AR) $@ $^
	@printf "${YELLOW}Building library ${BLUE}${NAME}\n${NEUTRAL}"

bonus: $(OBJS) $(PRINTF_BONUS_OBJS)
	@$(AR) $(NAME) $^
	@printf "${YELLOW}Building library ${BLUE}${NAME} with bonus\n${NEUTRAL}"

%.o: %.c
	@$(CC) $(CFLAGS) $(DEBUG) -o $@ -c $^
	@printf "${YELLOW}Compiling object file ${BLUE}$@\n${NEUTRAL}"

fclean: clean
	@rm -f $(NAME) $(TEST_O)
	@printf "${RED}Deleting archives and binaries\n${NEUTRAL}"

clean:
	@rm -f $(OBJS) $(PRINTF_OBJS) $(PRINTF_BONUS_OBJS)
	@printf "${RED}Deleting object files\n${NEUTRAL}"

.PHONY: ftest test all fclean clean re bonus
