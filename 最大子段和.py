array = list(map(int,input().split(',')))
b = [0] * len(array)
b[0] = array[0]
for i, a in enumerate(array[1:]):
    b[i+1]=max(b[i]+a, a)
m = max(b)
print(m if m>0 else 0)
