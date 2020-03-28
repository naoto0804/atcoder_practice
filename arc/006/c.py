# 今一番上にあるもののリストが保持できれば良い
# このリストを常に昇順ソートした状態で保持しておくと
# 挿入する要素が
# 　　どの要素よりも大きいときだけ新要素が生える
# 　　そうでないときはそれより大きいもののうち最小と入れ替える (かぶりがある場合に注意)
import bisect

N = int(input())
W = []
for i in range(N):
    W.append(int(input()))

current_top_list = []
for w in W:
    if len(current_top_list) == 0:
        current_top_list.append(w)
    else:
        left_ind = bisect.bisect_left(current_top_list, w)
        right_ind = bisect.bisect_right(current_top_list, w)
        if right_ind > left_ind:
            pass    # w matches existing var. in current_top_list, we can skip
        else:
            if left_ind == right_ind == len(current_top_list):
                current_top_list.append(w)  # w is the biggest
            else:
                current_top_list[right_ind] = w
print(len(current_top_list))
