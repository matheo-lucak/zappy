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
					$(addprefix $(SRC_PATH), arguments/set_default_values.c)					\
					$(addprefix $(SRC_PATH), arguments/create.c)								\
					$(addprefix $(SRC_PATH), arguments/destroy.c)								\
					$(addprefix $(SRC_PATH), logger/find_message.c)								\
					$(addprefix $(SRC_PATH), logger/logger.c)									\
					$(addprefix $(SRC_PATH), logger/map.c)										\
					$(addprefix $(SRC_PATH), network/get_input_stock.c)							\
					$(addprefix $(SRC_PATH), network/handle_client_connection.c)				\
					$(addprefix $(SRC_PATH), network/handle_clients_in.c)						\
					$(addprefix $(SRC_PATH), network/handle_clients_out.c)						\
					$(addprefix $(SRC_PATH), network/remove_connection.c)						\
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
					$(addprefix $(SRC_PATH), server/request/handlers/gui_player_position.c)		\
					$(addprefix $(SRC_PATH), server/request/handlers/gui_player_stats.c)		\
					$(addprefix $(SRC_PATH), server/request/handlers/gui_team_names.c)			\
					$(addprefix $(SRC_PATH), server/request/handlers/gui_tile_content.c)		\
					$(addprefix $(SRC_PATH), server/request/handlers/gui_time_unit_request.c)	\
					$(addprefix $(SRC_PATH), server/request/info/get_info.c)					\
					$(addprefix $(SRC_PATH), server/request/info/info.c)						\
					$(addprefix $(SRC_PATH), server/request/checker.c)							\
					$(addprefix $(SRC_PATH), server/request/create.c)							\
					$(addprefix $(SRC_PATH), server/request/destroy.c)							\
					$(addprefix $(SRC_PATH), server/request/handle_parsing.c)					\
					$(addprefix $(SRC_PATH), server/request/handle.c)							\
					$(addprefix $(SRC_PATH), server/request/parse.c)							\
					$(addprefix $(SRC_PATH), server/response/clone.c)							\
					$(addprefix $(SRC_PATH), server/response/create.c)							\
					$(addprefix $(SRC_PATH), server/response/destroy.c)							\
					$(addprefix $(SRC_PATH), server/add_notification.c)							\
					$(addprefix $(SRC_PATH), server/clear_client.c)								\
					$(addprefix $(SRC_PATH), server/find_client_from_drone.c)					\
					$(addprefix $(SRC_PATH), server/find_client_from_id.c)						\
					$(addprefix $(SRC_PATH), server/launch.c)									\
					$(addprefix $(SRC_PATH), server/remove_client.c)							\
					$(addprefix $(SRC_PATH), server/run.c)										\
					$(addprefix $(SRC_PATH), server/start.c)									\
					$(addprefix $(SRC_PATH), server/stop.c)										\
					$(addprefix $(SRC_PATH), simulation/direction/get_eject_direction.c)		\
					$(addprefix $(SRC_PATH), simulation/direction/get_random.c)					\
					$(addprefix $(SRC_PATH), simulation/drone/create.c)							\
					$(addprefix $(SRC_PATH), simulation/drone/destroy.c)						\
					$(addprefix $(SRC_PATH), simulation/drone/eat.c)							\
					$(addprefix $(SRC_PATH), simulation/drone/eject.c)							\
					$(addprefix $(SRC_PATH), simulation/drone/get_look_format.c)				\
					$(addprefix $(SRC_PATH), simulation/drone/get_map_quarter.c)				\
					$(addprefix $(SRC_PATH), simulation/drone/get_pos_after_move_on_map.c)		\
					$(addprefix $(SRC_PATH), simulation/drone/get_pos_on_map.c)					\
					$(addprefix $(SRC_PATH), simulation/drone/get_sound_direction.c)			\
					$(addprefix $(SRC_PATH), simulation/drone/get_sound_entering_tile.c)		\
					$(addprefix $(SRC_PATH), simulation/drone/get_sound_set_projections.c)		\
					$(addprefix $(SRC_PATH), simulation/drone/move.c)							\
					$(addprefix $(SRC_PATH), simulation/drone/rotate.c)							\
					$(addprefix $(SRC_PATH), simulation/egg/create.c)							\
					$(addprefix $(SRC_PATH), simulation/egg/destroy.c)							\
					$(addprefix $(SRC_PATH), simulation/handle/eggs.c)							\
					$(addprefix $(SRC_PATH), simulation/handle/food.c)							\
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
					$(addprefix $(SRC_PATH), simulation/inventory/get_deraumere_amount.c)		\
					$(addprefix $(SRC_PATH), simulation/inventory/get_food_amount.c)			\
					$(addprefix $(SRC_PATH), simulation/inventory/get_item_info.c)				\
					$(addprefix $(SRC_PATH), simulation/inventory/get_linemate_amount.c)		\
					$(addprefix $(SRC_PATH), simulation/inventory/get_mendiane_amount.c)		\
					$(addprefix $(SRC_PATH), simulation/inventory/get_phiras_amount.c)			\
					$(addprefix $(SRC_PATH), simulation/inventory/get_sibur_amount.c)			\
					$(addprefix $(SRC_PATH), simulation/inventory/get_thystame_amount.c)		\
					$(addprefix $(SRC_PATH), simulation/inventory/remove_item.c)				\
					$(addprefix $(SRC_PATH), simulation/map/add_drone.c)						\
					$(addprefix $(SRC_PATH), simulation/map/clear.c)							\
					$(addprefix $(SRC_PATH), simulation/map/count_resources.c)					\
					$(addprefix $(SRC_PATH), simulation/map/create.c)							\
					$(addprefix $(SRC_PATH), simulation/map/destroy.c)							\
					$(addprefix $(SRC_PATH), simulation/map/get_tile_look_format.c)				\
					$(addprefix $(SRC_PATH), simulation/map/refill.c)							\
					$(addprefix $(SRC_PATH), simulation/resource/get_info.c)					\
					$(addprefix $(SRC_PATH), simulation/resource/info.c)						\
					$(addprefix $(SRC_PATH), simulation/team/add_drone.c)						\
					$(addprefix $(SRC_PATH), simulation/team/add_egg.c)							\
					$(addprefix $(SRC_PATH), simulation/team/create.c)							\
					$(addprefix $(SRC_PATH), simulation/team/delete_drone.c)					\
					$(addprefix $(SRC_PATH), simulation/team/destroy.c)							\
					$(addprefix $(SRC_PATH), simulation/team/find_unactive_drone.c)				\
					$(addprefix $(SRC_PATH), simulation/team/has_drone.c)						\
					$(addprefix $(SRC_PATH), simulation/team/new_active_drone.c)				\
					$(addprefix $(SRC_PATH), simulation/tile/add_drone.c)						\
					$(addprefix $(SRC_PATH), simulation/tile/add_item.c)						\
					$(addprefix $(SRC_PATH), simulation/tile/clear_items.c)						\
					$(addprefix $(SRC_PATH), simulation/tile/count_drone.c)						\
					$(addprefix $(SRC_PATH), simulation/tile/count_item.c)						\
					$(addprefix $(SRC_PATH), simulation/tile/create.c)							\
					$(addprefix $(SRC_PATH), simulation/tile/destroy.c)							\
					$(addprefix $(SRC_PATH), simulation/tile/get_deraumere_amount.c)			\
					$(addprefix $(SRC_PATH), simulation/tile/get_food_amount.c)					\
					$(addprefix $(SRC_PATH), simulation/tile/get_linemate_amount.c)				\
					$(addprefix $(SRC_PATH), simulation/tile/get_mendiane_amount.c)				\
					$(addprefix $(SRC_PATH), simulation/tile/get_phiras_amount.c)				\
					$(addprefix $(SRC_PATH), simulation/tile/get_sibur_amount.c)				\
					$(addprefix $(SRC_PATH), simulation/tile/get_thystame_amount.c)				\
					$(addprefix $(SRC_PATH), simulation/tile/has_drones.c)						\
					$(addprefix $(SRC_PATH), simulation/tile/has_items.c)						\
					$(addprefix $(SRC_PATH), simulation/tile/is_empty.c)						\
					$(addprefix $(SRC_PATH), simulation/tile/remove_drone.c)					\
					$(addprefix $(SRC_PATH), simulation/tile/remove_item.c)						\
					$(addprefix $(SRC_PATH), simulation/vector/add.c)							\
					$(addprefix $(SRC_PATH), simulation/vector/distance.c)						\
					$(addprefix $(SRC_PATH), simulation/vector/sub.c)							\
					$(addprefix $(SRC_PATH), simulation/find_team_from_drone.c)					\
					$(addprefix $(SRC_PATH), simulation/handle.c)								\
					$(addprefix $(SRC_PATH), simulation/remove_drone.c)							\
					$(addprefix $(SRC_PATH), simulation/start.c)								\
					$(addprefix $(SRC_PATH), simulation/stop.c)									\
					$(addprefix $(SRC_PATH), usage.c)											\

