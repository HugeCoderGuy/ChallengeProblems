"""
Complete the function/method (depending on the language) to return true/True when its
argument is an array that has the same nesting structures and same corresponding length
of nested arrays as the first array.

For example:

# should return True
same_structure_as([ 1, 1, 1 ], [ 2, 2, 2 ] )
same_structure_as([ 1, [ 1, 1 ] ], [ 2, [ 2, 2 ] ] )

# should return False
same_structure_as([ 1, [ 1, 1 ] ], [ [ 2, 2 ], 2 ] )
same_structure_as([ 1, [ 1, 1 ] ], [ [ 2 ], 2 ] )

# should return True
same_structure_as([ [ [ ], [ ] ] ], [ [ [ ], [ ] ] ] )

# should return False
same_structure_as([ [ [ ], [ ] ] ], [ [ 1, 1 ] ] )
"""


def same_structure_as(original, other):
    print(original, other)
    index1 = []
    index2 = []
    if not isinstance(original, list) or not isinstance(other, list):
        return False
    for i, value in enumerate(original):
        print("i : ", value)
        if isinstance(value, list):
            index1.append(i)
    for j, value in enumerate(other):
        if isinstance(value, list):
            index2.append(j)

    print("index1 = ", str(index1), "index2 = ", str(index2))
    if index1 != index2:
        return False
    for z in index1:
        print(str(original[z]), " ... ", str(other[z]))
        print(len(original[z]), " other length: ", len(other[z]))
        if len(original[z]) != len(other[z]):
            return False
    else:
        return True
