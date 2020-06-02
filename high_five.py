def highFive(items):
    data = {}
    for item in items:
        # if student is already in data, append the current score to its list
        # if student is new, make a new dictionary entry for it
        try:
            data[item[0]].append(item[1])
        except KeyError:
            data.update({item[0]: [item[1]]})
    # print(data)

    # loop over every item in the dictionary and append two values to the output
    # one is the number representing the student
    # two is the average of its top 5 scores
    output = []
    for item in sorted(data.items()):
        average = int(sum(sorted(item[1], reverse=True)[:5]) / 5)
        output.append([item[0], average])

    return output


highFive([[3,81], [1,91],[1,92],[3,81],[2,93],[2,97],[3,81],[1,60],[2,77],[3,81],[1,65],[1,87],[3,81],[3,81],[1,100],[2,100],[2,76]])

