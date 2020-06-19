def countBattleships(board):

    # traverse the matrix
    # for if board[row][col] is x, increment count, then check its adjacent elements
    # adjacent elements are board[row+1][col] (element to the right), and board[row][col+1] (element below)
    # while right element is not empty water, visit it and mark on board as 'v'; do the same for the element below
    # for new row and col values, if a 'v' is encountered, continue
    count = 0
    for row in range(len(board)):
        for col in range(len(board[0])):
            if board[row][col] == 'X':
                board[row][col] = 'V'
                count += 1
                # i is the search bound when searching up and down for more Xs
                i = 1
                while True:
                    if row + i >= len(board):
                        break
                    if board[row + i][col] != 'X':
                        break
                    board[row + i][col] = 'V'
                    i += 1
                i = 1
                while True:
                    if col + i >= len(board[0]):
                        break
                    if board[row][col + i] != 'X':
                        break
                    board[row][col + i] = 'V'
                    i += 1

    # for row in board:
    #     print(row)
    # print(count)
    return count


print(countBattleships([["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]))