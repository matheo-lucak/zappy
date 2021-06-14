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

SRC_PROJECT		=	$(addprefix $(SRC_PATH), arg_parser/arg_checker/positive_int.c)			\
					$(addprefix $(SRC_PATH), arg_parser/arg_options/options.c)				\
					$(addprefix $(SRC_PATH), arg_parser/arg_setter/setters/clients_nb.c)	\
					$(addprefix $(SRC_PATH), arg_parser/arg_setter/setters/frequency.c)		\
					$(addprefix $(SRC_PATH), arg_parser/arg_setter/setters/height.c)		\
					$(addprefix $(SRC_PATH), arg_parser/arg_setter/setters/name.c)			\
					$(addprefix $(SRC_PATH), arg_parser/arg_setter/setters/port.c)			\
					$(addprefix $(SRC_PATH), arg_parser/arg_setter/setters/width.c)			\
					$(addprefix $(SRC_PATH), arg_parser/arg_setter/get_from_option.c)		\
					$(addprefix $(SRC_PATH), arg_parser/arg_setter/setters.c)				\
					$(addprefix $(SRC_PATH), arg_parser/parse.c)							\
					$(addprefix $(SRC_PATH), logger/find_message.c)							\
					$(addprefix $(SRC_PATH), logger/logger.c)								\
					$(addprefix $(SRC_PATH), logger/map.c)									\
					$(addprefix $(SRC_PATH), network/start.c)								\
					$(addprefix $(SRC_PATH), network/stop.c)								\
					$(addprefix $(SRC_PATH), server/client/create.c)						\
					$(addprefix $(SRC_PATH), server/client/destroy.c)						\
					$(addprefix $(SRC_PATH), server/run/handle_client_connection.c)			\
					$(addprefix $(SRC_PATH), server/run/handle_clients_in.c)				\
					$(addprefix $(SRC_PATH), server/run/handle_clients_out.c)				\
					$(addprefix $(SRC_PATH), server/launch.c)								\
					$(addprefix $(SRC_PATH), server/run.c)									\
					$(addprefix $(SRC_PATH), server/start.c)								\
					$(addprefix $(SRC_PATH), server/stop.c)									\
					$(addprefix $(SRC_PATH), simulation/direction/get_random.c)				\
					$(addprefix $(SRC_PATH), simulation/drone/create.c)						\
					$(addprefix $(SRC_PATH), simulation/drone/destroy.c)					\
					$(addprefix $(SRC_PATH), simulation/drone/is_drone.c)					\
					$(addprefix $(SRC_PATH), simulation/drone/is_spectator.c)				\
					$(addprefix $(SRC_PATH), simulation/drone/move.c)						\
					$(addprefix $(SRC_PATH), simulation/drone/rotate.c)						\
					$(addprefix $(SRC_PATH), simulation/drone/set_drone.c)					\
					$(addprefix $(SRC_PATH), simulation/map/create.c)						\
					$(addprefix $(SRC_PATH), simulation/map/destroy.c)						\
					$(addprefix $(SRC_PATH), simulation/tile/create.c)						\
					$(addprefix $(SRC_PATH), simulation/tile/destroy.c)						\
					$(addprefix $(SRC_PATH), simulation/start.c)							\
					$(addprefix $(SRC_PATH), simulation/stop.c)								\
					$(addprefix $(SRC_PATH), arguments_default_values.c)					\
					$(addprefix $(SRC_PATH), usage.c)										\

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

PROJECT_OBJ			=	$(SRC_PROJECT:.c=.o)
OBJ					=	$(SRC:.c=.o)

COV_PROJECT_OBJ		=	$(SRC_PROJECT:.c=.gcda) $(SRC_PROJECT:.c=.gcno)

PATH_TO_INSTANTIATE	?=	./

override NAME		=	$(PATH_TO_INSTANTIATE)/zappy_server

#############

all:	$(NAME)
.PHONY:	all

$(NAME):	CFLAGS += -O0
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

TESTS_PATH		=	tests/

TESTS_SRC		=	$(addprefix $(TESTS_PATH), arg_parser/arg_checker/positive_int.c)	\
					$(addprefix $(TESTS_PATH), arg_parser/arg_setter/get_from_option.c)	\
					$(addprefix $(TESTS_PATH), arg_parser/parse_basic_f.c)	\
					$(addprefix $(TESTS_PATH), arg_parser/parse_basic_c.c)	\
					$(addprefix $(TESTS_PATH), arg_parser/parse_basic_n.c)	\
					$(addprefix $(TESTS_PATH), arg_parser/parse_basic_p.c)	\
					$(addprefix $(TESTS_PATH), arg_parser/parse_basic_x.c)	\
					$(addprefix $(TESTS_PATH), arg_parser/parse_basic_y.c)	\
					$(addprefix $(TESTS_PATH), arg_parser/parse.c)	\
					$(addprefix $(TESTS_PATH), simulation/drone/move.c)	\
					$(addprefix $(TESTS_PATH), simulation/drone/rotate.c)	\

TESTS_OBJ		=	$(TESTS_SRC:.c=.o)

COV_TEST_OBJ	=	$(TESTS_SRC:.c=.gcda) $(TESTS_SRC:.c=.gcno)

COVERAGE_PATH	=	./coverage/

TESTS_NAME		=	unit_tests

#############

tests_run:	CFLAGS += --coverage
tests_run:	LDLIBS += -lcriterion
tests_run:	clean $(LIBRARIES) $(PROJECT_OBJ) $(TESTS_OBJ)
	$(CC) -o $(TESTS_NAME) $(PROJECT_OBJ) $(TESTS_OBJ) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	./$(TESTS_NAME) --verbose --always-succeed
	$(RM) $(TESTS_NAME)
.PHONY:	tests_run

coverage:
	gcovr --exclude $(TESTS_PATH)
	gcovr --exclude $(TESTS_PATH) --branches
.PHONY:	coverage

clean:
	for lib in $(LIBRARIES); do $(MAKE) $@ -C $(LIBRARIES_PATH)/$$lib; done;
	$(RM) $(OBJ) $(PROJECT_OBJ) $(TESTS_OBJ)
	$(RM) $(TESTS_NAME)
	$(RM) $(COV_PROJECT_OBJ) $(COV_TEST_OBJ)
.PHONY:	clean

fclean:	clean
	for lib in $(LIBRARIES); do $(MAKE) $@ -C $(LIBRARIES_PATH)/$$lib; done;
	$(RM) $(NAME)
.PHONY:	fclean

re::	fclean
re::	all
.PHONY:	re
