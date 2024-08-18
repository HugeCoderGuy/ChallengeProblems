class Solution:
    def isHappy(self, n: int) -> bool:
        next = 0
        seen_vals = set()
        while n != 1:
            next_n = 0
            while n != 0:
                next_n += (n % 10)**2
                n -= (n % 10)
                n = n/10
            n = next_n
            if n in seen_vals:
                return False
            else:
                seen_vals.add(n)

        return True
