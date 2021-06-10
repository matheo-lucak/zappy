##
## EPITECH PROJECT, 2021
## Lib mylist
## File description:
## Makefile
##

include		config.mk

OBJ					=	$(SRC_LIB:.c=.o)

ARFLAGS				=	rc

override CFLAGS		+=	-W -Wall -Wextra

override CPPFLAGS	+=	-I.					\
						-I./container		\
						-I./generic_list	\
						-I./ptr_list		\
						-I./string_list

override NAME		=	libmylist.a

all:	$(NAME) header

$(NAME):	$(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	cp -u $(NAME) ../

header:
	mkdir -p ../../include/
	cp -r $(HEADER) ../../include/

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME) ../$(NAME)

re:	fclean all

.PHONY: all header clean fclean re
