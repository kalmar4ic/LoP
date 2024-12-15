
text = ("Создание успешной стратегии в финансовых рынках требует глубокого "
        "понимания как теоретических, так и практических аспектов. Это включает изучение "
        "моделей, анализ данных и учет внешних экономических факторов.")

textReplace = (text.replace(" ", ",")
               .replace(".", ",").replace(",,", ","))
textList = textReplace.split(",")

for i in range(len(textList) - 1):
    change = textList[i]
    if change.count(change[-1]) == 1 and change.count(change[0]) > 1:
        change = change[-1] + change[1:-1] + change[0]
    elif change.count(change[-1]) == 1:
        change = change[-1] + change[:-1]
    elif change.count(change[0]) > 1:
        change = change[1:] + change[0]
    textList[i] = change

returnText = " ".join(textList)

print(text)
print(returnText)
