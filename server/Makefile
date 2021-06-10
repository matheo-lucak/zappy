##
## EPITECH PROJECT, 2021
## Zappy [WSL: Ubuntu]
## File description:
## Makefile
##

#############

#################
# Project files #
#################

INCLUDE_PATH	=	./include/

SRC_PATH		=	./src/

MAIN			=	$(addprefix $(SRC_PATH), main.c)

SRC_PROJECT		=	\

SRC				=	$(SRC_PROJECT) $(MAIN)

#############

#############
# Libraries #
#############

LIBRARIES_PATH		=	./libs/

LIBRARIES			=	my		\
						epinet	\
						mylist

override LDFLAGS	+=	$(addprefix -L, $(LIBRARIES_PATH))

override LDLIBS		+=	$(addprefix -l, $(LIBRARIES))

#############

####################################
# Compilation Flags & Object files #
####################################

CC					=	gcc

override CFLAGS		+=	-W -Wall -Wextra

override CPPFLAGS	+=	-I$(INCLUDE_PATH)

OBJ					=	$(SRC:.c=.o)

PATH_TO_INSTANTIATE	?=	./

override NAME		=	$(PATH_TO_INSTANTIATE)/zappy_server

#############

all:	$(NAME)
.PHONY:	all

$(NAME):	CFLAGS += -O2
$(NAME):	$(LIBRARIES) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

$(LIBRARIES):
	$(MAKE) -C $(LIBRARIES_PATH)$@
.PHONY:	$(LIBRARIES)

debug:	CFLAGS += -g
debug:	fclean $(NAME)
.PHONY:	debug

#############

#########
# Tests #
#########

TESTS_PATH		=	./tests/

TESTS_SRC		=	\

COVERAGE_PATH	=	./coverage/

TESTS_NAME		=	unit_tests

#############

tests_run:	CFLAGS += --coverage
tests_run:	LDLIBS += -lcriterion
tests_run:	$(LIBRARIES)
	@find -name "*.gcno" -name "*.gcda" -delete
	$(CC) -o $(TESTS_NAME) $(SRC_PROJECT) $(TESTS_SRC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	./$(TESTS_NAME) --verbose --always-succeed
	$(RM) $(TESTS_NAME) test*.gcno test*.gcda
	mkdir -p $(COVERAGE_PATH)
	mv *.gcno *.gcda $(COVERAGE_PATH)
.PHONY:	tests_run

coverage:
	gcovr --exclude $(PATH_TESTS)
	gcovr --exclude $(PATH_TESTS) --branches
.PHONY:	coverage

clean:
	for lib in $(LIBRARIES); do $(MAKE) $@ -C $(LIBRARIES_PATH)/$$lib; done;
	$(RM) $(OBJ)
	$(RM) $(TESTS_NAME) *.gcno *.gcda
.PHONY:	clean

fclean:	clean
	for lib in $(LIBRARIES); do $(MAKE) $@ -C $(LIBRARIES_PATH)/$$lib; done;
	$(RM) $(NAME)
.PHONY:	fclean

re::	fclean
re::	all
.PHONY:	re
