class Solution:
    def containsDuplicate(self, nums) -> bool:
        return len(nums) != len(set(nums))  # lmfao
        # for num in set(nums):
        #     if nums.count(num) > 1:
        #         return True
        # return False


sol = Solution()
print(sol.containsDuplicate([1, 2, 3, 4]))
