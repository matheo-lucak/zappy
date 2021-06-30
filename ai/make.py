#!/usr/bin/env python3
# -*- coding: Utf-8 -*

from os import chmod
from sys import path as SYSTEM_PATH
from argparse import ArgumentParser

CURRENT_DIR: str = SYSTEM_PATH[0]

EXECUTABLE_CONTENT: str = f"""#!/usr/bin/env python3
# -*- coding: Utf-8 -*

from runpy import run_path

MODULE: str = "{CURRENT_DIR}"

if __name__ == "__main__":
    run_path(MODULE, run_name=__name__)
"""

DEFAULT_PATH: str = "./zappy_ai"


def main() -> None:
    parser: ArgumentParser = ArgumentParser()
    parser.add_argument("file", nargs="?", default=DEFAULT_PATH, help=f"Output file; default={DEFAULT_PATH}")

    args = parser.parse_args()
    filepath: str = args.file

    with open(filepath, "w") as f:
        f.write(EXECUTABLE_CONTENT)

    chmod(filepath, 0o755)


if __name__ == "__main__":
    main()
