##
## EPITECH PROJECT, 2021
## YEP_zappy_2020
## File description:
## Makefile
##

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
	@./make.py $@
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
.PHONY:	clean

fclean:	clean
	$(RM) $(NAME)
	$(RM) -r $(PYTEST_CACHE)
	$(RM) -r $(MYPY_CACHE)
	$(RM) $(COVERAGE_CACHE)
.PHONY:	fclean

re::	fclean
re::	all
.PHONY:	re