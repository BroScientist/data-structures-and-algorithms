class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        if set(s) != set(t):
            return False

        dict1 = {}
        dict2 = {}

        for char in set(s):
            dict1[char] = s.count(char)

        for char in set(t):
            dict2[char] = t.count(char)

        if dict1 != dict2:
            return False

        return True


sol = Solution()
print(sol.isAnagram(s='anagram', t='nagaram'))
print(sol.isAnagram(s='rat', t='cat'))
print(sol.isAnagram(s='   ', t='   '))