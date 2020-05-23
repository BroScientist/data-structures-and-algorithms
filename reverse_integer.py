class Solution:
    def reverse(self, x: int) -> int:
        print(x)
        num = ''
        x = str(x)
        negative = False
        for i in range(len(x)-1, -1, -1):
            if x[i] == '-':
                negative = True
            else:
                num += x[i]
        if negative:
            num = -int(num)
        else:
            num = int(num)
        return num if (2 ** 31) - 1 >= num >= (-2 ** 31) else 0

sol = Solution()
print(sol.reverse(-2147483648))