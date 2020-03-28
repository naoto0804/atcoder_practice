S = input()
a_min_ind = None
for i, s in enumerate(S):
    if s == 'A' and a_min_ind is None:
        a_min_ind = i
    if s == 'Z':
        z_max_ind = i

print(z_max_ind - a_min_ind + 1)
