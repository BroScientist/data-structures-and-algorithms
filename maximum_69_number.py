def maximum69Number(num: int) -> int:
    digits = [x for x in str(num)]
    for i in range(0, len(digits)):
        if digits[i] == '6':
            digits[i] = '9'
            return int(''.join(digits))
    return num
n = 9996
print(maximum69Number(n))