import itertools

def next_bigger(n):
    string_n = str(n)
    print(n)
    for i in reversed((range(0, len(string_n)))):
        if int(string_n[i]) > int(string_n[i-1]):
            largest = i
            value = string_n[i]
            break
        else:
            return -1
    print("index: ", largest, "value:", value)
    print("next")
    for j in reversed(range(0, largest)):
        print(j)
        if int(string_n[j]) < int(string_n[largest]):
            larger = j
            value2 = string_n[j]
            break
    print("index: ",larger, "value", value2)
    list_n = list(string_n)
    list_n[larger] = value
    list_n[largest] = value2
    print("input", n, "output", "".join(list_n))
    return int("".join(list_n))
    """Find the highest index i such that s[i] < s[i+1]. If no such index exists, the 
    permutation is the last permutation.
Find the highest index j > i such that s[j] > s[i]. Such a j must exist, since i+1 is 
such an index.
Swap s[i] with s[j].
Reverse the order of all of the elements after index i till the last element."""

def next_bigger1(n):
    l = []
    lst = []
    [lst.append(int(x)) for x in str(n)]
    permutations = list(itertools.permutations(lst))
    for i in permutations:
        number = int(''.join(map(str, lst)))
        l.append(number)
    l.sort()
    location = l.index(n)
    return l[location+1]
