import math

# arr = eval(input())
a, b, c = map(float, input().split())

if a + b > c and a + c > b and b + c > a:
    s = (a + b + c) / 2
    area = math.sqrt(s * (s - a) * (s - b) * (s - c))
    print("area={:.2f};perimeter={:.2f}".format(area, s*2))
else:
    print("These sides do not correspond to a valid triangle")
