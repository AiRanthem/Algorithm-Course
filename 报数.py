n = int(input())
players = [i for i in range(n)]
A = list(map(int,input().split()))
rank = []
N = n
while(n):
    i = A[N-n]%n
    rank.append(players[i])
    del players[i]
    n -= 1
    i = cnt = 0
rank.reverse()

o = [0 for i in range(N)]
for i, name in enumerate(rank):
    o[name]=i+1
for i in o:
    print(i)
