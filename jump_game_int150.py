"""
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
"""

import numpy as np
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if len(nums) == 1:
            return True
        nums = np.array(nums)
        bad_indexes = np.where(nums == 0)[0]
        if len(bad_indexes) == 0:
            return True

        last_indx = 0
        tmp_nums = nums + list(range(len(nums)))
        for i in bad_indexes:
            good_vals = np.any(tmp_nums[:i] > i)
            if (good_vals == 0) and (i != len(nums) - 1):
                return False
            elif np.any(nums[:i] == i) and (i == len(nums) - 1):
                return True
            last_indx = i

        return True
