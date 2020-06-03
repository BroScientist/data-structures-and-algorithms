def sumZero(n: int):
    if n == 1:
        return [0]
    output = []
    # if n is odd, append a zero to the output
    if n % 2 != 0:
        output.append(0)
    # if n is even, loop through int i between 1 and n/2, and populate the output with i and -i
    # this will ensure the array always sum up to zero because the pairs cancel themselves
    for i in range(1, int(n/2)+1):
        output.append(i)
        output.append(-i)
    return output


print(sumZero(5))
print(sumZero(4))
print(sumZero(10))
print(sumZero(1))
print(sumZero(2))