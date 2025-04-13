import sys
input = sys.stdin.readline

length = int(input().strip())
arr = [0] + list(map(int, input().split()))
num = int(input())
dp = [[0] * (length + 1) for _ in range(length + 1)]

for i in range(1, length + 1):
    dp[i][i] = 1
    if arr[i] == arr[i - 1]:
        dp[i][i - 1] = 1
    for j in range(i-2, 0, -1):
        if arr[i] == arr[j]:
            if dp[i - 1][j + 1]:
                dp[i][j] = 1

for _ in range(num):
    a, b = map(int, input().split())
    print(dp[b][a])