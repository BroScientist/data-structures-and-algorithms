class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        i = 1
        while i <= n:
            if i == n:
                return True
            i *= 3
        return False

sol  = Solution()
print(sol.isPowerOfThree(0))