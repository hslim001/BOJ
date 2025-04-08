dp = [[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
     [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
     [0, 1, 2, 3, 4, 5, 6, 7, 8, 9],
     [0, 0, 1, 3, 6, 10, 15, 21, 28, 36],
     [0, 0, 0, 1, 4, 10, 20, 35, 56, 84],
     [0, 0, 0, 0, 1, 5, 15, 35, 70, 126],
     [0, 0, 0, 0, 0, 1, 6, 21, 56, 126],
     [0, 0, 0, 0, 0, 0, 1, 7, 28, 84],
     [0, 0, 0, 0, 0, 0, 0, 1, 8, 36],
     [0, 0, 0, 0, 0, 0, 0, 0, 1, 9],
     [0, 0, 0, 0, 0, 0, 0, 0, 0, 1]]



result = [0, 10, 55, 175, 385, 637, 847, 967, 1012, 1022, 1023]

def find(dp, result, temp, num):

    val = result[temp]
    output = ''
    idx = 9
    for i in range(temp, 0, -1):
        for j in range(idx, -1, -1):
            if val - dp[i][j] < num:
                output += str(j)
                idx = j - 1
                break

            val -= dp[i][j]

    return output
num = int(input()) + 1
temp = 0
if num <= 1023:
    for i in range(1, len(result)):
        if result[i] >= num:
            temp = i
            break

    print(find(dp, result, temp, num))
else:
    print(-1)