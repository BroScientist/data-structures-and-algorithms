class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # the code I wrote didn't work for the special cases...
        nums.sort()
        if nums[0] != 0:
            return 0
        elif nums[-1] != len(nums):
            return len(nums)
        if nums == [1]:
            return 0

        for i in range(1, len(nums)):
            if i not in nums:
                return i
'''
find min and max
for i in range(min, max):
    if i not in arr:
        return i
'''
solution = Solution()
print(solution.missingNumber([9, 6, 4, 2, 3, 5, 7, 0, 1]))
print(solution.missingNumber([0]))
print(solution.missingNumber([1]))
print(solution.missingNumber([0, 1]))