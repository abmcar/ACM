t = int(input())

for i in range(t):
    nowString = input()
    nowList = nowString.split(' ')
    tot = 0.0
    for temp in nowList:
        tot = tot + float(temp)
    print("{:.1f}".format(tot/nowList.__len__()))
