# 样例输入
# 5 2
# 10 1
# 2 2
# 5 2
# 8 1
# 9 1
# 样例输出
# 28.00
n,k = list(map(int,input().split()))
A = [0]
B = [0]
for i in range(n):
    u,v = list(map(int,input().split()))
    if v == 1:
        A.append(u)
    else:
        B.append(u)

A.sort()
B.sort()
print(A,B)
a = len(A)-1
b = len(B)-1
k = min(k, a)
# k 打折机会数
# a A类商品数
# b B类商品数
# dp[k][a][b]
"""
dp[k][a][b] = min{
    dp[k-1][a-1][b-1],
    dp[k-1][a-2][b]
}
"""

dp = [[[0 for i in range(b+1)] for ii in range(a+1)] for iii in range(k+1)]

for i in range(a+1):
    for j in range(b+1):
        dp[0][i][j] = sum(A[:i+1]) + sum(B[:j+1])

for kk in range(1,k+1):
    for i in range(a+1):
        for j in range(1, b+1):
            if i == 0:
                dp[kk][i][j] = sum(B[:j+1])
            elif i == 1:
                dp[kk][i][j] = dp[max(0,kk-1)][max(0,i-1)][max(0,j-1)] + max((A[i]/2+B[j]), (A[i]+B[j]/2))
            else:
                a1 = dp[max(0,kk-1)][max(0,i-2)][j] + A[i] + A[max(0,i-1)] / 2
                a2 = dp[max(0,kk-1)][max(0,i-1)][max(0,j-1)] + max((A[i]/2+B[j]), (A[i]+B[j]/2))
                dp[kk][i][j] = min(a1, a2)
print(dp[k][a][b])