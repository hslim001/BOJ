def find(num):
    if num == 0:
        print(0)
        print(0)
        return
    if num == 1 or num == -1:
        print(1)
        print(1)
        return
    dp = [0] * (abs(num) + 1)
    dp[1] = 1
    if num > 0:
        for i in range(2, num + 1):
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000000
    else:
        for i in range(2, abs(num) + 1):
            temp = dp[i - 2] - dp[i - 1]
            dp[i] = temp % 1000000000 if temp >= 0 else (temp % 1000000000) - 1000000000
    if dp[abs(num)] > 0:
        print(1)
    elif dp[abs(num)] < 0:
        print(-1)
    else:
        print(0)

    print(abs(dp[abs(num)]))
num = int(input())
find(num)