from collections import deque
def bfs(i, j, arr, visit, island):
    que = deque([(i, j)])
    visit[i][j] = 1
    arr[i][j] = island
    while que:
        cur_y, cur_x = que.popleft()

        for dy, dx in [(-1, 0), (0, -1), (1, 0), (0, 1)]:
            tempy = cur_y + dy
            tempx = cur_x + dx
            if 0 <= tempy < width and 0 <= tempx < length and arr[tempy][tempx] and not visit[tempy][tempx]:
                arr[tempy][tempx] = island
                visit[tempy][tempx] = 1
                que.append((tempy, tempx))


def find(y, x, dy, dx, cur):
    global arr, bridge
    cnt = 1
    tempy, tempx = y, x

    while 1:
        tempy += dy
        tempx += dx
        if not 0 <= tempy < width or not 0 <= tempx < length:
            return
        if arr[tempy][tempx]:
            if cnt == 1 or arr[tempy][tempx] == cur:
                return


            graph.add((cur, arr[tempy][tempx],cnt))
            return
        cnt += 1




width, length = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(width)]
visit = [[0] * length for _ in range(width)]
island = 0

for i in range(width):
    for j in range(length):
        if arr[i][j] and not visit[i][j]:
            island += 1
            bfs(i, j, arr, visit, island)

graph = set()
for i in range(width):
    for j in range(length):
        if arr[i][j] == 0:
            continue
        for dy, dx in [(-1, 0), (0, -1), (1, 0), (0, 1)]:
            tempy = i + dy
            tempx = j + dx
            if 0 <= tempy < width and 0 <= tempx < length and arr[tempy][tempx] == 0:
                find(tempy, tempx, dy, dx, arr[i][j])

parent = [i for i in range(island + 1)]
result = 0
graph = list(graph)
graph.sort(key=lambda x : x[2])
visited = [0] * (island + 1)
def find_parent(x):
    if parent[x] != x:
        parent[x] = find_parent(parent[x])
    return parent[x]

def union(a, b):
    pa = find_parent(a)
    pb = find_parent(b)
    if pa < pb:
        parent[pb] = pa
    else:
        parent[pa] = pb
for a, b, pay in graph:
    if find_parent(a) != find_parent(b):
        union(a, b)
        result += pay
        visited[a] = 1
        visited[b] = 1

for i in range(1, island + 1):
    find_parent(i)
parent.pop(0)
if len(list(set(parent))) > 1:
    print(-1)
else:
    print(result)