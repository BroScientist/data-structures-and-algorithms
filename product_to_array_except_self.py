class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        def calc_product(arr):
            product = 1
            for num in arr:
                product *= num
            return product

        result = []
        for i in range(len(nums)):
            new_arr = nums[:]
            # new_arr.pop(nums[i])
            del new_arr[i]
            # print(new_arr)
            result.append(calc_product(new_arr))
        return result


solution = Solution()
print(solution.productExceptSelf([1, 2, 3, 4]))
print(solution.productExceptSelf([0, 0]))
print(solution.productExceptSelf([-1, 1, 1]))

# [1, 2, 3, 4]
# [2*3*4, 1*3*4, 1*2*4, 1*2*3]
'''
for i range(len(nums)):
    new_arr.append(all nums except one at index i) 
    product(new_arr)
    results.append(product)
'''
