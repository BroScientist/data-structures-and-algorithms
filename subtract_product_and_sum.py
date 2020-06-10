def subtractProductAndSum(n: int) -> int:
    sum = 0
    product = 1
    for digit in str(n):
        sum += int(digit)
        product *= int(digit)
    return product - sum


print(subtractProductAndSum(234))
print(subtractProductAndSum(4421))
