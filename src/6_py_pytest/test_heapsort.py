import random
import pytest

from heapsort import heap_sort

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

@pytest.mark.parametrize("sort_func", [heap_sort, bubble, gnome, usual])
def test_empty(sort_func):
    assert sort_func([]) == []

@pytest.mark.parametrize("sort_func", [heap_sort, bubble, gnome, usual])
def test_single(sort_func):
    assert sort_func([5]) == [5]

@pytest.mark.parametrize("sort_func", [heap_sort, bubble, gnome, usual])
def test_sorted(sort_func):
    assert sort_func([1, 2, 3, 4, 5]) == [1, 2, 3, 4, 5]

@pytest.mark.parametrize("sort_func", [heap_sort, bubble, gnome, usual])
def test_reverse(sort_func):
    assert sort_func([5, 4, 3, 2, 1]) == [1, 2, 3, 4, 5]

@pytest.mark.parametrize("sort_func", [heap_sort, bubble, gnome, usual])
def test_duplicates(sort_func):
    assert sort_func([3, 1, 4, 1, 5]) == [1, 1, 3, 4, 5]

@pytest.mark.parametrize("sort_func", [heap_sort, bubble, gnome, usual])
def test_negative(sort_func):
    assert sort_func([-2, -10, 100, 9]) == [-10, -2, 9, 100]

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