class Solution:
    def plusOne(self, digits):
        """
        if not nine just add one to the last digit
        if it is nine, make it zero, move to next index, add one to it, and check if it's nine.
        do this until nothing is equal to nine

        special case: all nines
        set(digits) = 9
        return [1] + len(digits) number of zeros
        """
        # if input only contains 9s, make all of them zero and attach a one in front
        if set(digits) == {9}:
            return [1] + ([0] * len(digits))

        i = -1  # I put this inside the loop lmao
        while True:
            # if current digit is 9, make it zero and move back digit
            if digits[i] == 9:
                digits[i] = 0
                i -= 1
            # if current digit is any other number, increment it and we are done
            else:
                digits[i] += 1
                break
        return digits


sol = Solution()
print(sol.plusOne([4, 3, 2, 9]))
print(sol.plusOne([4, 3, 9, 9]))
print(sol.plusOne([4, 9, 9, 9]))
print(sol.plusOne([9, 9, 9, 9]))
print(sol.plusOne([9]))