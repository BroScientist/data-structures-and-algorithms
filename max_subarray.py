nums = [-2, -1]


def max_subarray(nums):
    """
    :type nums: List[int]
    :rtype: int
    """

    def subarray_sum(nums, start_index, end_index):
        sum = 0
        for i in range(start_index, end_index+1):
            sum += nums[i]
        return sum

    if len(nums) == 1:
        return nums[0]

    max_sum = max(nums)
    for i in range(len(nums)):
        for j in range(i, len(nums)):
            if subarray_sum(nums, i, j) > max_sum:
                max_sum = subarray_sum(nums, i, j)
    return max_sum


print(max_subarray(nums))