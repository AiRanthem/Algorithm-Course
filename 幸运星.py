n = int(input())
starx = []
stary = []
for i in range(n):
    x,y = list(map(int,input().split()))
    starx.append(x)
    stary.append(y)

sum = 0
for i in range(n):
    hasl = hasr = hasu = hasd = False
    for j in range(n):
        if i == j:
            continue
        if starx[j] < starx[i] and stary[j] == stary[i]:
            hasl = True
        elif starx[j] > starx[i] and stary[j] == stary[i]:
            hasr = True
        elif starx[i] == starx[j] and stary[j] < stary[i]:
            hasu = True
        elif starx[i] == starx[j] and stary[j] > stary[i]:
            hasd = True
    if hasl and hasr and hasu and hasd:
        sum += 1
print(sum)