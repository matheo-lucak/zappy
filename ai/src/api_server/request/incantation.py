# -*- coding: Utf-8 -*

from typing import List, Optional
from re import match as regex_match, Match

from .base import BaseRequest, ResponseCallback
from .response.multiple import MultiResponse
from .response.exceptions import ResponseParsingError


class IncantationResponse(MultiResponse, nb_responses=2, wait_for_all=False):
    def __init__(self, *responses: str) -> None:
        super().__init__(*responses)
        rp: str = responses[0]

        valid_first_response: List[str] = ["Elevation underway", "ko"]
        if rp not in valid_first_response:
            raise ResponseParsingError(rp, f"Must be in {valid_first_response}")

        self.__result: Optional[bool] = None
        self.__level: int = 0

        if rp == "ko":
            self.__result = False

        if len(responses) == 2:
            rp = responses[1]
            valid_second_response: List[str] = [r"Current level: +([0-9]+)", r"(ko)"]
            match: Optional[Match[str]] = None
            for pattern in valid_second_response:
                match = regex_match(pattern, rp)
                if match is not None:
                    break
            if match is None:
                raise ResponseParsingError(rp, "Does not match to any pattern")
            if self.__result is False:
                return
            if match.group(0) == "ko":
                self.__result = False
            else:
                self.__result = True
                self.__level = int(match.group(1))

    @property
    def result(self) -> Optional[bool]:
        return self.__result

    @property
    def level(self) -> int:
        return self.__level


class IncantationRequest(BaseRequest[IncantationResponse], process_time=300):
    def __init__(self, callback: Optional[ResponseCallback[IncantationResponse]] = None) -> None:
        super().__init__("Incantation", callback=callback)
