class Solution:
    def printVertically(self, s: str) -> List[str]:
        words = s.split(' ')
        longest = 0
        for word in words:
            longest = max(longest, len(word))
        res = [""] * longest
        for i in range(0, len(words)):
            word = words[i]
            for j in range(0, longest):
                if (j > len(word) - 1):
                    res[j] += ' '
                else:
                    res[j] += word[j]
        res = [word.rstrip() for word in res]
        return res