##
## Personnal C Library
## GuillaumeBgd - Advanced_C_Library
## File description:
## Makefile use for libmy compilation
##

###################

INCLUDE_PATH		=	./

###################
# Files Traceback #
###################

LIBS_DIR_PATH		=	../

ROOT_DIR_PATH		=	../../

PATH_TO_COPY		=	$(ROOT_DIR_PATH)include/

LIBRARY_HEADERS		=	$(wildcard *.h)

COPIED_HEADERS		=	$(addprefix $(PATH_TO_COPY), $(LIBRARY_HEADERS))

###################

SRC					=	my_get_nbr.c	\
						my_is_digit.c	\
						my_str_cat.c	\
						my_str_len.c	\

OBJ					=	$(SRC:.c=.o)

#####################
# Compilation Flags #
#####################

override CFLAGS		=	-W -Wall -Wextra -Wshadow

override CPPFLAGS	+=	-I./

override LDFLAGS	+=

override LDLIBS		+=

###########
# Outputs #
###########

LIB_NAME			=	my

override NAME		=	$(addprefix lib, $(LIB_NAME).a)

###########

AR					=	ar rc

###########

all:	$(NAME)
.PHONY:	all

$(NAME):	$(OBJ)
	$(AR) $(NAME) $(OBJ)
	mv $(NAME) $(LIBS_DIR_PATH)
	mkdir -p $(PATH_TO_COPY)
	cp -r $(LIBRARY_HEADERS) $(PATH_TO_COPY)

clean:
	$(RM) $(OBJ)
.PHONY:	clean

fclean:	clean
	$(RM) $(LIBS_DIR_PATH)$(NAME)
	$(RM) -r $(COPIED_HEADERS)
.PHONY:	fclean

re::	fclean
re::	all
.PHONY:	re
