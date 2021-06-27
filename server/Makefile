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

SRC_PROJECT		=	$(addprefix $(SRC_PATH), arg_parser/arg_checker/positive_int.c)				\
					$(addprefix $(SRC_PATH), arg_parser/arg_options/options.c)					\
					$(addprefix $(SRC_PATH), arg_parser/arg_setter/setters/clients_nb.c)		\
					$(addprefix $(SRC_PATH), arg_parser/arg_setter/setters/frequency.c)			\
					$(addprefix $(SRC_PATH), arg_parser/arg_setter/setters/height.c)			\
					$(addprefix $(SRC_PATH), arg_parser/arg_setter/setters/name.c)				\
					$(addprefix $(SRC_PATH), arg_parser/arg_setter/setters/port.c)				\
					$(addprefix $(SRC_PATH), arg_parser/arg_setter/setters/width.c)				\
					$(addprefix $(SRC_PATH), arg_parser/arg_setter/get_from_option.c)			\
					$(addprefix $(SRC_PATH), arg_parser/arg_setter/setters.c)					\
					$(addprefix $(SRC_PATH), arg_parser/parse.c)								\
					$(addprefix $(SRC_PATH), logger/find_message.c)								\
					$(addprefix $(SRC_PATH), logger/logger.c)									\
					$(addprefix $(SRC_PATH), logger/map.c)										\
					$(addprefix $(SRC_PATH), network/handle_client_connection.c)				\
					$(addprefix $(SRC_PATH), network/handle_clients_in.c)						\
					$(addprefix $(SRC_PATH), network/handle_clients_out.c)						\
					$(addprefix $(SRC_PATH), network/start.c)									\
					$(addprefix $(SRC_PATH), network/stop.c)									\
					$(addprefix $(SRC_PATH), server/client/add_request.c)						\
					$(addprefix $(SRC_PATH), server/client/add_response.c)						\
					$(addprefix $(SRC_PATH), server/client/block.c)								\
					$(addprefix $(SRC_PATH), server/client/create.c)							\
					$(addprefix $(SRC_PATH), server/client/destroy.c)							\
					$(addprefix $(SRC_PATH), server/client/to.c)								\
					$(addprefix $(SRC_PATH), server/request/checkers/is_positive_int.c)			\
					$(addprefix $(SRC_PATH), server/request/checkers/is_resource.c)				\
					$(addprefix $(SRC_PATH), server/request/checkers/no_check.c)				\
					$(addprefix $(SRC_PATH), server/request/handlers/cmd_broadcast.c)			\
					$(addprefix $(SRC_PATH), server/request/handlers/cmd_connect_nbr.c)			\
					$(addprefix $(SRC_PATH), server/request/handlers/cmd_eject.c)				\
					$(addprefix $(SRC_PATH), server/request/handlers/cmd_fork.c)				\
					$(addprefix $(SRC_PATH), server/request/handlers/cmd_forward.c)				\
					$(addprefix $(SRC_PATH), server/request/handlers/cmd_incantation.c)			\
					$(addprefix $(SRC_PATH), server/request/handlers/cmd_inventory.c)			\
					$(addprefix $(SRC_PATH), server/request/handlers/cmd_left.c)				\
					$(addprefix $(SRC_PATH), server/request/handlers/cmd_look.c)				\
					$(addprefix $(SRC_PATH), server/request/handlers/cmd_right.c)				\
					$(addprefix $(SRC_PATH), server/request/handlers/cmd_set.c)					\
					$(addprefix $(SRC_PATH), server/request/handlers/cmd_take.c)				\
					$(addprefix $(SRC_PATH), server/request/handlers/default.c)					\
					$(addprefix $(SRC_PATH), server/request/handlers/gui_map_content.c)			\
					$(addprefix $(SRC_PATH), server/request/handlers/gui_map_size.c)			\
					$(addprefix $(SRC_PATH), server/request/handlers/gui_player_inventory.c)	\
					$(addprefix $(SRC_PATH), server/request/handlers/gui_player_level.c)		\
					$(addprefix $(SRC_PATH), server/request/handlers/gui_player_position.c)		\
					$(addprefix $(SRC_PATH), server/request/handlers/gui_team_names.c)			\
					$(addprefix $(SRC_PATH), server/request/handlers/gui_tile_content.c)		\
					$(addprefix $(SRC_PATH), server/request/handlers/gui_time_unit_modif.c)		\
					$(addprefix $(SRC_PATH), server/request/handlers/gui_time_unit_request.c)	\
					$(addprefix $(SRC_PATH), server/request/info/get_info.c)					\
					$(addprefix $(SRC_PATH), server/request/info/info.c)						\
					$(addprefix $(SRC_PATH), server/request/checker.c)							\
					$(addprefix $(SRC_PATH), server/request/create.c)							\
					$(addprefix $(SRC_PATH), server/request/destroy.c)							\
         			$(addprefix $(SRC_PATH), server/request/get_input.c)						\
					$(addprefix $(SRC_PATH), server/request/handle.c)							\
					$(addprefix $(SRC_PATH), server/request/parse.c)							\
					$(addprefix $(SRC_PATH), server/response/create.c)							\
					$(addprefix $(SRC_PATH), server/response/destroy.c)							\
					$(addprefix $(SRC_PATH), server/find_client_from_drone.c)					\
					$(addprefix $(SRC_PATH), server/launch.c)									\
					$(addprefix $(SRC_PATH), server/remove_client.c)							\
					$(addprefix $(SRC_PATH), server/run.c)										\
					$(addprefix $(SRC_PATH), server/start.c)									\
					$(addprefix $(SRC_PATH), server/stop.c)										\
					$(addprefix $(SRC_PATH), simulation/direction/get_eject_direction.c)		\
					$(addprefix $(SRC_PATH), simulation/direction/get_random.c)					\
					$(addprefix $(SRC_PATH), simulation/drone/create.c)							\
					$(addprefix $(SRC_PATH), simulation/drone/destroy.c)						\
					$(addprefix $(SRC_PATH), simulation/drone/eject.c)							\
					$(addprefix $(SRC_PATH), simulation/drone/move.c)							\
					$(addprefix $(SRC_PATH), simulation/drone/rotate.c)							\
					$(addprefix $(SRC_PATH), simulation/egg/create.c)							\
					$(addprefix $(SRC_PATH), simulation/egg/destroy.c)							\
					$(addprefix $(SRC_PATH), simulation/handle/eggs.c)							\
					$(addprefix $(SRC_PATH), simulation/handle/incantations.c)					\
					$(addprefix $(SRC_PATH), simulation/incantation/check.c)					\
					$(addprefix $(SRC_PATH), simulation/incantation/create.c)					\
					$(addprefix $(SRC_PATH), simulation/incantation/destroy.c)					\
					$(addprefix $(SRC_PATH), simulation/incantation/elevate.c)					\
					$(addprefix $(SRC_PATH), simulation/incantation/find_requirements.c)		\
					$(addprefix $(SRC_PATH), simulation/incantation/remove_owner.c)				\
					$(addprefix $(SRC_PATH), simulation/incantation/requirements.c)				\
					$(addprefix $(SRC_PATH), simulation/inventory/add_item.c)					\
					$(addprefix $(SRC_PATH), simulation/inventory/create.c)						\
					$(addprefix $(SRC_PATH), simulation/inventory/destroy.c)					\
					$(addprefix $(SRC_PATH), simulation/inventory/get_deraumere_info.c)			\
					$(addprefix $(SRC_PATH), simulation/inventory/get_food_info.c)				\
					$(addprefix $(SRC_PATH), simulation/inventory/get_item_info.c)				\
					$(addprefix $(SRC_PATH), simulation/inventory/get_linemate_info.c)			\
					$(addprefix $(SRC_PATH), simulation/inventory/get_mendiane_info.c)			\
					$(addprefix $(SRC_PATH), simulation/inventory/get_phiras_info.c)			\
					$(addprefix $(SRC_PATH), simulation/inventory/get_sibur_info.c)				\
					$(addprefix $(SRC_PATH), simulation/inventory/get_thystame_info.c)			\
					$(addprefix $(SRC_PATH), simulation/inventory/remove_item.c)				\
					$(addprefix $(SRC_PATH), simulation/map/create.c)							\
					$(addprefix $(SRC_PATH), simulation/map/destroy.c)							\
					$(addprefix $(SRC_PATH), simulation/resource/get_info.c)					\
					$(addprefix $(SRC_PATH), simulation/resource/info.c)						\
					$(addprefix $(SRC_PATH), simulation/team/add_drone.c)						\
					$(addprefix $(SRC_PATH), simulation/team/add_egg.c)							\
					$(addprefix $(SRC_PATH), simulation/team/create.c)							\
					$(addprefix $(SRC_PATH), simulation/team/delete_drone.c)					\
					$(addprefix $(SRC_PATH), simulation/team/destroy.c)							\
					$(addprefix $(SRC_PATH), simulation/team/has_drone.c)						\
					$(addprefix $(SRC_PATH), simulation/tile/add_drone.c)						\
					$(addprefix $(SRC_PATH), simulation/tile/add_item.c)						\
					$(addprefix $(SRC_PATH), simulation/tile/count_drone.c)						\
					$(addprefix $(SRC_PATH), simulation/tile/count_item.c)						\
					$(addprefix $(SRC_PATH), simulation/tile/create.c)							\
					$(addprefix $(SRC_PATH), simulation/tile/destroy.c)							\
					$(addprefix $(SRC_PATH), simulation/tile/remove_drone.c)					\
					$(addprefix $(SRC_PATH), simulation/tile/remove_item.c)						\
					$(addprefix $(SRC_PATH), simulation/find_team_from_drone.c)					\
					$(addprefix $(SRC_PATH), simulation/handle.c)								\
					$(addprefix $(SRC_PATH), simulation/remove_drone.c)							\
					$(addprefix $(SRC_PATH), simulation/start.c)								\
					$(addprefix $(SRC_PATH), simulation/stop.c)									\
					$(addprefix $(SRC_PATH), arguments_default_values.c)						\
					$(addprefix $(SRC_PATH), usage.c)											\

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

