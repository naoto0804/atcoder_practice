# https://qiita.com/saki-engineering/items/55467b4f0db9c926e871
from typing import List

def bisect_left(arr: List[int], key: int):
    return bisect(arr, key)


def bisect_right(arr: List[int], key: int):
    return bisect(arr, key, insert_left=False)


def bisect(arr: List[int], key: int, insert_left: bool = True):
    left = 0
    right = len(arr)
    while left < right:
        middle = (right - left) // 2 + left

        # difference is only in "key <OP> arr[middle]"
        if insert_left:  # bisect_left
            if key <= arr[middle]:
                right = middle
            else:
                left = middle + 1
        else:  # bisect_right
            if key < arr[middle]:
                right = middle
            else:
                left = middle + 1
    # note that left and right is always the same
    return left


def bisect_element_index_search(arr: List[int], key: int):
    left = 0
    right = len(arr)
    while left < right:
        middle = (right - left) // 2 + left

        if key == arr[middle]:
            return middle
        elif key < arr[middle]:
            right = middle
        else:
            left = middle + 1
    return -1


def binary_search(arr: List[int], key: int):
    left = 0
    right = len(arr)
    while left < right:
        middle = (right - left) // 2 + left

        if key == arr[middle]:
            return middle
        elif key < arr[middle]:
            right = middle
        else:
            left = middle + 1
    return -1

# 典型的なやつ，整数Nの平方根
def bisect_square_search(target):
    left = 0
    right = 10

    while left <= right:
        middle = (right - left) // 2 + left
        tmp = middle ** 2
        if tmp == target:
            return middle
        elif target < tmp:
            right = middle - 1
        else:
            left = middle + 1
    return right
