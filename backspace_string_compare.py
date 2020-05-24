def backspaceCompare(S: str, T: str) -> bool:
    stack1 = []
    for char in S:
        if char == '#':
            if len(stack1) == 0:
                continue
            stack1.pop()
        else:
            stack1.append(char)

    stack2 = []
    for char in T:
        if char == '#':
            if len(stack2) == 0:
                continue
            stack2.pop()
        else:
            stack2.append(char)

    return stack1 == stack2


s = 'a#c'
t = 'b'
print(backspaceCompare(s, t))