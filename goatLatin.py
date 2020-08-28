class Solution:
    def toGoatLatin(self, S: str) -> str:
        words = S.split()
        vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
        for index, word in enumerate(words):
            if word[0] in vowels:
                word += 'ma'
            else:
                first = word[0]
                word = word[1:]
                word += first
                word += 'ma'
            word += 'a' * (index + 1)
            words[index] = word
        return ' '.join(words)