def decompressRLElist(nums):
    result = []
    for i in range(0, len(nums), 2):
        result += [nums[i+1]] * nums[i]
    # print(result)
    return result


decompressRLElist([1, 2, 3, 4])
decompressRLElist([1, 1, 2, 3])
decompressRLElist([2, 2])