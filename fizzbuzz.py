class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        # result = []
        #
        # for i in range(1, n+1):
        #     if i % 3 == 0 and i % 5 == 0:
        #         result.append('FizzBuzz')
        #     elif i % 3 == 0:
        #         result.append('Fizz')
        #     elif i % 5 == 0:
        #         result.append('Buzz')
        #     else:
        #         result.append(str(i))
        # return result
        result = []
        for i in range(1, n+1):
            output = ''
            if i % 3 == 0:
                output += 'Fizz'
            if i % 5 == 0:
                output += 'Buzz'
            if output == '':
                output = str(i)
            result.append(output)
        return result

solution = Solution()
print(solution.fizzBuzz(16))
# if all interview questions were like this, then oh boy...