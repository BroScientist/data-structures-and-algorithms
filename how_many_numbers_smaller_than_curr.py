def smallerNumbersThanCurrent(nums):
    # use two loops. The first loop goes from current index to end, the second from 0 to curr
    # for each loop, increment count if the number is greater than current, then return count
    output = []
    for i in range(len(nums)):
        count = 0
        # loop from current to end
        for j in range(i, len(nums)):
            if nums[j] < nums[i]:
                count += 1
        # loop from start to current
        for j in range(0, i):
            if nums[j] < nums[i]:
                count += 1
        output.append(count)
    return output


print(smallerNumbersThanCurrent([8, 1, 2, 2, 3]))
print(smallerNumbersThanCurrent([6, 5, 4, 8]))
print(smallerNumbersThanCurrent([7, 7, 7, 7]))