def find(num):
    arr = [list(map(int, input().split())) for _ in range(num)]

    arr[1][0] += arr[0][1]
    arr[1][1] += min(arr[0][1], arr[1][0], arr[0][2] + arr[0][1])
    arr[1][2] += min(arr[0][1], arr[1][1], arr[0][2] + arr[0][1])
    for i in range(2, num):
        arr[i][0] += min(arr[i - 1][0], arr[i - 1][1])
        arr[i][1] += min(arr[i - 1][0], arr[i - 1][1], arr[i - 1][2], arr[i][0])
        arr[i][2] += min(arr[i - 1][2], arr[i - 1][1], arr[i][1])

    return arr[num - 1][1]
tc = 0
while 1:
    tc += 1
    num = int(input())
    if num == 0:
        break

    print(f'{tc}. {find(num)}')