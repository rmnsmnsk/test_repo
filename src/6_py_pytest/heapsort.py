m = list(map(int, input().split()))

def heap_sort(arr):
    if len(arr) == 0:
        return arr
    
    m = arr
    n = len(m)

    for start in range(n//2 - 1, -1, -1):
        current = start
        while True:
            data = m[current]
            index = current
            left = 2 * current + 1
            right = 2 * current + 2

            if left < n and m[left] > data:
                index = left
                data = m[left]
            
            if right < n and m[right] > data:
                index = right
                data = m[right]

            if index != current:
                m[current], m[index] = m[index], m[current]
                current = index
            else:
                break

    for i in range(n-1, 0, -1):
        m[0], m[i] = m[i], m[0]
        current = 0
        while True:
            data = m[current]
            index = current
            left = 2 * current + 1
            right = 2 * current + 2

            if left < i and m[left] > data:
                index = left
                data = m[left]
            
            if right < i and m[right] > data:
                index = right
                data = m[right]

            if index != current:
                m[current], m[index] = m[index], m[current]
                current = index
            else:
                break

    return m

m = heap_sort(m)
print(m)
