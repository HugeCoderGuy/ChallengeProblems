class Solution {
public:
    int majorityElement(vector<int>& nums) {
        vector<int> nums_copy = nums;
        auto new_unique_end = std::unique(nums_copy.begin(), nums_copy.end());
        int return_val = nums[0];
        for (auto i=nums.begin(); i!=new_unique_end; i++) {
            int num_occurence = count(nums.begin(), nums.end(), *i);
            if (num_occurence > (nums.size()/2)) {
                return_val = *i;
                break;
            }
        }
        return return_val;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = 0;
        std::map<int, int> dict; 
        for (int i=0; i<nums.size(); i++) {
            if (dict.find(nums[i]) == dict.end()) {
                nums[pos] = nums[i];
                dict.insert({nums[i], 1});
                pos++;
            }
            else if (dict.at(nums[i]) == 1) {
                dict[nums[i]]++;
                nums[pos] = nums[i];
                pos++;
            }
        }
        return pos;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = 0;
        std::unordered_set<int> set; 
        for (int i=0; i<nums.size(); i++) {
            if (!set.count(nums[i])) {
                nums[pos] = nums[i];
                set.insert(nums[i]);
                pos++;
            }
        }
        return pos;
    }
};
