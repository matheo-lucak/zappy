##
## EPITECH PROJECT, 2020
## Epinet
## File description:
## Makefile config
##

CPPFLAGS		=	-Iinclude
CFLAGS			=	-Wall -Wextra -O2
LDFLAGS			=
RM				=	rm -f
TARGET_LIB 		=	libepinet.a
TARGET_TESTS	=	unit_tests
DIR_SRC			=	./src/
DIR_TESTS		=	./tests/
TESTS_FLAGS		=	-lcriterion -lepinet -L. --coverage
OBJS			=	$(addprefix $(DIR_SRC), $(SRCS:.c=.o))
