/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, 
representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. 
To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be 
merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n != 0) {
            int num2_count = 0;
            for (int i=0; i<m+n; i++) {
                int pushes = 0;
                while (num2_count < n && nums2[num2_count] <= nums1[i + pushes]) {
                    nums1.insert(nums1.begin() + i + pushes, nums2[num2_count]);
                    num2_count += 1;
                    pushes++;
                }
            }
            for (int i=0; i<n; i++) {
                nums1.erase(nums1.end() - 1);
            }
            if (num2_count != n) {
                while (num2_count < n) {
                    nums1.push_back(nums2[num2_count]);
                    num2_count += 1;
                }
            }
        }


    }
};
