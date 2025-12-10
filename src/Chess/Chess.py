from itertools import permutations

# проверка на диагонали
def check_diagonal(queens):
    for i in range(len(queens)):
        for j in range(i + 1, len(queens)):
            if abs(queens[j] - queens[i]) == abs(j - i):
                return False
    return True


# проверка на столбцы
def check_column(queens):
    for i in range(len(queens)):
        for j in range(i + 1, len(queens)):
            if queens[i] == queens[j]:
                return False
    return True


# общая проверка расстановки
def is_valid(queens):
    return check_column(queens) and check_diagonal(queens)


# переборный способ с permutations
def brute_force(n):
    count = 0
    # permutations генерирует все перестановки столбцов
    # это автоматически исключает ферзей в одном столбце
    for perm in permutations(range(n)):
        # остается проверить только диагонали
        if check_diagonal(perm):
            count += 1
    return count


# рекурсивный backtracking
def recursive(n):
    queens = [-1] * n  # -1 значит ферзь еще не поставлен
    count = 0

    # проверка безопасности для новой позиции
    def safe(row, col):
        # проверяем со всеми уже поставленными ферзями
        for prev_row in range(row):
            prev_col = queens[prev_row]
            # один столбец
            if prev_col == col:
                return False
            # диагональ
            if abs(prev_col - col) == abs(prev_row - row):
                return False
        return True

    def place(row):
        nonlocal count
        # если дошли до конца - нашли решение
        if row == n:
            count += 1
            return

        # пробуем все столбцы для текущей строки
        for col in range(n):
            if safe(row, col):
                queens[row] = col  # ставим ферзя
                place(row + 1)     # переходим к след строке

    place(0)
    return count


# итеративный backtracking (стек вместо рекурсии)
def iterative(n):
    count = 0
    stack = [[]]  # стек с частичными решениями

    while stack:
        current = stack.pop()      # берем последнюю расстановку
        length = len(current)      # сколько ферзей уже поставлено

        # если поставили всех ферзей - это решение
        if length == n:
            count += 1
            continue

        # пробуем добавить ферзя в следующую строку
        for col in range(n):
            new = current + [col]  # новая расстановка
            if is_valid(new):      # если подходит
                stack.append(new)  # добавляем в стек для дальнейшего разбора

    return count


n = int(input("Введите размер доски n x n: "))

print("1. Переборный метод:")
result1 = brute_force(n)
print(f"   Результат: {result1}")

print("\n2. Рекурсивный метод:")
result2 = recursive(n)
print(f"   Результат: {result2}")

print("\n3. Итеративный метод:")
result3 = iterative(n)
print(f"   Результат: {result3}")

if result1 == result2 == result3:
    print(f"\nВсе методы дали одинаковый результат: {result1}")
else:
    print(f"\nРезультаты различаются: {result1}, {result2}, {result3}")
