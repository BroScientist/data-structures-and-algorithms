def build_array(target, n):

    output = []
    counter = 0
    for i in range(1, n+1):
        # target[counter] represents the current target value we are trying to build
        # for every number i from 1 to n, if i is equal to the current target, append it to the output and increment counter
        # if i is not equal to current target, i is useless and we step over it by pushing and popping it
        if i == target[counter]:
            output.append('Push')
            counter += 1
            if counter == len(target):
                break
        else:
            output.append('Push')
            output.append('Pop')

    return output


print(build_array([1, 3], 3))
print(build_array([1, 2, 3], 3))
print(build_array([1, 2], 4))
print(build_array([2, 3, 4], 4))