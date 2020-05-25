def removeDuplicates(S: str) -> str:
    stack = []
    for char in S:
        if len(stack) > 0 and char == stack[-1]:
            stack.pop()
        else:
            stack.append(char)
    return ''.join([x for x in stack])


print(removeDuplicates('abbaca'))
print(removeDuplicates('eee'))