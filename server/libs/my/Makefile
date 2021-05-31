##
## Personnal C Library
## GuillaumeBgd - Advanced_C_Library
## File description:
## Makefile use for libmy compilation
##

LIB_DIR_PATH		=	../

ROOT_DIR_PATH		=	../../

PATH_TO_COPY		=	$(ROOT_DIR_PATH)include/

LIBRARY_HEADERS		=	$(wildcard include/*)

COPIED_HEADERS		=	$(addprefix $(ROOT_DIR_PATH), $(LIBRARY_HEADERS))

####

SRC					=	get_next_line.c

OBJ					=	$(SRC:.c=.o)

####

override CFLAGS		=	-W -Wall -Wextra -Wshadow

override CPPFLAGS	+=	-I./

####

LIB_NAME			=	my

override NAME		=	$(addprefix lib, $(LIB_NAME).a)

####

AR					=	ar rc

####

all:	$(NAME)
.PHONY:	all

$(NAME):	$(OBJ)
	$(AR) $(NAME) $(OBJ)
	mv $(NAME) $(LIB_DIR_PATH)
	mkdir -p $(PATH_TO_COPY)
	cp -r $(LIBRARY_HEADERS) $(PATH_TO_COPY)

clean:
	$(RM) $(OBJ)
.PHONY:	clean

fclean:	clean
	-$(RM) $(NAME)
	-$(RM) $(LIB_DIR_PATH)$(NAME)
	-$(RM) -r $(COPIED_HEADERS)
.PHONY:	fclean

re::	fclean
re::	all
.PHONY:	re
