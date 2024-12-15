import func

text = func.readFile("1.txt")
print(text)
count, index = func.mainFunc(text)
print(count, index)
func.writeToFile("2.txt", count, index)
