class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        for i in range(2, int(x/2)):
            if i*i >= x:
                return int(i)


solution = Solution()
print(solution.mySqrt(8))