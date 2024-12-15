import tkinter as tk
from tkinter import filedialog, messagebox


def loadFromFile():
    filename = filedialog.askopenfilename(title="Выберите файл", filetypes=[("Text files", "*.txt")])
    with open(filename, 'r') as file:
        data = file.read().split()
        entry_input.delete(0, tk.END)
        entry_input.insert(tk.END, " ".join(data))


def saveToFile(result):
    filename = filedialog.askopenfilename(title="Выберите файл", filetypes=[("Text files", "*.txt")])
    with open(filename, 'w') as file:
        file.write(result)
    messagebox.showinfo("Сохранение", "Результат сохранен")


def findMax(X):
    n = len(X)
    half_count = n // 2
    maximum = max(X[:half_count])
    return maximum


def findMaxSecondHalf(X):
    n = len(X)
    half_count = n // 2
    maximum = max(X[half_count: n])
    return maximum


def mainCommand():
    arr = list(map(int, entry_input.get().split()))
    firstHalf = findMax(arr)
    secondHalf = findMaxSecondHalf(arr)

    res = (f"Максимальный элемент первой половины равен - {firstHalf}\n "
           f"Максимальный элемент второй половины - {secondHalf}\n")

    entry_output.delete("1.0", tk.END)
    entry_output.insert(tk.END, res)

    if messagebox.askyesno("Сохранение", "Сохранить в файл?"):
        saveToFile(res)


window = tk.Tk()
window.title("Лабораторная работа № 10")

tk.Label(window, text="Введите числа через пробел или из файла").pack()
entry_input = tk.Entry(window, width=50)
entry_input.pack()

button_load = tk.Button(window, text="Данные из файла", command=loadFromFile)
button_load.pack(pady=5)

button_process = tk.Button(window, text="Выполнить", command=mainCommand)
button_process.pack(pady=5)

tk.Label(window, text="Результат:").pack()
entry_output = tk.Text(window, width=50, height=5)
entry_output.pack()

window.mainloop()
