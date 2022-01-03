while True:
    try:
        temp = input()
        ans = 0
        for nowChar in temp:
            ans = ans + int(nowChar)
        print(ans)
    except:
        break