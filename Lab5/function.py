def fill_list():
    count = int(input("Введите кол-во элементов: "))
    X = []
    for i in range(count):
        el = int(input("Введите элемент: "))
        X.append(el)
    return X


def find_max(X):
    n = len(X)
    half_count = n // 2
    maximum = max(X[:half_count])
    return maximum


def find_max_second_half(X):
    n = len(X)
    half_count = n // 2
    maximum = max(X[half_count: n])
    return maximum