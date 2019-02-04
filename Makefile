# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/01 11:55:28 by ojerroud          #+#    #+#              #
#    Updated: 2019/02/01 11:55:30 by ojerroud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = doom-nukem
INC_PATH = inc
MINI_PATH = minilibx
FLAGS = -Wall -Wextra -Werror
vpath %.c src
vpath_h = -I $(INC_PATH) -I $(MINI_PATH) -I libft/includes
LIB = -L libft/ -lft -L $(MINI_PATH) -lmlx

MINIFLAGS = -framework OpenGL -framework AppKit

OBJDIR := obj
OBJS := $(addprefix $(OBJDIR)/,main.o error.o init.o keyboard.o reader.o)

$(OBJDIR)/%.o : %.c
	@$(CC) $(FLAGS) $(vpath_h) -c \
	$(OUTPUT_OPTION) $<

all : $(OBJS)
	@make -C libft/
	@make -C $(MINI_PATH)
	@$(CC) $(LIB) -o $(NAME) $(OBJS) $(MINIFLAGS)

recomp : $(OGJS)
	@$(CC) $(LIB) -o $(NAME) $(OBJS) $(MINIFLAGS)

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	@mkdir $(OBJDIR)

clean :
	@make clean -C libft
	@/bin/rm -rf $(OBJDIR)
	@echo "clean.."

fclean : clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all