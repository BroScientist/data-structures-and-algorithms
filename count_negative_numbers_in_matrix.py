def countNegatives(grid) -> int:
    length = len(grid[0])
    count = 0
    for row in grid:
        for num in row:
            if num < 0:
                count += 1
    return count
    # count = 0
    # for row in grid:
    #     for i in range(length-1, -1, -1):
    #         if row[i] >= 0:
    #             break
    #         if row[i] < 0:
    #             count += 1
    # return count


grid = [[4, 3, 2, -1], [3, 2, 1, -1], [1, 1, -1, -2], [-1, -1, -2, -3]]
print(countNegatives(grid))