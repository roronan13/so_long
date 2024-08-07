NAME		=	so_long

SRCS		=	so_long.c\
				utils.c\
				my_parsing/check_and_create_tab.c\
				my_parsing/check_errors.c\
				my_parsing/checks_1.c\
				my_parsing/checks_2.c\
				my_parsing/check_path.c\
				my_mlx/mlx_init.c\
				my_mlx/mlx_init_2.c\
				get_next_line/get_next_line.c\
				get_next_line/get_next_line_utils.c

OBJS		=	$(SRCS:.c=.o)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -g3

RM			=	rm -rf

MAKE_LIBFT	= $(MAKE) -C ./libft

LIBFT		= ./libft/libft.a

MAKE_FT_PRINTF	= $(MAKE) -C ./ft_printf

FT_PRINTF	= ./ft_printf/libftprintf.a

INCLUDE		= -I ./

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE) 

all			:	$(NAME)

$(LIBFT)	:
				$(MAKE_LIBFT)

$(FT_PRINTF)	:	
					$(MAKE_FT_PRINTF)

$(NAME)		:	$(OBJS) | $(LIBFT) $(FT_PRINTF)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(FT_PRINTF) ./.MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
#				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(FT_PRINTF) ./MLX42/build/libmlx42.a -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.4/lib" -fsanitize=address -g3

clean		:	
				$(RM) $(OBJS)
				$(MAKE_LIBFT) clean
				$(MAKE_FT_PRINTF) clean

fclean		:	clean
				$(RM) $(NAME)
				$(MAKE_LIBFT) fclean
				$(MAKE_FT_PRINTF) fclean

re			:	fclean
				make fclean -C libft
				make fclean -C ft_printf
				make -C libft
				make -C ft_printf
				make

.PHONY		:	all clean fclean re