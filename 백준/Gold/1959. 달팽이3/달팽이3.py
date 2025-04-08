
width, length = map(int, input().split())
temp = min(width, length)
result = 0
if temp % 2 == 0:
    result += temp // 2 * 4 - 2
    if width > length:
        result += 1


else:
    result += temp // 2 * 4
    if width > length:
        result += 1




y = 0
x = 0
temp = result % 4
if temp == 0:
    x = length - result // 4
    y = (width // 2) + (1 if width % 2 == 1 else 0)
elif temp == 1:
    x = (length // 2) + (1 if length % 2 == 1 else 0)
    y = width - result // 4
elif temp == 2:
    x = result // 4 + 1
    y = (width // 2) + (0 if width % 2 == 1 else 1)
else:
    x = (length // 2)
    y = result // 4 + 2

print(result)
print(y, x)