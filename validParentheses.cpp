/*
  Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
*/

class Solution {
public:
    bool isValid(string s) {
        stack<int> stack;
        char curr_val;
        std::set<char> starts = {'(', '{', '['};
        std::unordered_map<char, char> lookup = {
            {'(',')'}, 
            {'{','}'},
            {'[',']'}};

        for (char &c : s) {
            curr_val = c;
            if (starts.contains(c)) {
                stack.push(c);
            }
            else if (!stack.empty() && c != lookup[stack.top()]) {
                return false;
            }
            else if (stack.empty()) {
                return false;
            }
            else {
                stack.pop();
            }
        }
        if (starts.contains(curr_val) | !stack.empty()){
            return false;
        }
        return true;
    }
};
