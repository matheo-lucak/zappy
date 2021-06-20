##
## EPITECH PROJECT, 2021
## YEP_zappy_2020
## File description:
## Makefile
##

current_dir			:=	$(dir $(abspath $(lastword $(MAKEFILE_LIST))))

PYCACHE				=	__pycache__

PYTEST_CACHE		=	.pytest_cache

COVERAGE_CACHE		=	.coverage

MYPY_CACHE			=	.mypy_cache

PATH_TO_INSTANTIATE	?=	.

override NAME		=	$(PATH_TO_INSTANTIATE)/zappy_ai

all:	$(NAME)
.PHONY: all

$(NAME):
	@echo "Creating $@ script..."
	@echo "#! /bin/sh" > $@
	@echo >> $@
	@echo -n "/usr/bin/env python3 $(current_dir) $$" >> $@
	@echo "@" >> $@
	@chmod +x $@
	@echo "Done"

tests_run:
	@echo "Running tests..."
	@pytest .
.PHONY: tests_run

coverage:
	coverage run -m pytest
	coverage report -m

clean:
	@find -name "$(PYCACHE)" | xargs -I {} sh -c 'echo "$(RM) -r {}" && $(RM) -r {}'
	$(RM) -r $(PYTEST_CACHE)
	$(RM) -r $(MYPY_CACHE)
	$(RM) $(COVERAGE_CACHE)
.PHONY:	clean

fclean:	clean
	$(RM) $(NAME)
.PHONY:	fclean

re::	fclean
re::	all
.PHONY:	re