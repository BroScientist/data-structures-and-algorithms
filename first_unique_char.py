class Solution:
    def firstUniqChar(self, s: str) -> int:
        # create set of unique characters from the input (unlike set(s) this maintains the original order)
        unique_letters = []
        for char in s:
            if char not in unique_letters:
                unique_letters += char
        
        # count the num of occurrences of each letter  
        for letter in unique_letters:
            count = 0
            for char in s:
                if char == letter:
                    count += 1
            if count == 1:
                # I accidentally did unique_letters.index(letter) lmao
                return s.index(letter)

        return -1

sol = Solution()
print(sol.firstUniqChar('loveleetcode'))
print(sol.firstUniqChar('leetcode'))
print(sol.firstUniqChar('eeyyzz'))
print(sol.firstUniqChar('dddccdbba'))