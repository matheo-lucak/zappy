##
## EPITECH PROJECT, 2021
## Lib mylist
## File description:
## Makefile
##

include		config.mk

LIB_DIR_PATH		=	../

ROOT_DIR_PATH		=	../../

PATH_TO_COPY		=	$(ROOT_DIR_PATH)include/

COPIED_HEADERS		=	$(addprefix $(PATH_TO_COPY), $(HEADERS))

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
	mkdir -p $(PATH_TO_COPY)
	cp -r $(HEADERS) $(PATH_TO_COPY)

clean:
	$(RM) $(OBJ)
	$(RM) -r $(COPIED_HEADERS)

fclean:	clean
	$(RM) $(NAME) ../$(NAME)

re:	fclean all

.PHONY: all header clean fclean re
