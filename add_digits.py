def addDigits(num: int) -> int:
    def digit_sum(n):
        sum = 0
        for digit in str(n):
            sum += int(digit)
        return sum

    curr_sum = digit_sum(num)
    while curr_sum > 9:
        curr_sum = digit_sum(curr_sum)
    return curr_sum


print(addDigits(38))
print(addDigits(100))