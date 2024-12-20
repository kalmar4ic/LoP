from Line import Line


class ColoredLine(Line):
    def __init__(self, color=None, length=None):
        self.__color = color
        self.__length = length

    def getLength(self):
        return self.__length

    def getName(self):
        return "ColoredLine"

    def input(self):
        self.__color = input("Введите цвет линии: ")
        self.__length = int(input("Введите длину линии: "))
        return self

    def out(self):
        print(f"Цвет линии: {self.__color}, длина линии: {self.__length}")

    def writeToFile(self):
        return f"{self.getName()},{self.__color},{self.__length}\n"

    def readFromFile(self, line):
        self.__color = line[0]
        self.__length = int(line[1])
        return self
