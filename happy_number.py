def isHappy(n):
    def get_sum(num):
        sum = 0
        for digit in str(num):
            sum += int(digit)**2
        return sum

    appeared = set()
    while n != 1 and n not in appeared:
        get_sum(n)
        appeared.add(n)
        n = get_sum(n)

    return n == 1


print(isHappy(19))


