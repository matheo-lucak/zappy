##
## EPITECH PROJECT, 2021
## Lib my_elf
## File description:
## Makefile
##

LIB_DIR_PATH		=	../

ROOT_DIR_PATH		=	../../

PATH_TO_COPY		=	$(ROOT_DIR_PATH)include/

LIBRARY_HEADERS		=	$(wildcard include/*)

COPIED_HEADERS		=	$(addprefix $(ROOT_DIR_PATH), $(LIBRARY_HEADERS))

####

SRC			=	my_list.c				\
				my_create_node.c		\
				my_insert_in_list.c		\
				my_list_to_str.c		\
				my_list_to_2d_array.c	\
				my_2d_array_to_list.c	\
				my_concat_str_list.c	\
				my_free_list.c			\
				my_concat_list.c		\
				my_rev_list.c			\
				my_list_dup.c			\
				my_node.c				\
				my_node_from.c			\
				my_find_node.c			\
				my_remove_node.c		\
				my_delete_node.c		\
				my_delete_node_from.c	\
				rotate_list.c

OBJ			=	$(SRC:.c=.o)

####

override ARFLAGS	=	rc

override CFLAGS		+=	-W -Wall -Wextra

override CPPFLAGS	+=	-I./include/

override NAME		=	libmylist.a

####

all:	$(NAME)
.PHONY:	all

$(NAME):	$(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	cp -u $(NAME) ../
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
