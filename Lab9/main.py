from Picture import Picture

picture = Picture()
ch = 0
while ch != -1:
    print("Нажмите 1, чтобы ввести массив вручную")
    print("Нажмите 2, чтобы ввести массив из файла")
    print("Нажмите 3, чтобы вывести массив на экран")
    print("Нажмите 4, чтобы вывести те линии, у которых длина находится в диапазоне")
    print("Нажмите 5, чтобы сортировать массив, по длине линии")
    print("Нажмите 6, чтобы сохранить в файл")
    print("Нажмите -1, чтобы выйти из программы")
    ch = int(input())
    if ch == 1:
        picture.input()

    elif ch == 2:
        filename = input("Введите название файла: ")
        picture.fromFile(filename)

    elif ch == 3:
        picture.output()

    elif ch == 4:
        minD = int(input("Введите минимальное число диапазона: "))
        maxD = int(input("Введите максимальное число диапазона: "))
        minMax = picture.printByLength(minD, maxD)
        minMax.output()

    elif ch == 5:
        picture.sortByLength()

    elif ch == 6:
        filename = input("Введите название файла: ")
        picture.toFile(filename)
    elif ch == -1:
        break
