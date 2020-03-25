# dp[i][j] 为 i到j 的最大子回文串长度
# 如果 a[i] = a[j] 则 dp[i][j] = 2 + dp[i+1][j-1]
# 否则 dp[i][j] = max(dp[i+1][j], dp[i][j-1])

a = list(input())
l = len(a)
dp = [[0]*l for i in range(l)]
for i in range(l):
    dp[i][i] = 1
    
for step in range(1, l):
    for i in range(l - step):
        j = i + step
        if a[j] == a[i]:
            dp[i][j] = dp[i+1][j-1] + 2
        else:
            dp[i][j] = max(dp[i+1][j], dp[i][j-1])

print(dp[0][l-1])