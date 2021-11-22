# Complete the solution so that it splits the string into pairs of two characters.
# If the string contains an odd number of characters then it should replace the
# missing second character of the final pair with an underscore ('_').

# Example:
# solution('abc') # should return ['ab', 'c_']
# solution('abcdef') # should return ['ab', 'cd', 'ef']

def solution(s):
    if len(s) % 2 == 1:
        s += "_"
    lists = []
    for i in range(0, len(s), 2):
        lists.append(s[i]+s[i+1])
        print(lists)
    return lists