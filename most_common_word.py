class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        paragraph = paragraph.replace(',', ' ')
        words = paragraph.split()
        hashtable = {}
        for word in words:
            word = word.strip().lower()
            word = ''.join(x for x in word if x.isalpha())
            if word not in banned:
                if word in hashtable:
                    hashtable[word] += 1
                else:
                    hashtable.update({word: 1})
        return max(hashtable, key=hashtable.get)