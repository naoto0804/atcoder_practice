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
