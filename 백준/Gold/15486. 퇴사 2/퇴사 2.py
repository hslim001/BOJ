import sys
def find():
    dp = [0] * (num + 2)


    for i in range(num, 0, -1):

        if i + time[i] - 1 > num:
            dp[i] = dp[i + 1]
            continue
        if cost[i] + dp[i + time[i]] > dp[i + 1]:
            dp[i] = cost[i] + dp[i + time[i]]
        else:
            dp[i] = dp[i + 1]


    return dp[1]

num = int(input())
time = [0]
cost = [0]
for _ in range(num):
    t, c = map(int, sys.stdin.readline().split())
    time.append(t)
    cost.append(c)

print(find())