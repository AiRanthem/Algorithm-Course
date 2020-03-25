def max_sub_array_sum(array):
    if not array:
        return []
    b = [0] * len(array)
    b[0] = array[0]
    for i, a in enumerate(array[1:]):
        b[i+1] = max(b[i]+a, a)
    for i, bb in enumerate(b):
        if bb < 0:
            b[i] = 0
    return b


_, M = list(map(int, input().split()))
A = list(map(int, input().split()))
S = []  # 简化A

first_positive = -1
for i, a in enumerate(A):
    if a > 0:
        first_positive = i
        break

if first_positive == -1:
    print(0)
    exit()

positive = 1
tmp = 0
for a in A[first_positive:]:
    if a * positive >= 0: # 符号不变
        tmp += a
    else: # 符号改变
        S.append(tmp)
        tmp = a
        positive = -positive
if positive >= 0:
    S.append(tmp)

# 正数和负数的个数
l = len(S)
negative = l // 2
positive = l - negative

if M >= positive:
    print(sum([S[2*i] for i in range(positive)]))
    exit()

# 状态转移方程：
# p[i][j] = <=i个子段且最后一个子段以第j个结束的最大i子段和
# msas(array) = array的最大子段和，O(n)
# p[i][j] = max(p[i-1][k] + msas(S[k+1:j])), 0<=k<=j+1
# 这里只涉及两行，所以只用两个列表存。用过的就直接丢弃。
current_row = max_sub_array_sum(S)
for m in range(1,M):
    before_row = current_row
    current_row = [0] * (l+1)
    before_max = 0 # 前一行目前为止见到的最大的，也就是max(before)
    for j in range(1, l + 1):
        before_max = max(before_max, before_row[j-1]) # 前j-1个组i-1段的最大值
        current_row[j] = max(before_max, current_row[j-1]+S[j-1])
print(max(current_row))