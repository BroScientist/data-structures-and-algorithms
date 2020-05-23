class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """

        zeros = []
        non_zeros = []
        for n in nums:
            if n == 0:
                zeros.append(n)
            else:
                non_zeros.append(n)
        for i in range(0, len(nums)):
            nums[i] = [non_zeros + zeros][0][i]
        print(nums)


solution = Solution()
solution.moveZeroes([0, 1, 0, 3, 12])
solution.moveZeroes([0, 0, 1])

# when it said "You must do this in-place without making a copy of the array" I thought you must do it without creating new arrays...
