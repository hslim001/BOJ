num, limit = map(int, input().split())
coins = []
for _ in range(num):
    temp = int(input())
    if temp <= limit:
        coins.append(temp)

dp = [99999] * (limit + 1)
dp[0] = 0
for i in range(1, limit + 1):
    for coin in coins:
        if coin <= i:
            dp[i] = min(dp[i], dp[i - coin] + 1)
if dp[limit] == 99999:
    dp[limit] = -1
print(dp[limit])