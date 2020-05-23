def single_number(nums):
    unique_nums = set()
    for num in nums:
        if num not in unique_nums:
            unique_nums.add(num)
            continue
        if num in unique_nums:
            unique_nums.remove(num)

    return unique_nums.pop()


print(single_number([99, 100, 100, 98, 99]))