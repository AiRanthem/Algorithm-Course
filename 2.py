n, m, q = list(map(int, input().split()))
A = []
Q = []
for i in range(n):
    A.append(list(map(int, input().split())))
for i in range(q):
    Q.append(list(map(int, input().split())))
hs_row = [] # 行公差s
a_row = []  # 列首项

for i in range(n):
    a1 ,a2, p1, p2 = (0,0,0,0)
    for j in range(m):
        if A[i][j] != 0:
            if not a1:
                a1 = A[i][j]
                p1 = j
            elif not a2:
                a2 = A[i][j]
                p2 = j
                break
    if a1 and a2:
        h = (a2-a1) / (p2-p1)
        hs_row.append(int(h))
        a_row.append(int(a1 - h*(p1)))
    else:
        hs_row.append(0)
        a_row.append(0)

hs_col = []
a_col = []
for j in range(m):
    a1, a2, p1, p2 = (0, 0, 0, 0)
    for i in range(n):
        if A[i][j] != 0:
            if not a1:
                a1 = A[i][j]
                p1 = i
            elif not a2:
                a2 = A[i][j]
                p2 = i
                break
    if a1 and a2:
        h = (a2-a1) / (p2-p1)
        hs_col.append(int(h))
        a_col.append(int(a1 - h*(p1)))
    else:
        hs_col.append(0)
        a_col.append(0)

for question in Q:
    r = question[0] - 1
    c = question[1] - 1
    if a_row[r]:
        print(a_row[r] + hs_row[r] * c)
    elif a_col[c]:
        print(a_col[c] + hs_col[c] * r)
    else:
        print("Unknown")