TESTS_SRC		=	$(addprefix $(TESTS_PATH), arg_parser/arg_checker/positive_int.c)		\
					$(addprefix $(TESTS_PATH), arg_parser/arg_setter/get_from_option.c)		\
					$(addprefix $(TESTS_PATH), arg_parser/parse_basic_f.c)					\
					$(addprefix $(TESTS_PATH), arg_parser/parse_basic_c.c)					\
					$(addprefix $(TESTS_PATH), arg_parser/parse_basic_n.c)					\
					$(addprefix $(TESTS_PATH), arg_parser/parse_basic_p.c)					\
					$(addprefix $(TESTS_PATH), arg_parser/parse_basic_x.c)					\
					$(addprefix $(TESTS_PATH), arg_parser/parse_basic_y.c)					\
					$(addprefix $(TESTS_PATH), arg_parser/parse.c)							\
					$(addprefix $(TESTS_PATH), server/request/checkers/is_positive_int.c)	\
					$(addprefix $(TESTS_PATH), server/request/checkers/is_resource.c)		\
					$(addprefix $(TESTS_PATH), server/request/handler/cmd_forward.c)		\
					$(addprefix $(TESTS_PATH), server/request/handler/cmd_left.c)			\
					$(addprefix $(TESTS_PATH), server/request/handler/cmd_right.c)			\
					$(addprefix $(TESTS_PATH), server/request/handler/cmd_set.c)			\
					$(addprefix $(TESTS_PATH), server/request/handler/cmd_take.c)			\
					$(addprefix $(TESTS_PATH), server/request/get_input.c)					\
					$(addprefix $(TESTS_PATH), server/request/parse.c)						\
					$(addprefix $(TESTS_PATH), server/response/create.c)					\
					$(addprefix $(TESTS_PATH), server/remove_client.c)						\
					$(addprefix $(TESTS_PATH), simulation/drone/eject.c)					\
					$(addprefix $(TESTS_PATH), simulation/drone/move.c)						\
					$(addprefix $(TESTS_PATH), simulation/drone/rotate.c)					\
					$(addprefix $(TESTS_PATH), simulation/incantation/check.c)				\
					$(addprefix $(TESTS_PATH), simulation/inventory/add_item.c)				\
					$(addprefix $(TESTS_PATH), simulation/inventory/get_item_info.c)		\
					$(addprefix $(TESTS_PATH), simulation/inventory/remove_item.c)			\
					$(addprefix $(TESTS_PATH), simulation/teams/has_drone.c)				\
					$(addprefix $(TESTS_PATH), simulation/tile/add_drone.c)					\
					$(addprefix $(TESTS_PATH), simulation/tile/add_item.c)					\
					$(addprefix $(TESTS_PATH), simulation/tile/count_drone.c)				\
					$(addprefix $(TESTS_PATH), simulation/tile/count_item.c)				\
					$(addprefix $(TESTS_PATH), simulation/tile/remove_drone.c)				\
					$(addprefix $(TESTS_PATH), simulation/tile/remove_item.c)				\
					$(addprefix $(TESTS_PATH), simulation/start.c)							\


TESTS_OBJ		=	$(TESTS_SRC:.c=.o)

COV_TEST_OBJ	=	$(TESTS_SRC:.c=.gcda) $(TESTS_SRC:.c=.gcno)

COVERAGE_PATH	=	./coverage/

TESTS_NAME		=	unit_tests

#############

tests_run:	CFLAGS += --coverage
tests_run:	LDLIBS += -lcriterion
tests_run:	clean $(LIBRARIES) $(PROJECT_OBJ) $(TESTS_OBJ)
	$(CC) -o $(TESTS_NAME) $(PROJECT_OBJ) $(TESTS_OBJ) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	./$(TESTS_NAME) --verbose --always-succeed -j1
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
