def maxIncreaseKeepingSkyline(grid):
    """
    :type grid: List[List[int]]
    :rtype: int
    """
    row_maxes = [0] * len(grid)
    col_maxes = []

    # find the max of each row and store in row_maxes
    for i in range(len(grid)):
        row_maxes[i] = max(grid[i])

    # fix the max of each column and store in col_maxes
    for j in range(len(grid[0])):
        curr_max = 0
        for i in range(len(grid)):
            if grid[i][j] > curr_max:
                curr_max = grid[i][j]
        col_maxes.append(curr_max)

    # for each value in grid, compute the difference and add to sum
    # the difference is the max value grid[row][col] can be without exceeding its skyline
    sum = 0
    for row in range(len(grid)):
        for col in range(len(grid[0])):
            sum += min(row_maxes[row], col_maxes[col]) - grid[row][col]
    return sum


maxIncreaseKeepingSkyline([[3, 0, 8, 4],
                           [2, 4, 5, 7],
                           [9, 2, 6, 3],
                           [0, 3, 1, 0]])
