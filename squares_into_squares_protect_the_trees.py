import math

def helper(n, c):
    """
    Find a set of distinct numbers, each no greater than C, whose
    squares sum to N.

    Returns as a list, in numerical order.

    If no such set exists, return None.
    """
    if n == 0:
        return []
    if n < c * c:
        c = int(math.sqrt(n))
    if c == 0:
        return None
    try:
        return helper(n - c * c, c - 1) + [c]
    except TypeError:
        # the recursive call returned None, so try the next smaller
        # candidate instead
        return helper(n, c - 1)

def decompose(n):
    return helper(n * n, n - 1)