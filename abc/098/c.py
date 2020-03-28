N = int(input())
S = input()

e_acc, w_acc = 0, 0
e_acc_list = [0]
w_acc_list = [0]
acc = {'E': 0, 'W': 0}
acc_list = {'E': [0], 'W': [0]}
for s in S:
    if s == 'E':
        acc['E'] += 1
    else:
        acc['W'] += 1
    acc_list['E'].append(acc['E'])
    acc_list['W'].append(acc['W'])

def count(l_ind, r_ind, symbol):
    # assert l_ind < r_ind
    if r_ind < 0 or l_ind > N - 1:
        return 0
    else:
        if symbol == 'E':
            return acc_list['E'][r_ind] - acc_list['E'][l_ind]
        else:
            return acc_list['W'][r_ind] - acc_list['W'][l_ind]

cost = 1e10

for i in range(N):  # ind of leader
    tmp = count(0, i, 'W') + count(i + 1, N, 'E')
    if tmp < cost:
        cost = tmp
print(cost)
