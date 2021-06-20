# -*- coding: Utf-8 -*

from typing import Any, Dict, Tuple, cast


class MetaResource(type):

    __all_resources: Dict[str, "MetaResource"] = dict()

    def __new__(metacls, name: str, bases: Tuple[type, ...], attrs: Dict[str, Any], resource: str) -> "MetaResource":
        if name != "BaseResource":
            if len(resource) == 0:
                raise TypeError("Resource name can't be empty")
            if resource in metacls.__all_resources:
                raise TypeError(f"A resource class already hold this name: {metacls.__all_resources[resource]}")
        return cast(MetaResource, super(MetaResource, metacls).__new__(metacls, name, bases, attrs))

    def __init__(cls, name: str, bases: Tuple[type, ...], attrs: Dict[str, Any], resource: str) -> None:
        super().__init__(name, bases, attrs)
        if resource:
            setattr(cls, "__resource_name__", resource)
            cls.__all_resources[resource] = cls

    def __call__(cls, *args: Any, **kwds: Any) -> Any:
        if cls is BaseResource:
            raise TypeError(f"{cls.__name__} can't be instantiated")
        return super().__call__(*args, **kwds)

    @classmethod
    def get_all_resources(metacls) -> Tuple[str, ...]:
        return tuple(metacls.__all_resources)

    @classmethod
    def create(metacls, resource: str, amount: int = 0) -> "BaseResource":
        if resource not in metacls.__all_resources:
            raise TypeError(f"Unknown resource {repr(resource)}")
        return cast(BaseResource, metacls.__all_resources[resource](amount))


class BaseResource(metaclass=MetaResource, resource=str()):
    def __init__(self, amount: int = 0) -> None:
        self.amount = amount

    def __repr__(self) -> str:
        return f"<{self.name}({self.__amount})>"

    @property
    def name(self) -> str:
        return str(getattr(type(self), "__resource_name__"))

    @property
    def amount(self) -> int:
        return self.__amount

    @amount.setter
    def amount(self, value: int) -> None:
        self.__amount = max(int(value), 0)
