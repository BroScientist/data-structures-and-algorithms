def generateTheString(n: int) -> str:
    if n == 1:
        return 'a'
    if n % 2 == 0:
        return 'b' + 'a' * (n-1)
    return 'a' * n


print(generateTheString(3))
print(generateTheString(1))
print(generateTheString(6))