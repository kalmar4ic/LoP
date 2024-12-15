from listHotels import listHotels
hotels = listHotels()

while True:
        print("\nМеню:")
        print("1. Добавить отели")
        print("2. Показать все отели")
        print("3. Поиск отеля по городам")
        print("4. Поиск отеля по кол-ву свободных мест")
        print("5. Поиск отеля по кол-ву свободных мест и городам")
        print("6. Сортировка сортировка отелей по кол-ву звезд")
        print("7. Сохранить в файл")
        print("8. Загрузить из файла")
        print("0. Выйти")
        choice = input("Выберите опцию: ")

        if choice == "1":
            hotels.inputListFromKeyboard()
        elif choice == "2":
            print("\nСписок отелей:")
            hotels.outList()
        elif choice == "3":
            town = input("Введите город для поиска: ")
            res = listHotels(hotels.printByTown(town))
            res.outList()
        elif choice == "4":
            Type = input("Введите тип комнат: ")
            count = int(input("Введите кол-во свободных мест, которые вам нужны: "))
            res = listHotels(hotels.printListByNumbers(Type, count))
            res.outList()
        elif choice == "5":
            town = input("Введите город для поиска: ")
            Type = input("Введите тип комнат: ")
            count = int(input("Введите кол-во минимальных свободных мест:"))
            res = listHotels(hotels.printByNumbersAndTown(town, Type, count))
            res.outList()
        elif choice == "6":
            hotels.sortByStars()
        elif choice == "7":
            hotels.writeToFile()
        elif choice == "8":
            hotels.readFromFile()
        elif choice == "0":
            print("Выход из программы.")
            break
        else:
            print("Некорректный выбор. Пожалуйста, выберите заново.")
