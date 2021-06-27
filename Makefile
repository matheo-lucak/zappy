##
## EPITECH PROJECT, 2021
## Zappy [WSL: Ubuntu]
## File description:
## Makefile
##

ZAPPY_SERVER_PATH	=	./server/

ZAPPY_CLIENT_PATH	=	./ai/

# ZAPPY_GUI_PATH		=	./gui/

ZAPPY_PATHS			=	$(ZAPPY_SERVER_PATH)	\
						$(ZAPPY_CLIENT_PATH)	\
						# $(ZAPPY_GUI_PATH)

SERVER_NAME			=	zappy_server
CLIENT_NAME			=	zappy_ai
GUI_NAME			=	zappy_gui

ZAPPY_BINARIES		=	$(SERVER_NAME)		\
						$(CLIENT_NAME)		\
						# $(GUI_NAME)

all:	$(ZAPPY_BINARIES)

$(SERVER_NAME):
	$(MAKE) -C $(ZAPPY_SERVER_PATH) -e "PATH_TO_INSTANTIATE=.."

$(CLIENT_NAME):
	$(MAKE) -C $(ZAPPY_CLIENT_PATH) -e "PATH_TO_INSTANTIATE=.."

clean fclean tests_run:
	for part in $(ZAPPY_PATHS); do $(MAKE) $@ -C $$part -e "PATH_TO_INSTANTIATE=.."; done;
.PHONY:	clean fclean tests_run

re::	fclean
re::	all
.PHONY:	re
