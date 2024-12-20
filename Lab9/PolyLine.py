from Line import Line


class PolyLine(Line):
    def __init__(self, segmentLength=None):
        if isinstance(segmentLength, list):
            self.__segmentLength = segmentLength
        else:
            self.__segmentLength = []

    def getName(self):
        return "PolyLine"

    def getLength(self):
        return sum(self.__segmentLength)

    def input(self):
        mas = []
        count = int(input("Введите кол-во линий: "))
        for _ in range(count):
            length = int(input("Введите длину одного участка ломанной линии: "))
            mas.append(length)
        self.__segmentLength = mas
        return self

    def out(self):
        for i in range(len(self.__segmentLength)):
            print(f"Длина {i + 1} участка ломанной линии равна - {self.__segmentLength[i]}")

    def writeToFile(self):
        ls = [str(i) for i in self.__segmentLength]
        lineStr = ",".join(ls)
        return f"{self.getName()},{len(self.__segmentLength)},{lineStr}\n"

    def readFromFile(self, line):
        count = int(line[0])
        for i in range(count):
            self.__segmentLength.append(int(line[i + 1]))
        return self
