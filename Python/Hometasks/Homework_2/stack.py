class Stack:
    def __init__(self, *args):
        self.__data = list(args)

    def push(self, element):
        self.__data.append(element)

    def pop(self):
        return self.__data.pop(-1)

    def __str__(self):
        return ", ".join(list(map(str, self.__data)))


if __name__ == "__main__":
    stack = Stack(10, 20, 30, 40)
    print(stack)
    print(stack.pop())
    print(stack)
    print(stack.pop())
    print(stack)
    stack.push("elem")
    print(stack)
