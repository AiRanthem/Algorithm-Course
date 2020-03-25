n = int(input())
ls = []
for i in range(n):
    string = input()[-6:]
    ls.append(int(string))
ls.sort()
for i in ls:
    print(i)
