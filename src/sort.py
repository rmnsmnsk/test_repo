import random
n = int(input("Put the size of array "))

m = [random.randint(1, 100) for _ in range(n)]

flag = True

while flag == True:
    flag = False
    for j in range(n-1):
        if m[j+1] < m[j]:
            m[j], m[j+1] = m[j+1], m[j]
            flag = True
    if flag == False:
        break

print("Sorted array:", *m)
