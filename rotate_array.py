class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        '''copy arr, rotate that one, copy back'''
        new_arr = nums[:]

        for i in range(k):
            new_arr = [new_arr[-1]] + new_arr
            new_arr.pop()

        for i in range(len(nums)):
            nums[i] = new_arr[i]
        print(nums)

sol = Solution()
sol.rotate([1, 2, 3, 4, 5, 6, 7], 3)
sol.rotate([1], 2)