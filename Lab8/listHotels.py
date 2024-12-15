import json
from Hotel import Hotel


class listHotels:
    def __init__(self, listH=None):
        if isinstance(listH, list):
            self.__listh = listH
        else:
            self.__listh = []

    def inputListFromKeyboard(self):
        count = int(input("Введите количество отелей: "))
        for _ in range(count):
            hotel = Hotel()
            hotel = hotel.inputFromKeyboard()
            self.__listh.append(hotel)
        return self

    def outList(self):
        hotel = Hotel()
        for hotel in self.__listh:
            hotel.out()
            print("--------")

    def printByTown(self, inputTown):
        res = []
        for hotel in self.__listh:
            if hotel.getTown() == inputTown:
                res.append(hotel)
        return res


    def printListByNumbers(self, Type, count):
        res = []
        for hotel in self.__listh:
            if hotel.getFreeRooms(Type) > count:
                res.append(hotel)
        return listHotels(res)

    def printByNumbersAndTown(self, inputTown, Type, count):
        res = []
        for hotel in self.__listh:
            if hotel.getTown() == inputTown and hotel.getFreeRooms(Type) > count:
                res.append(hotel)
        return listHotels(res)

    def sortByStars(self):
        self.__listh = sorted(self.__listh, key=lambda hotel: hotel.getStars(), reverse=True)
        return self

    def lineToHotel(self, line):
        data = line.split(";")
        hotelName = data[0]
        town = data[1]
        countStars = int(data[2])
        numberOfRooms = json.loads(data[3])
        busyNumbers = json.loads(data[4])
        return Hotel(hotelName, town, countStars, numberOfRooms, busyNumbers)

    def readFromFile(self):
        filename = input("Введите название файла: ")
        with (open(filename, "r") as file):
            for line in file.readlines():
                hotel = self.lineToHotel(line)
                self.__listh.append(hotel)

    def writeToFile(self):
        filename = input("Введите название файла для сохранения: ")
        file = open(filename, "w")
        for hotel in self.__listh:
            line = hotel.addHotelToFile()
            file.write(line + '\n')
