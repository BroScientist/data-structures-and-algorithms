class Solution:
    def generate(self, numRows: int):
        # for the current row, value at index i is equal prev_row[i] + prev_row[i-1]
        def get_next_row(prev_row):
            row = [1] * (len(prev_row) + 1)
            for i in range(1, len(row)-1):
                row[i] = prev_row[i] + prev_row[i-1]
            return row

        answer = [[1]]
        previous = [1, 1]
        if numRows == 0:
            return []  # how is this a test case? makes zero sense
        # handling the special cases of numRows = 1 and 2
        if numRows == 1:
            return answer
        answer.append(previous)
        if numRows == 2:
            return answer

        # for every row after the second, compute the current row based on the previous row
        for i in range(2, numRows):
            current_row = get_next_row(previous)
            previous = current_row
            answer.append(current_row)

        return answer


sol = Solution()
print(sol.generate(8))
print(sol.generate(1))
print(sol.generate(2))
print(sol.generate(3))
print(sol.generate(0))