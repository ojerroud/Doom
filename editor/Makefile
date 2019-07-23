# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/01 11:55:28 by ojerroud          #+#    #+#              #
#    Updated: 2019/07/03 17:02:12 by ojerroud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = doom-nukem-editor
INC_PATH = inc
MINI_PATH = ../minilibx/
LIBFT_PATH = ../libft/
HEADER = inc/editor.h
FLAGS = -Wall -Wextra -Werror 
SANITIZE = -fsanitize=address -g
vpath %.c src
vpath_h = -I $(INC_PATH) -I $(MINI_PATH) -I $(LIBFT_PATH)includes
LIBS = -L $(LIBFT_PATH) -lft -L $(MINI_PATH) -lmlx

MINIFLAGS = -framework OpenGL -framework AppKit

OBJDIR := obj
OBJS := $(addprefix $(OBJDIR)/,main.o init.o draw.o error.o keyboard.o mouse.o\
texture.o list_utils.o imgs.o init_img.o tabdraw.o utils.o portal.o central.o\
sav_map.o sprite.o)



$(OBJDIR)/%.o : %.c $(HEADER)
	$(CC) $(FLAGS) $(vpath_h) -c \
	$(OUTPUT_OPTION) $<
	
all : $(OBJS)
	@make -C $(LIBFT_PATH)
	@make -C $(MINI_PATH)
	@$(CC) $(LIBS) -o $(NAME) $(OBJS) $(MINIFLAGS)

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	@mkdir $(OBJDIR)

clean :
	@make clean -C $(LIBFT_PATH)
	@/bin/rm -rf $(OBJDIR)
	@echo "clean.."

fclean : clean
	@make fclean -C $(LIBFT_PATH)
	@/bin/rm -f $(NAME)

re: fclean all