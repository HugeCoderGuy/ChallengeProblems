/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        char current_char;
        std::string ans = "";
        int min_possible_len = INT_MAX;
        for (int i=0; i<std::size(strs); i++) {
            if (std::size(strs[i]) < min_possible_len) {
                min_possible_len = std::size(strs[i]);
            }
        }
        // for char in each string char
        for (int i=0; i<min_possible_len; i++) {
            char curr_char = strs[0][i];
            // for string in the list of strings
            for (int j=0; j<std::size(strs); j++) {
                // check each string to see if char matches
                if (strs[j][i] != curr_char) {
                    return ans;
                }
            }
            // all matched so now add this char to the answer!
            ans += curr_char;
        }
        return ans;
    }
};
