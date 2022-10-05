from collections import deque


class Stack:
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


def ispar(self, x):
    # code here
    arr = self.Stack()
    for sign in x:
        if sign in ("(", "[", "{"):
            arr.push(sign)
            continue

        if arr.is_empty():
            return False

        if arr.top() == "(" and sign == ")":
            arr.pop()
            continue

        if arr.top() == "[" and sign == "]":
            arr.pop()
            continue

        if arr.top() == "{" and sign == "}":
            arr.pop()
            continue

        return False

    return arr.is_empty()