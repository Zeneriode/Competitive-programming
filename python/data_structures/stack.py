from abc import ABC
from collections import deque


class StackADT(ABC):
    def __init__(self):
        pass

    def push(self, value) -> None:
        """Добавление элемента в стек\n
        :time_complexity O(1)"""
        pass

    def pop(self) -> object:
        """Удаление элемента из стека\n
        :time_complexity O(1)"""
        pass

    def top(self) -> object:
        """Возвращает самый верхний элемент\n
        :time_complexity O(1)"""
        pass

    def size(self) -> int:
        """Размер стека\n
        :time_complexity O(1)"""
        pass

    def is_empty(self) -> bool:
        """Возвращает, пустой ли у нас стек или нет\n
        :time_complexity O(1)"""
        pass


class SimpleStack(StackADT):
    def __init__(self, size: int):
        super().__init__()
        self.max_capacity = size
        self.arr: list[object] = [None] * self.max_capacity
        self.first = -1

    def push(self, value) -> None:
        if self.first + 1 == self.max_capacity:
            raise OverflowError("Стек переполнен!")
        self.first += 1
        self.arr[self.first] = value

    def pop(self) -> object:
        if self.is_empty():
            raise IndexError("Стек пустой!")
        self.first -= 1
        return self.arr[self.first + 1]

    def top(self) -> object:
        if self.is_empty():
            raise IndexError("Стек пустой!")
        return self.arr[self.first]

    def size(self) -> int:
        return self.first + 1

    def is_empty(self) -> bool:
        return self.first == -1


class LinkedStack(StackADT):
    class Node:
        def __init__(self, data, next_elem):
            self.data = data
            self.next = next_elem

    def __init__(self):
        super().__init__()
        self.head: LinkedStack.Node = None
        self.__size = 0

    def push(self, value) -> None:
        self.__size += 1
        self.head = self.Node(value, self.head)

    def pop(self) -> object:
        if self.is_empty():
            raise IndexError("Ошибка вследствие удаления несуществующего элемента.")

        self.__size -= 1
        temp = self.head
        self.head = self.head.next
        return temp.data

    def top(self) -> object:
        if self.is_empty():
            raise IndexError("Ошибка вследствие поиска несуществующего элемента.")
        return self.head.data

    def size(self) -> int:
        return self.__size

    def is_empty(self) -> bool:
        return self.__size == 0


class BestStack(StackADT):
    def __init__(self):
        super().__init__()
        self.__stack = deque()
        self.__size = 0

    def push(self, value) -> None:
        self.__size += 1
        self.__stack.append(value)

    def pop(self) -> object:
        self.__size -= 1
        return self.__stack.pop()

    def top(self) -> object:
        return self.__stack[-1]

    def size(self) -> int:
        return self.__size

    def is_empty(self) -> bool:
        return self.__size == 0
