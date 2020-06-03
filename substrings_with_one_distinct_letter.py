def countLetters(S: str) -> int:
    count = 0
    # find all substrings of S
    substrings = [S[i:j] for i in range(len(S)) for j in range(i + 1, len(S) + 1)]
    # for every substring, increment count if set(S) == 1
    for s in substrings:
        if len(set(s)) == 1:
            count += 1
    return count


print(countLetters("aaaba"))
print(countLetters("aaaaaaaaaa"))
print(countLetters("a"))
print(countLetters(""))