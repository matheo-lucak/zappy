##
## EPITECH PROJECT, 2021
## Zappy [WSL: Ubuntu]
## File description:
## Makefile
##

ZAPPY_SERVER_PATH	=	./server/

ZAPPY_PATHS			=	$(ZAPPY_SERVER_PATH)

SERVER_NAME			=	zappy_server
CLIENT_NAME			=	zappy_server
GUI_NAME			=	zappy_server

all:	zappy_server

zappy_server:
	$(MAKE) -C $(ZAPPY_SERVER_PATH) -e "PATH_TO_INSTANTIATE=.."

clean:
	for part in $(ZAPPY_PATHS); do $(MAKE) $@ -C $$part -e "PATH_TO_INSTANTIATE=.."; done;
.PHONY:	clean

fclean:
	for part in $(ZAPPY_PATHS); do $(MAKE) $@ -C $$part -e "PATH_TO_INSTANTIATE=.."; done;
.PHONY:	fclean

re::	fclean
re::	all
.PHONY:	re
