import json


class Hotel:
    def __init__(self, hotelName=None, town=None, countStars=None,
                 numberOfRooms=None, busyNumbers=None):
        self.__hotelName = hotelName
        self.__town = town
        self.__countStars = countStars
        self.__numberOfRooms = numberOfRooms if numberOfRooms else {}
        self.__busyNumbers = busyNumbers if busyNumbers else {}

    def inputFromKeyboard(self):
        self.__hotelName = input("Введите название отеля: ")
        self.__town = input("Введите город, в котором находится отель: ")
        self.__countStars = input("Введите кол-во звезд:")
        print("Добавление номеров: ")
        while True:
            roomType = input("Введите тип номера (vip, семейный, двойной, "
                             "одинарный) или stop для остановки: ").strip()
            if roomType == "stop":
                print("Добавление завершено")
                break
            else:
                total = int(input(f"Введите кол-во всех номеров типа {roomType}: "))
                busy = int(input(f"Введите кол-во занятых номеров типа {roomType}: "))

                self.__numberOfRooms[roomType] = total
                self.__busyNumbers[roomType] = busy
        return self

    def out(self):
        print(f"Название отеля: {self.__hotelName}")
        print(f"Город: {self.__town}")
        print(f"Кол-во звезд: {self.__countStars}")
        print("Информация о номерах")
        for roomType in self.__numberOfRooms:
            total = self.__numberOfRooms[roomType]
            busy = self.__busyNumbers[roomType]
            print(f"Тип номера: {roomType}, всего мест: {total}, занято: {busy}")
        return self

    def getTown(self):
        return self.__town

    def getStars(self):
        return self.__countStars

    def getFreeRooms(self, Type):
        total = self.__numberOfRooms[Type]
        busy = self.__busyNumbers[Type]
        return int(total - busy)

    def printByNumbers(self, Type, count):
        for roomType in self.__numberOfRooms:
            if roomType == Type and count < self.__numberOfRooms[roomType]:
                self.out()

    def check_occupied_rooms(self, roomType, occupied):
        if roomType in self.__numberOfRooms:
            total = self.__numberOfRooms[roomType]
            if 0 <= occupied <= total:
                return True
        return False

    def addHotelToFile(self):
        line = ";".join([
            self.__hotelName,
            self.__town,
            str(self.__countStars),
            json.dumps(self.__numberOfRooms, ensure_ascii=False),
            json.dumps(self.__busyNumbers, ensure_ascii=False)
        ])
        return line
