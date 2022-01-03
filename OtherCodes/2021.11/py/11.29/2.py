t = int(input())

for i in range(t):
    nowString = input()
    cnt = 0
    for nowChar in nowString:
        if (nowChar >= '0') & (nowChar <= '9'):
            cnt = cnt + 1
    print(cnt)