SRC				=	$(SRC_PROJECT) $(MAIN)

#############

#############
# Libraries #
#############

PERSONAL_LIBRARIES_PATH	=	./libs/

PERSONAL_LIBRARIES		=	my		\
							epinet	\
							mylist

OTHER_LIBRARIES			=	m

override LDFLAGS	+=	$(addprefix -L, $(PERSONAL_LIBRARIES_PATH))

override LDLIBS		+=	$(addprefix -l, $(PERSONAL_LIBRARIES))		\
						$(addprefix -l, $(OTHER_LIBRARIES))

#############

####################################
# Compilation Flags & Object files #
####################################

CC					=	gcc

override CFLAGS		+=	-W -Wall -Wextra

override CPPFLAGS	+=	-I$(INCLUDE_PATH)

##############

PROJECT_OBJ			=	$(SRC_PROJECT:.c=.o)

OBJ					=	$(SRC:.c=.o)

COV_PROJECT_OBJ		=	$(SRC_PROJECT:.c=.gcda) $(SRC_PROJECT:.c=.gcno)

##############

PATH_TO_INSTANTIATE	?=	.

override NAME		=	$(PATH_TO_INSTANTIATE)/zappy_server

#############

all:	$(NAME)
.PHONY:	all

$(PROJECT_OBJ):	$(PERSONAL_LIBRARIES)
$(OBJ):			$(PERSONAL_LIBRARIES)

