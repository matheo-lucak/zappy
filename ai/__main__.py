# -*- coding: Utf-8 -*

from sys import exit

from src.parse_args import parse_args, HelpError
from src.errors import Result, Error
from src.zappy_ai import ZappyAIArgs, zappy_ai

EPITECH_EXIT_SUCCESS: int = 0
EPITECH_EXIT_FAILURE: int = 84

def main() -> int:
    args: Result[ZappyAIArgs] = parse_args()
    if isinstance(args, Error):
        if isinstance(args, HelpError):
            return EPITECH_EXIT_SUCCESS
        return EPITECH_EXIT_FAILURE
    zappy_ai(args)
    return EPITECH_EXIT_SUCCESS

if __name__ == "__main__":
    exit(main())