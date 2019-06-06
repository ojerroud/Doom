# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/01 11:55:28 by ojerroud          #+#    #+#              #
#    Updated: 2019/06/06 13:57:29 by ojerroud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = doom-nukem
INC_PATH = inc
MINI_PATH = minilibx
LIBFT_PATH = libft/
HEADER = inc/DoomNukem.h
FLAGS = -Wall -Wextra -Werror
vpath %.c src editor/src
vpath_h = -I $(INC_PATH) -I $(MINI_PATH) -I $(LIBFT_PATH)includes
LIB = -L $(LIBFT_PATH) -lft -L $(MINI_PATH) -lmlx

MINIFLAGS = -framework OpenGL -framework AppKit

OBJDIR := obj
OBJS := $(addprefix $(OBJDIR)/,main.o error.o init.o keyboard.o reader.o mouse.o test.o)

$(OBJDIR)/%.o : %.c $(HEADER)
	$(CC) $(FLAGS) $(vpath_h) -c \
	$(OUTPUT_OPTION) $<

all : $(OBJS)
	@make -C $(LIBFT_PATH)
	@make -C $(MINI_PATH)
	@$(CC) $(LIB) -o $(NAME) $(OBJS) $(MINIFLAGS)

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	@mkdir $(OBJDIR)

clean :
	@make clean -C libft
	@/bin/rm -rf $(OBJDIR) $(OBJDIR_EDITOR)
	@echo "clean.."

fclean : clean
	@make fclean -C libft
	@/bin/rm -f $(NAME) $(EDITOR)

re: fclean all