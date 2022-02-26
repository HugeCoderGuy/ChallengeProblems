"""
Task

You will be given an array of numbers. You have to sort the odd numbers in ascending order while leaving the even
numbers at their original positions.

Examples

[7, 1]  =>  [1, 7]
[5, 8, 6, 3, 4]  =>  [3, 8, 6, 5, 4]
[9, 8, 7, 6, 5, 4, 3, 2, 1, 0]  =>  [1, 8, 3, 6, 5, 4, 7, 2, 9, 0]
"""
def sort_array(source_array):
    odds = []
    indexes = []
    for i, j in enumerate(source_array):
        if j % 2 != 0:
            indexes.append(i)
            odds.append(j)
    odds.sort()
    counter = 0
    for place in indexes:
        source_array[place] = odds[counter]
        counter += 1
    return source_array
