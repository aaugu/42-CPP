# Colour codes
GREEN	=	\033[0;32m
CYAN	=	\033[0;36m
CYAN_B	=	\033[1;96m

NAME	=	cpp00_ex00
CC		=	g++
FLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-I
RM		=	rm -rf

OBJ_D 	=	objs/
SRC		=	tests \

SRCS	=	$(addsuffix .cpp, $(SRC))
OBJ		=	$(SRC:%.c=%.o)
OBJS	=	$(addprefix $(OBJ_D), $(addsuffix .o, $(OBJ)))

$(OBJ_D)%.o : %.cpp
			@mkdir -p $(OBJ_D)
			@($(CC) $(FLAGS) $(INCLUDE) -c $< -o $@)

all:		$(NAME)

$(NAME):	$(OBJS)
			@($(CC) $(FLAGS) $(INCLUDE) $(OBJS) -o $(NAME))
			@echo "$(CYAN) [ OK ] | $(CYAN_B)$(NAME)$(END) $(CYAN)ready!$(END)"

clean:
			@($(RM) $(OBJ_D))
			@echo "$(GREEN) [ OK ] | Objects removed!$(END)"

fclean: 	clean
			@($(RM) $(NAME))
			@echo "$(GREEN) [ OK ] | Everything is clean!$(END)"

re: 		fclean all

.PHONY:		all clean fclean re
