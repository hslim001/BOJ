def find(cnt, arr):
    global visit, num, rotate, result
    if cnt == num:
        for idx in arr:
            result = min(result, sum(idx))
        return
    for k in range(num):
        if not visit[k]:
            new_arr = [idx[:] for idx in arr]

            for l in range((rotate[k][1] - rotate[k][0]) // 2):

                for x in range(rotate[k][2] + 1 + l, rotate[k][3] - l + 1):
                    new_arr[rotate[k][0] + l][x] = arr[rotate[k][0] + l][x - 1]

                for x in range(rotate[k][2] + l, rotate[k][3] - l):
                    new_arr[rotate[k][1] - l][x] = arr[rotate[k][1] - l][x + 1]

                for y in range(rotate[k][0] + 1 + l, rotate[k][1] - l + 1):
                    new_arr[y][rotate[k][3] - l] = arr[y - 1][rotate[k][3] - l]

                for y in range(rotate[k][0] + l, rotate[k][1] - l):
                    new_arr[y][rotate[k][2] + l] = arr[y + 1][rotate[k][2] + l]

            visit[k] = 1
            find(cnt + 1, new_arr)
            visit[k] = 0
# 0 : y 시작 1 : y 끝 2 : x 시작 3 : x 끝
width, length, num = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(width)]
rotate = []
for i in range(num):
    r, c, s = map(int, input().split())
    rotate.append((r - s - 1, r + s - 1, c - s - 1, c + s - 1))

result = 99999999
visit = [0] * num
find(0, arr)

print(result)