from itertools import product

n = int(input("Введите n для доски n x n "))

num = 0


# переборный способ
def diag(m):  # проверка на диагональт
    for i in range(len(m)):
        for j in range(i + 1, len(m)):
            if abs(m[j] - m[i]) == abs(i - j):
                return False
    return True


def stolb(m):
    for i in range(len(m)):
        for j in range(i + 1, len(m)):
            if m[i] == m[j]:
                return False
    return True


for u in product([i for i in range(n)], repeat=n):
    # u - будет массив, где строка - индекс, столбец - число
    # при таком задании фрези не стоят на одной стр
    if stolb(u) and diag(u):
        num += 1

print(f"Количество перестановок (перестановочный способ): {num}")

# рекурсивный способ, с исп уже написанных функций diag и stolb
field = [0] * n


def solve(row):
    count1 = 0

    if row == n:
        return True  # по факту 1 или 0, 1 означает, что расстановка верна

    for i in range(n):
        field[row] = i
        q = field[: row + 1]  # учитывается часть, где ферзи поставлены
        # ведь изначально массив заполнен просто одинаковыми числами
        if stolb(q) and diag(q):
            count1 += solve(row + 1)
    return count1


total = solve(0)

print(f"Количество перестановок (рекурсивный способ): {total}")

# своё решение, с исп уже написанных функций diag и stolb


def mine(n):

    board = [[]]
    count = 0
    while len(board) != 0:

        current = board.pop()  # т.е я беру последнюю подходяшую растановку
        lenght = len(current)  # использую pop(), чтобы не было беск цикла

        if lenght == n:
            count += 1
            continue  # чтобы не уходить в цикл ниже
            # ведь если длина равна n, то это подх решение

        for i in range(n):  # перебираю столбцы
            current1 = current + [i]  # пытаюсь добавить ферзя на след строку
            if diag(current1) and stolb(current1):
                board.append(current1)  # добавляю подходящий вариант на конкретно этом шаге
    return count


total1 = mine(n)

print(f"Количество перестановок (третий способ): {total1}")
