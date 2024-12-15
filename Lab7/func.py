

def readFile(fileName):
    file = open(fileName, "r")
    contentFile = file.read()
    content = contentFile.split(" ")
    toFloat = [float(i) for i in content]
    file.close()
    return toFloat


def mainFunc(mas):
    minNum = min(mas)
    count = 0
    index = []
    for i in range(1, len(mas) - 1):
        if mas[i - 1] > mas[i] > minNum and mas[i] < mas[i + 1]:
            count += 1
            index.append(i+1)
    return count, index


def writeToFile(fileName, count, index):
    file = open(fileName, "w")
    file.write(f"Кол-во чисел: {count}\n")
    file.write("Индексы: ")
    for i in index:
        file.write(f"{i} ")
