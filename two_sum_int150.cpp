/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> possible_combo;
        std::vector<int> answer(2,0);
        std::vector<int> repeats;
        int pair;
        for (int i=0; i<std::size(nums); i++) {
            if (possible_combo.find(nums[i]) != possible_combo.end()) {
                repeats.push_back(nums[i]);
            }
            else {
                possible_combo[nums[i]] = i;
            }
            pair = target - nums[i];
            if (possible_combo.find(pair) != possible_combo.end()) { // && possible_combo[pair] > 0) {
                answer[0] = possible_combo[pair];
                answer[1] = i;
                if (pair == nums[i] && std::count(repeats.begin(), repeats.end(), nums[i])) {
                    return answer;
                }
                else if (pair != nums[i]) {
                    return answer;
                }                
            }
        }
        return answer;

        // std::vector<int> combo(2, 0);
        // for (int i=0; i<std::size(nums)-1; i++) {
        //     for (int j=i+1; j<std::size(nums); j++) {
        //         combo[0] = i;
        //         combo[1] = j;
        //         if (nums[i] + nums[j] == target) {
        //             return combo;
        //         }
        //     }
        // }
        // return combo;
    }
};
