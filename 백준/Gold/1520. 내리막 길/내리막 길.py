from heapq import heappush, heappop
def bfs(width, length, arr):
    que = []
    dp = [[0] * length for _ in range(width)]
    for i in range(width):
        for j in range(length):
            heappush(que, (-arr[i][j], i, j))
    dp[0][0] = 1
    while que:
        val, cur_y, cur_x= heappop(que)

        for dy, dx in (1, 0), (0, 1), (-1, 0), (0, -1):
            temp_y = cur_y + dy
            temp_x = cur_x + dx
            if 0 <= temp_y < width and 0 <= temp_x < length and arr[cur_y][cur_x] > arr[temp_y][temp_x]:
                dp[temp_y][temp_x] += dp[cur_y][cur_x]

    print(dp[width - 1][length - 1])


width, length = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(width)]

bfs(width, length, arr)