class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        return n//2 + 1

solution = Solution()
print(solution.climbStairs(6))