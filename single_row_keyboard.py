def calculateTime(keyboard: str, word: str) -> int:
    # initialize current index to word[0], and time to 0
    # for each character in word, increment time by |current index - next char index|
    curr = keyboard[0]
    time = 0
    for char in word:
        time += abs(keyboard.index(curr) - keyboard.index(char))
        curr = char
    return time


print(calculateTime(keyboard="abcdefghijklmnopqrstuvwxyz", word="cba"))
print(calculateTime(keyboard="pqrstuvwxyzabcdefghijklmno", word="leetcode"))
print(calculateTime(keyboard="pqrstuvwxyzabcdefghijklmno", word="a"))