def selfDividingNumbers(left: int, right: int):
    output = []
    for num in range(left, right+1):
        if 0 < num <= 9:
            output.append(num)
            continue
        if num % 10 == 0:
            continue
        self_divide = True
        for digit in str(num):
            if int(digit) == 0 or num % int(digit) != 0:
                self_divide = False
        if self_divide:
            output.append(num)
    return output


print(selfDividingNumbers(1, 22))
print(selfDividingNumbers(1, 1000))
