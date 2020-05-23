str = ["h","e","l","l","o"]
left = 0
right = len(str) - 1
while left < right:
    tmp = str[left]
    str[left] = str[right]
    str[right] = tmp
    left += 1
    right -= 1

print(str)
