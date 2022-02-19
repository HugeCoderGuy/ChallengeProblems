import math


a = [0, 2, 3, 4, 5]
b = [1, 2, 3, 45, 6, 7, 8, 9, 2]

remove = []
for i, j in enumerate(b):
    if j in a:
        remove.append(i)
for subtract in reversed(remove):
    b.pop(subtract)
print(b)
print("stop")