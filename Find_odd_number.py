# Given an array of integers, find the one that appears an odd number of times.

# There will always be only one integer that appears an odd number of times.

# Examples

# [7] should return 7, because it occurs 1 time (which is odd).
# [0] should return 0, because it occurs 1 time (which is odd).
# [1,1,2] should return 2, because it occurs 1 time (which is odd).
# [0,1,0,1,0] should return 0, because it occurs 3 times (which is odd).
# [1,2,2,3,3,3,4,3,3,3,2,2,1] should return 4, because it appears 1 time (which is odd).

def find_it(seq):
    list = []
    count = 0
    for i in seq:
        if i not in list:
            list.append(i)
    for j in range(0, len(list)):
        print(j)
        for k in range(0, len(seq)):
            print(k)
            if list[j] == seq[k]:
                count += 1
        if count % 2 ==1:
            return list[j]
    return None

