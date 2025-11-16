CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = fdf
RM = rm -rf

SRCS_FOLDER = srcs/
BONUS_SRCS_FOLDER = srcs_bonus/
LIBS_FOLDER = libs/
INCLUDES_FOLDER = includes/
OBJECTS_FOLDER = objects/

SRCS = 

BONUS_SRCS = 

LIBS_SRCS = $(LIBS_FOLDER)ft_printf/ft_printf.c \
	$(LIBS_FOLDER)ft_printf/lltoa.c \
	$(LIBS_FOLDER)ft_printf/printing_utils.c \
	$(LIBS_FOLDER)ft_printf/ulltoa.c \
	$(LIBS_FOLDER)ft_printf/xtoa.c \
	$(LIBS_FOLDER)gnl/get_next_line_bonus.c \
	$(LIBS_FOLDER)gnl/get_next_line_utils_bonus.c \

SRCS_OBJS = $(addprefix $(OBJECTS_FOLDER),$(SRCS:.c=.o))
LIBS_OBJS = $(addprefix $(OBJECTS_FOLDER),$(LIBS_SRCS:.c=.o))
BONUS_OBJS = $(addprefix $(OBJECTS_FOLDER),$(BONUS_SRCS:.c=.o))

all: $(NAME)

$(NAME): $(SRCS_OBJS) $(LIBS_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

bonus: $(BONUS_OBJS) $(LIBS_OBJS)
	$(CC) $(CFLAGS) $^ /libs/MacroLibX-master/[libmlx.so -lSDL2 -o $@ 

$(OBJECTS_FOLDER)%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INCLUDES_FOLDER) -c $< -o $@

clean:
	$(RM) $(OBJECTS_FOLDER)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
