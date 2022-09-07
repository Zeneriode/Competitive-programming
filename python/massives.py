class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

    def __str__(self):
        return str(self.value)


class LinkedList:
    def __init__(self):
        self.head: Node = None

    def append(self, item):
        """:time_complexity O(1) против O(n) обычного списка"""
        node = Node(item)
        node.next = self.head
        self.head = node

    def __getitem__(self, index):
        """:time_complexity O(n) против O(1) обычного списка"""
        elem = self.head
        for i in range(index):
            if elem is None:
                raise IndexError
            elem = elem.next
        return elem

    def __setitem__(self, index, item):
        """:time_complexity O(n) против O(n) обычного списка"""
        if index == 0:
            temp = self.head.next
            self.head = Node(item)
            self.head.next = temp
            return

        elem = self.head
        for i in range(index - 1):
            if elem is None:
                raise IndexError
            elem = elem.next

        temp = elem.next
        elem.next = Node(item)
        elem.next.next = temp.next

    def remove(self, index: int):
        """:time_complexity O(n) против O(n) обычного списка"""
        if index == 0:
            self.head = self.head.next
            return

        elem = self.head

        for i in range(index - 1):
            if elem is None:
                raise IndexError
            elem = elem.next

        elem.next = elem.next.next


linked_list = LinkedList()
linked_list.append(10)
linked_list.append(19)
linked_list.append(197)
linked_list.append(982)
print(linked_list[3])
linked_list[0] = 1
print(linked_list[0])
print(linked_list[2])
linked_list.remove(2)
print(linked_list[2])



# И что дальше ._.