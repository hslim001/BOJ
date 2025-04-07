def find(num):
    if num % 2 == 1:
        return 0
    dp = [0] * (num + 1)
    dp[0] = 1
    dp[2] = 3
    for i in range(4, num + 1, 2):
        dp[i] = dp[i - 2] * 3
        for j in range(4, i + 1, 2):
            dp[i] += dp[i - j] * 2

    return dp[num]

print(find(int(input())))