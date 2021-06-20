# -*- coding: Utf-8 -*

from .base import BaseRequest
from .response.team import TeamResponse

class TeamRequest(BaseRequest[TeamResponse]):
    
    def __init__(self, team_name: str) -> None:
        super().__init__(team_name)