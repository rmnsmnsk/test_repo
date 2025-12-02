import random

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

def bubble(arr):
    n = len(arr)
    for i in range(n):
        for j in range(n-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr

def gnome(arr):
    i = 0
    n = len(arr)
    while i < n:
        if i == 0 or arr[i] >= arr[i-1]:
            i += 1
        else:
            arr[i], arr[i-1] = arr[i-1], arr[i]
            i -= 1
    return arr

def usual(arr):
    return sorted(arr)

def test_empty():
    assert heap_sort([]) == []
    assert bubble([]) == []
    assert gnome([]) == []
    assert usual([]) == []

def test_single():
    assert heap_sort([5]) == [5]
    assert bubble([5]) == [5]
    assert gnome([5]) == [5]
    assert usual([5]) == [5]

def test_sorted():
    assert heap_sort([1, 2, 3, 4, 5]) == [1, 2, 3, 4, 5]
    assert bubble([1, 2, 3, 4, 5]) == [1, 2, 3, 4, 5]
    assert gnome([1, 2, 3, 4, 5]) == [1, 2, 3, 4, 5]
    assert usual([1, 2, 3, 4, 5]) == [1, 2, 3, 4, 5]

def test_reverse():
    assert heap_sort([5, 4, 3, 2, 1]) == [1, 2, 3, 4, 5]
    assert bubble([5, 4, 3, 2, 1]) == [1, 2, 3, 4, 5]
    assert gnome([5, 4, 3, 2, 1]) == [1, 2, 3, 4, 5]
    assert usual([5, 4, 3, 2, 1]) == [1, 2, 3, 4, 5]

def test_duplicates():
    assert heap_sort([3, 1, 4, 1, 5]) == [1, 1, 3, 4, 5]
    assert bubble([3, 1, 4, 1, 5]) == [1, 1, 3, 4, 5]
    assert gnome([3, 1, 4, 1, 5]) == [1, 1, 3, 4, 5]
    assert usual([3, 1, 4, 1, 5]) == [1, 1, 3, 4, 5]

def test_negative():
    assert heap_sort([-2, -10, 100, 9]) == [-10, -2, 9, 100]
    assert bubble([-2, -10, 100, 9]) == [-10, -2, 9, 100]
    assert gnome([-2, -10, 100, 9]) == [-10, -2, 9, 100]
    assert usual([-2, -10, 100, 9]) == [-10, -2, 9, 100]

def test_heap_bubble():
    for _ in range(20):
        array = [random.randint(-50, 50) for _ in range(10)]
        assert heap_sort(array[:]) == bubble(array[:])

def test_heap_gnome():
    for _ in range(20):
        array = [random.randint(-50, 50) for _ in range(10)]
        assert heap_sort(array[:]) == gnome(array[:])

def test_all_equal():
    assert heap_sort([1, 2, 3]) == bubble([1, 2, 3]) == gnome([1, 2, 3]) == usual([1, 2, 3])
    assert heap_sort([3, 2, 1]) == bubble([3, 2, 1]) == gnome([3, 2, 1]) == usual([3, 2, 1])
    assert heap_sort([1, 1, 1]) == bubble([1, 1, 1]) == gnome([1, 1, 1]) == usual([1, 1, 1])
    assert heap_sort([5, -1, 0]) == bubble([5, -1, 0]) == gnome([5, -1, 0]) == usual([5, -1, 0])