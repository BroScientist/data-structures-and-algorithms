class Solution:
    def romanToInt(self, s: str) -> int:
        # a dictionary of character to value
        dict = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000,
            'IV': 4,
            'IX': 9,
            'XL': 40,
            'XC': 90,
            'CD': 400,
            'CM': 900
        }

        result = 0
        i = 0
        while i < len(s):
            char = s[i]
            # get the next character and see if char + next is a valid entry in dict
            # if it is, increment i by 1 to skip the next character
            try:
                next = s[i + 1]
                result += dict[char + next]
                i += 1
            # an exception would be thrown if a) next is out of range b) char + next is not in dict
            # in this case just increment the single character
            except:
                result += dict[char]

            # regardless out the outcome, increment i by 1
            finally:
                i += 1

        return result


sol = Solution()
print(sol.romanToInt('MCMXCIV'))
print(sol.romanToInt('I'))
print(sol.romanToInt('III'))
print(sol.romanToInt('LVIII'))
print(sol.romanToInt('IX'))

'''
loop through string
for each char, check it's next char for special case if it's an I, X or C
    if special, increment accordingly
    if not, add normally
'''
