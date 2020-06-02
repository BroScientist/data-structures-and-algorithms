def isArmstrong(N: int) -> bool:
    sum = 0
    for digit in str(N):
        sum += int(digit) ** len(str(N))
    return sum == N

print(isArmstrong(153))
print(isArmstrong(123))
print(isArmstrong(644))
print(isArmstrong(0))