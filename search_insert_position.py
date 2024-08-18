class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        high = len(nums) - 1
        low = 0
        if nums[high] < target:
            return high + 1
        elif nums[low] > target:
            return 0
        while high != low:
            comp_indx = int((high + low) / 2)
            compr_val = nums[comp_indx]
            print(f"High, {high}, Low {low}, comp_indx {comp_indx}")
            if target == compr_val:
                return comp_indx
            elif abs(high-low) == 1 and nums[high] >= target and nums[low] <= target:
                return high
            elif high == low:
                if nums[high] < target:
                    return high + 1
                else:
                    return high
            elif target > compr_val:
                low = comp_indx
            elif target < compr_val:
                high = comp_indx

        return high
