# 二分探索
# 見つからないと-1を返すバージョン
# l = 0, r = N からスタート
def binary_search(arr, l, r, x):
    while l < r:
        mid = l + (r - l) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            r = mid
        else:
            l = mid + 1
    return -1

# ソート済みの配列が与えられた時丁度いい挿入場所を返すパターン
# 重複がある場合は一番左に入れる
# l = 0, r = N からスタート
def binary_search(nums, target):
    use_left = True
    l = 0
    r = len(nums)
    while l < r:
        mid = (l + r) // 2
        if nums[mid] > target or (use_left and target == nums[mid]):
            r = mid
        else:
            l = mid+1
    return l

nums = [1, 3, 3, 4, 5]
print(binary_search(nums, 0))
