print('Введите два целых числа, причём оба из них быть 0 одновременно быть не могут')
a, b = input(), input()

def check(x):
    if x[0] == '-':
        if len(x) == 1:
            return False
        else:
            x = x[1:]
    for j in x:
        if j not in '0123456789': #тут же проверются и дробные, т.к в них содержаться .
            return False
            break
    else:
        return True

while not(check(a)) or not(check(b)):
    print('Введите два целых числа, причём оба из них быть 0 одновременно быть не могут')
    a,b = input(), input()

a = int(a) #перезаписываем в int
b = int(b)

def gcd(k,m):
    sik = 0 #для учёта изначальных знаков, как обревеатура слова sign и название перемееной
    sim = 0
    if k >= 0:
        sik = 1
    else:
        sik = -1
    if m >= 0:
        sim = 1
    else:
        sim = -1
    k = abs(k) #учитываекм случай с отрицательными числами
    m = abs(m)
    k0, k1 = 1, 0 #коэф для a
    m0, m1 = 0, 1 #коэф для b

    while m != 0:

        q = k // m

        k,m = m, k % m

        k0, k1 = k1, k0 - q * k1
        m0, m1 = m1, m0 - q * m1

    return k, k0 * sik, m0 * sim

max_del, k_a, k_b = gcd(a,b)

print(f'Нод - это {max_del}')
print(f'Коэффициент перед первым числом: {k_a}')
print(f'Коэффициент перед вторым числом {k_b}')
