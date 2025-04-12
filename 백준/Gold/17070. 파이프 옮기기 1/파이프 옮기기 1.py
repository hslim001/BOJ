
length = int(input())
arr = [list(map(int, input().split())) + [1] for _ in range(length)]
limit = length - 1
cnt = 0
arr. append([1] * length)


def move(y2, x2, y1, x1):
    if y1 == limit and x1 == limit:
        global cnt
        cnt += 1

    else:

        if not(x1 + 1 == limit and y1 !=limit) and (y2 == y1 or x1 != x2) and arr[y1][x1 + 1] == 0:

            move(y1, x1, y1, x1 + 1)

        if not(y1 + 1 == limit and x1 != limit) and (x2 == x1 or y1 != y2) and arr[y1+1][x1] == 0:

            move(y1, x1, y1 + 1, x1)

        if arr[y1][x1 + 1] == arr[y1+1][x1] == arr[y1+1][x1+1] == 0:
            move(y1, x1, y1 + 1, x1 + 1)
        return

move(0, 0, 0, 1)

print(cnt)