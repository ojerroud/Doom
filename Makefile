# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokartou <yokartou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/12 21:43:25 by yokartou          #+#    #+#              #
#    Updated: 2018/05/04 15:51:03 by yokartou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = doom-nukem
INC_PATH = inc
MINI_PATH = minilibx
vpath %.c src
vpath_h = -I $(INC_PATH) -I $(MINI_PATH) -I libft/$(INC_PATH)
LIB = -L libft/ -lft -L $(MINI_PATH) -lmlx

MINIFLAGS = -framework OpenGL -framework AppKit

OBJDIR := obj
OBJS := $(addprefix $(OBJDIR)/,main.o keyhook.o read.o error.o)

$(OBJDIR)/%.o : %.c
	@$(CC) $(CPPFLAGS) $(CFLAGS) $(vpath_h) -Wall -Wextra -Werror -c \
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