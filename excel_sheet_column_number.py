class Solution:
    def titleToNumber(self, s: str) -> int:
        """
        create dict of alphabet to value
        reverse input to obtain index (or find a clever to reverse index)
        for letter in input:
            sum += letter ^ index+1
        :param s:
        :return:
        """
        letters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        dict = {}
        for i in range(0, len(letters)):
            dict[letters[i]] = i+1
        # print(dict)
        str = ''
        for i in range(len(s) - 1, -1, -1):
            str += s[i]
        sum = 0
        # dict = {'A': 1, 'B': 2, 'C': 3, 'Y': 25, 'Z': 26}

        for index, letter in enumerate(str):
            sum += dict[letter] * (26 ** index)
        return sum


sol = Solution()
print(sol.titleToNumber('ZY'))
print(sol.titleToNumber('AA'))
print(sol.titleToNumber('A'))
print(sol.titleToNumber('ABCD'))
