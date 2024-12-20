from abc import ABC, abstractmethod


class Line(ABC):
    @abstractmethod
    def getLength(self):
        pass

    @abstractmethod
    def getName(self):
        pass

    @abstractmethod
    def input(self):
        pass

    @abstractmethod
    def out(self):
        pass

    @abstractmethod
    def writeToFile(self):
        pass

    @abstractmethod
    def readFromFile(self, line):
        pass
