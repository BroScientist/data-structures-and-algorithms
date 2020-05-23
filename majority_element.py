class Solution:
    def majorityElement(self, nums) -> int:
        max = 0
        majority_ele = None
        for num in set(nums):
            count = 0
            for i in nums:
                if i == num:
                    count += 1
                if count > max:
                    max = count
                    majority_ele = i
        return majority_ele


sol = Solution()
print(sol.majorityElement([2, 2, 1, 1, 1, 2, 2, 3, 3, 3, 3, 3]))
print(sol.majorityElement([3, 2, 3, 0, 0]))
print(sol.majorityElement([1]))
