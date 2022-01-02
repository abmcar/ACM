while True:
    try:
        temp = int(input())
        ans = 0
        for i in range(1,temp+1):
            if i % 2 == 1:
                ans = ans + i
        print(ans)
    except:
        break