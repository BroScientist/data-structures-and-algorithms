class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """

        def is_prime(num):
            if num == 1:
                return False
            for i in range(2, num-1):
                if num % i == 0:
                    return False
            return True

        count = 0
        for num in range(1, n):
            if is_prime(num):
                count += 1
                # print(num)

        return count


solution = Solution()
print(solution.countPrimes(10))
print(solution.countPrimes(1))