$(NAME):	CFLAGS += -O0
$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

$(PERSONAL_LIBRARIES):
	$(MAKE) -C $(PERSONAL_LIBRARIES_PATH)$@
.PHONY:	$(PERSONAL_LIBRARIES)

debug:	CFLAGS += -g
debug:	$(NAME)
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
					$(addprefix $(TESTS_PATH), server/request/handle_parsing.c)				\
					$(addprefix $(TESTS_PATH), server/request/parse.c)						\
					$(addprefix $(TESTS_PATH), server/response/create.c)					\
					$(addprefix $(TESTS_PATH), server/remove_client.c)						\
					$(addprefix $(TESTS_PATH), simulation/drone/eat.c)						\
					$(addprefix $(TESTS_PATH), simulation/drone/eject.c)					\
					$(addprefix $(TESTS_PATH), simulation/drone/get_look_format.c)			\
					$(addprefix $(TESTS_PATH), simulation/drone/get_map_quarter.c)			\
					$(addprefix $(TESTS_PATH), simulation/drone/get_sound_direction.c)		\
					$(addprefix $(TESTS_PATH), simulation/drone/get_sound_entering_tile.c)	\
					$(addprefix $(TESTS_PATH), simulation/drone/move.c)						\
					$(addprefix $(TESTS_PATH), simulation/drone/rotate.c)					\
					$(addprefix $(TESTS_PATH), simulation/incantation/check.c)				\
					$(addprefix $(TESTS_PATH), simulation/inventory/add_item.c)				\
					$(addprefix $(TESTS_PATH), simulation/inventory/get_item_info.c)		\
					$(addprefix $(TESTS_PATH), simulation/inventory/remove_item.c)			\
					$(addprefix $(TESTS_PATH), simulation/map/create.c)						\
					$(addprefix $(TESTS_PATH), simulation/map/clear.c)						\
					$(addprefix $(TESTS_PATH), simulation/teams/has_drone.c)				\
					$(addprefix $(TESTS_PATH), simulation/tile/add_drone.c)					\
					$(addprefix $(TESTS_PATH), simulation/tile/add_item.c)					\
					$(addprefix $(TESTS_PATH), simulation/tile/count_drone.c)				\
					$(addprefix $(TESTS_PATH), simulation/tile/count_item.c)				\
					$(addprefix $(TESTS_PATH), simulation/tile/remove_drone.c)				\
					$(addprefix $(TESTS_PATH), simulation/tile/remove_item.c)				\
					$(addprefix $(TESTS_PATH), simulation/start.c)							\

########################################
# Compilation & Object files for Tests #
########################################

COVERAGE_PATH	=	./coverage/

TESTS_NAME		=	unit_tests

TESTS_OBJ		=	$(TESTS_SRC:.c=.o)

$(TESTS_OBJ):		$(PERSONAL_LIBRARIES)

COV_TEST_OBJ	=	$(TESTS_SRC:.c=.gcda) $(TESTS_SRC:.c=.gcno)

#############

tests_run:	CFLAGS += --coverage
tests_run:	LDLIBS += -lcriterion
tests_run:	$(PROJECT_OBJ) $(TESTS_OBJ)
	$(CC) -o $(TESTS_NAME) $(PROJECT_OBJ) $(TESTS_OBJ) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	./$(TESTS_NAME) --verbose --always-succeed
	$(RM) $(TESTS_NAME)
.PHONY:	tests_run

coverage:
	gcovr --exclude $(TESTS_PATH)
	gcovr --exclude $(TESTS_PATH) --branches
.PHONY:	coverage

clean:
	for lib in $(PERSONAL_LIBRARIES); do $(MAKE) $@ -C $(PERSONAL_LIBRARIES_PATH)/$$lib; done;
	$(RM) $(OBJ) $(PROJECT_OBJ) $(TESTS_OBJ)
	$(RM) $(TESTS_NAME)
	$(RM) $(COV_PROJECT_OBJ) $(COV_TEST_OBJ)
.PHONY:	clean

fclean:	clean
	for lib in $(PERSONAL_LIBRARIES); do $(MAKE) $@ -C $(PERSONAL_LIBRARIES_PATH)/$$lib; done;
	$(RM) $(NAME)
.PHONY:	fclean

re::	fclean
re::	all
.PHONY:	re
