##
## EPITECH PROJECT, 2020
## Epinet
## File description:
## Makefile
##

include mk/sources.mk
include mk/config.mk

ROOT_DIR_PATH	=	../../

LIBRARY_HEADERS	=	$(wildcard include/*)

COPIED_HEADERS	=	$(addprefix $(ROOT_DIR_PATH), $(LIBRARY_HEADERS))

all:	${TARGET_LIB}

$(TARGET_LIB):	$(OBJS)
	@ar rc $(TARGET_LIB) $(OBJS)
	@cp $(TARGET_LIB) ../
	@mkdir -p $(ROOT_DIR_PATH)include
	@cp -r $(LIBRARY_HEADERS) $(ROOT_DIR_PATH)include

clean:
	@$(RM) $(OBJS)
	@$(RM) *.gcno
	@$(RM) *.gcda

fclean:	clean
	@$(RM) $(TARGET_LIB)
	@$(RM) $(TARGET_TESTS)
	@$(RM) ../$(TARGET_LIB)
	@$(RM) -r $(COPIED_HEADERS)

re:	fclean all

tests_run:	re
	@$(CC) -o $(TARGET_TESTS) $(addprefix $(DIR_TESTS), $(TESTS_SRCS)) \
	$(TESTS_FLAGS) $(CPPFLAGS)
	./unit_tests

.PHONY:	all clean fclean re tests_run
