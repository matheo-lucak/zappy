# -*- coding: Utf-8 -*

from typing import Any, Dict, Tuple, cast


class MetaAction(type):
    def __new__(metacls, name: str, bases: Tuple[type, ...], attrs: Dict[str, Any]) -> "MetaAction":
        annotations: Dict[str, type] = attrs.get("__annotations__", {})
        for action, t in annotations.items():
            if not issubclass(t, int):
                raise TypeError(f"{action}: Must be an int")
            attrs[action] = metacls.make_property(action)
        return cast(MetaAction, super(MetaAction, metacls).__new__(metacls, name, bases, attrs))

    @staticmethod
    def make_property(action: str) -> property:
        def getter(self: "BaseAction") -> int:
            return self.get(action)

        def setter(self: "BaseAction", value: int) -> None:
            return self.set(action, value)

        return property(getter, setter)


class BaseAction(metaclass=MetaAction):
    def __init__(self) -> None:
        self.__doing_action: Dict[str, int] = dict()

    def get(self, action: str) -> int:
        return self.__doing_action.get(action, 0)

    def set(self, action: str, value: int) -> None:
        self.__doing_action[str(action)] = max(int(value), 0)

    def ongoing(self, *ignoring: str) -> bool:
        return sum(number for action, number in self.__doing_action.items() if action not in ignoring) > 0
