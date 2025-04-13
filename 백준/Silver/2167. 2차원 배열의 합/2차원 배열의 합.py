import sys
input=sys.stdin.readline
## 시간 : 672ms
## 공간 : 35480kb

width, length = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(width)]
num = int(input())

for i in range(width):
    for j in range(length):
        if i != 0 and j != 0:
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1]
        elif i != 0:
            arr[i][j] += arr[i - 1][j]
        elif j != 0:
            arr[i][j] += arr[i][j - 1]
for _ in range(num):
    i, j, y, x = map(int, input().split())
    i -= 1
    j -= 1
    y -= 1
    x -= 1
    if i != 0 and j != 0:
        print(arr[y][x] - arr[i - 1][x] - arr[y][j - 1] + arr[i - 1][j - 1])
    elif i != 0:
        print(arr[y][x] - arr[i - 1][x])
    elif j != 0:
        print(arr[y][x] - arr[y][j - 1])
    else:
        print(arr[y][x])