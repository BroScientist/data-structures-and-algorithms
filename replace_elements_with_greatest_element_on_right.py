def replaceElements(arr):
    if len(arr) == 1:
        return [-1]
    for i in range(0, len(arr) - 1):
        arr[i] = max(arr[i+1:])
    arr[-1] = -1
    return arr


print(replaceElements([17, 18, 5, 4, 6, 1]))
print(replaceElements([3]))