from ColoredLine import ColoredLine
from PolyLine import PolyLine


class Picture:
    def __init__(self, lines=None):
        if isinstance(lines, list):
            self.__lines = lines
        else:
            self.__lines = []

    def input(self):
        count = int(input("Введите кол-во линий: "))
        for _ in range(count):
            Type = input("Введите тип линии (ColoredLine или PolyLine): ")
            notLine = None
            if Type == "ColoredLine":
                notLine = ColoredLine()
            elif Type == "PolyLine":
                notLine = PolyLine()
            line = notLine.input()
            self.__lines.append(line)
        return self

    def output(self):
        for line in self.__lines:
            print(f"Тип линии {line.getName()}")
            line.out()
            print("- - - - -")

    def printByLength(self, minD, maxD):
        linesByLength = []
        for line in self.__lines:
            if minD < line.getLength() < maxD:
                linesByLength.append(line)
        return Picture(linesByLength)

    def sortByLength(self):
        self.__lines = sorted(self.__lines, key=lambda line: line.getLength(), reverse=True)

    def fromFile(self, filename):
        with open(filename, "r") as file:
            for linee in file:
                line = linee.split(",")
                if line[0] == "ColoredLine":
                    self.__lines.append(ColoredLine().readFromFile(line[1:]))
                elif line[0] == "PolyLine":
                    self.__lines.append(PolyLine().readFromFile(line[1:]))

    def toFile(self, filename):
        with open(filename, "w") as file:
            for line in self.__lines:
                file.writelines(line.writeToFile())
