# get all combination of binary flags

nums = input()
op_cnt = len(nums) - 1

for i in range(2 ** op_cnt):
    op = ["-"] * op_cnt
    for j in range(op_cnt):
        if ((i >> j) & 1):
            op[op_cnt - 1 - j] = "+"
    formula = ""
    for p_n, p_o in zip(nums, op + [""]):
        formula += (p_n + p_o)
    if eval(formula) == 7:
        print(formula + "=7")
        break
