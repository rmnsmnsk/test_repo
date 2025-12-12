import pytest
from heap_code import BinHeap


def test_insert():
    h = BinHeap()
    h.insert(5, "a")
    h.insert(3, "b")
    assert h.getMinimum() == (3, "b")


def test_get_min():
    h = BinHeap()
    h.insert(10, "x")
    h.insert(20, "y")
    assert h.getMinimum() == (10, "x")


def test_extract_min():
    h = BinHeap()
    h.insert(7, "a")
    h.insert(2, "b")
    assert h.extractMin() == (2, "b")
    assert h.getMinimum() == (7, "a")


def test_merge():
    h1 = BinHeap()
    h2 = BinHeap()
    h1.insert(5, "a")
    h2.insert(3, "b")
    h1.root_list = h1.merge(h1.root_list, h2.root_list)
    assert h1.getMinimum() == (3, "b")


def test_decrease_key():
    h = BinHeap()
    node = h.insert(10, "test")
    h.decreaseKey(node, 5)
    assert h.getMinimum()[0] == 5


def test_delete():
    h = BinHeap()
    node = h.insert(15, "delete_me")
    h.insert(8, "keep")
    h.delete(node)
    assert h.getMinimum() == (8, "keep")


def test_empty():
    h = BinHeap()
    assert h.getMinimum() is None
    assert h.extractMin() is None

if __name__ == "__main__":
    test_insert()
    test_get_min()
    test_extract_min()
    test_merge()
    test_decrease_key()
    test_delete()
    test_empty()


