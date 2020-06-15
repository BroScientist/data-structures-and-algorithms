def groupAnagrams(strs):
    dict = {}
    for word in strs:
        ordered_word = ''.join(sorted(word))
        if ordered_word in dict.keys():
            dict[ordered_word].append(word)
        else:
            dict[ordered_word] = [word]
    return dict.values()


groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"])