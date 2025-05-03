def find(num):
    if num == 1:
        return 1
    dp = [0] * (num + 1)
    dp[0] = 1
    dp[1] = 1
    for i in range(2, num + 1):
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746
    return dp[num]
num = int(input())
print(find(num))