NAME = libft.a

SRC_DIR = src/
OBJ_DIR = obj/
INCLUDES = includes/

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES)

FT_IS_DIR = ft_is/
FT_IS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c

FT_LST_DIR = ft_lst/
FT_LST =\
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

FT_MEM_DIR = ft_mem/
FT_MEM =\
	ft_bzero.c \
	ft_calloc.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c

FT_PRINTF_DIR = ft_printf/
FT_PRINTF =\
	ft_itoa_mod.c \
	ft_print_unsigned.c \
	ft_printf_utils.c \
	ft_printf.c \
	ft_printhex.c \
	ft_printnum.c \
	ft_printptr.c \
	ft_to_bighex.c \
	ft_to_hex.c \
	ft_utoa.c

FT_PUT_DIR = ft_put/
FT_PUT =\
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c

FT_STR_DIR = ft_str/
FT_STR =\
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c

FT_TO_DIR = ft_to/
FT_TO =\
	ft_atoi.c \
	ft_atoi_base.c \
	ft_atoi_safe.c \
	ft_itoa.c \
	ft_tolower.c \
	ft_toupper.c

GNL_DIR = gnl/
GNL = get_next_line.c get_next_line_utils.c

SRC_FILES =\
	$(addprefix $(FT_IS_DIR), $(FT_IS)) \
	$(addprefix $(FT_LST_DIR), $(FT_LST)) \
	$(addprefix $(FT_MEM_DIR), $(FT_MEM)) \
	$(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF)) \
	$(addprefix $(FT_PUT_DIR), $(FT_PUT)) \
	$(addprefix $(FT_STR_DIR), $(FT_STR)) \
	$(addprefix $(FT_TO_DIR), $(FT_TO)) \
	$(addprefix $(GNL_DIR), $(GNL))

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))


OBJ_FLAG = .cache_exists

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_FLAG)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_FLAG):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)$(FT_IS_DIR)
	@mkdir -p $(OBJ_DIR)$(FT_LST_DIR)
	@mkdir -p $(OBJ_DIR)$(FT_MEM_DIR)
	@mkdir -p $(OBJ_DIR)$(FT_PRINTF_DIR)
	@mkdir -p $(OBJ_DIR)$(FT_PUT_DIR)
	@mkdir -p $(OBJ_DIR)$(FT_STR_DIR)
	@mkdir -p $(OBJ_DIR)$(FT_TO_DIR)
	@mkdir -p $(OBJ_DIR)$(GNL_DIR)
	@touch $(OBJ_FLAG)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(OBJ_FLAG)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
