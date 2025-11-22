CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = fdf
RM = rm -rf

SRCS_FOLDER = srcs/
BONUS_SRCS_FOLDER = srcs_bonus/
LIBS_FOLDER = libs/
INCLUDES_FOLDER = includes/
OBJECTS_FOLDER = objects/
BONUS_OBJECTS_FOLDER = bonus_objects/
MLX = $(LIBS_FOLDER)MacroLibX-master/libmlx.so -lSDL2  \

SRCS = $(SRCS_FOLDER)display/pixels_region.c \
	$(SRCS_FOLDER)display/pixels_region_utils.c \
	$(SRCS_FOLDER)display/transform_projection.c \
	$(SRCS_FOLDER)display/update.c \
	$(SRCS_FOLDER)display/window.c \
	$(SRCS_FOLDER)events/key_down.c \
	$(SRCS_FOLDER)events/key_up.c \
	$(SRCS_FOLDER)events/preset.c \
	$(SRCS_FOLDER)events/window_event.c \
	$(SRCS_FOLDER)parsing/parsing.c \
	$(SRCS_FOLDER)parsing/parsing_utils.c \
	$(SRCS_FOLDER)struct_managment/map.c \
	$(SRCS_FOLDER)struct_managment/point.c \
	$(SRCS_FOLDER)struct_managment/update_info.c \
	$(SRCS_FOLDER)fdf.c \

BONUS_SRCS = $(SRCS)

LIBS_SRCS = $(LIBS_FOLDER)ft_printf/ft_printf.c \
	$(LIBS_FOLDER)ft_printf/converters/lltoa.c \
	$(LIBS_FOLDER)ft_printf/utils/printing_utils.c \
	$(LIBS_FOLDER)ft_printf/converters/ulltoa.c \
	$(LIBS_FOLDER)ft_printf/converters/xtoa.c \
	$(LIBS_FOLDER)gnl/get_next_line_bonus.c \
	$(LIBS_FOLDER)gnl/get_next_line_utils_bonus.c \
	$(LIBS_FOLDER)libft/ft_atoi.c \
	$(LIBS_FOLDER)libft/ft_bzero.c \
	$(LIBS_FOLDER)libft/ft_calloc.c \
	$(LIBS_FOLDER)libft/ft_isdigit.c \
	$(LIBS_FOLDER)libft/ft_strchr.c \
	$(LIBS_FOLDER)libft/ft_strlen.c \
	$(LIBS_FOLDER)libft/ft_toupper.c \

SRCS_OBJS = $(addprefix $(OBJECTS_FOLDER),$(SRCS:.c=.o))
LIBS_OBJS = $(addprefix $(OBJECTS_FOLDER),$(LIBS_SRCS:.c=.o))
BONUS_OBJS = $(addprefix $(BONUS_OBJECTS_FOLDER),$(BONUS_SRCS:.c=.o))

all: $(NAME)

$(NAME): $(SRCS_OBJS) $(LIBS_OBJS)
	$(CC) $(CFLAGS) $^ $(MLX) -lm -o $@

bonus: $(BONUS_OBJS) $(LIBS_OBJS)
	$(CC) $(CFLAGS) $^ $(MLX) -lm -o $@ 

$(OBJECTS_FOLDER)%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INCLUDES_FOLDER) -c $< -o $@

$(BONUS_OBJECTS_FOLDER)%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INCLUDES_FOLDER) -D BONUS=1 -c $< -o $@

clean:
	$(RM) $(OBJECTS_FOLDER)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
