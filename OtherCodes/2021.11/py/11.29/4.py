t = int(input())

for i in range(t):
    nowNum = int(input())
    temp = 1
    flag = 0
    while (temp * temp) <= nowNum:
        temp = temp + 1
        if (temp * temp) > nowNum:
            break
        if nowNum % temp == 0:
            print("no")
            flag = 1
            break
    if flag == 0:
        print("yes")

