t = int(input())

for i in range(t):
    n = int(input())
    if n % 4 == 0:
        if n % 400 == 0:
            print("YES")
            continue
        if n % 100 == 0:
            print("NO")
            continue
        print("YES")
    else:
        print("NO")