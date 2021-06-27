# -*- coding: Utf-8 -*

from typing import Any, Dict, Tuple, cast

from .exception import ResourceError


class MetaResource(type):

    __all_resources: Dict[str, "MetaResource"] = dict()
    __resources_density: Dict[str, float] = dict()
    __rarity_ceiling: float = 0.10

    def __new__(
        metacls, name: str, bases: Tuple[type, ...], attrs: Dict[str, Any], resource: str, density: float
    ) -> "MetaResource":
        if name != "BaseResource":
            if len(resource) == 0:
                raise ValueError("Resource name can't be empty")
            if not (0 <= density <= 1):
                raise ValueError("Density must be between 0 and 1")
            if resource in metacls.__all_resources:
                raise TypeError(f"A resource class already hold this name: {metacls.__all_resources[resource]}")
        return cast(MetaResource, super(MetaResource, metacls).__new__(metacls, name, bases, attrs))

    def __init__(cls, name: str, bases: Tuple[type, ...], attrs: Dict[str, Any], resource: str, density: float) -> None:
        super().__init__(name, bases, attrs)
        if resource:
            setattr(cls, "__resource_name__", resource)
            setattr(cls, "__resource_density__", density)
            cls.__all_resources[resource] = cls
            cls.__resources_density[resource] = density

    def __call__(cls, *args: Any, **kwds: Any) -> Any:
        if cls is BaseResource:
            raise TypeError(f"{cls.__name__} can't be instantiated")
        return super().__call__(*args, **kwds)

    @classmethod
    def get_all_resources(metacls) -> Tuple[str, ...]:
        return tuple(metacls.__all_resources)

    @classmethod
    def get_rare_resources(metacls) -> Tuple[str, ...]:
        resources: Tuple[Tuple[str, float], ...]
        resources = tuple(sorted(metacls.__resources_density.items(), key=lambda item: item[1]))
        return tuple(resource for resource, density in resources if density < metacls.__rarity_ceiling)

    @classmethod
    def get_resource_density(metacls, resource: str) -> float:
        return metacls.__resources_density[resource]

    @classmethod
    def create(metacls, resource: str, amount: int = 0) -> "BaseResource":
        if resource not in metacls.__all_resources:
            raise ResourceError(f"Unknown resource {repr(resource)}")
        return cast(BaseResource, metacls.__all_resources[resource](amount))


class BaseResource(metaclass=MetaResource, resource=str(), density=0):
    def __init__(self, amount: int = 0) -> None:
        self.amount = amount

    def __repr__(self) -> str:
        return f"<{self.name}({self.__amount})>"

    def __str__(self) -> str:
        return self.name

    @classmethod
    def get_name(cls) -> str:
        if cls is BaseResource:
            raise AttributeError("Base class for Resource does not have this attribute")
        return str(getattr(cls, "__resource_name__"))

    @classmethod
    def get_density(cls) -> float:
        if cls is BaseResource:
            raise AttributeError("Base class for Resource does not have this attribute")
        return float(getattr(cls, "__resource_density__"))

    @property
    def name(self) -> str:
        return self.get_name()

    @property
    def density(self) -> float:
        return self.get_density()

    @property
    def amount(self) -> int:
        return self.__amount

    @amount.setter
    def amount(self, value: int) -> None:
        self.__amount = max(int(value), 0)
