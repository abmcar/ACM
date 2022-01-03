def getGcd(a, b):
    if b != 0:
        return getGcd(b, a % b)
    return a


t = int(input())
for i in range(t):
    t1, t2 = input().split(" ")
    print(getGcd(int(t1),int(t2)))