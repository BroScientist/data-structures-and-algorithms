def balancedStringSplit(s: str) -> int:
    count = 0
    index = 0
    boundary = 2
    while(True):
        if index == len(s):
            break
        if s[index:index+boundary].count('L') == s[index:index+boundary].count('R'):
            count += 1
            index = index + boundary
            boundary = 2

        else:
            boundary += 2

    return count


print(balancedStringSplit('RLRRRLLRLL'))