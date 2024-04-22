?*
  Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

  */

class Solution {
public:
    string addBinary(string a, string b) {
        int count = 0;
        int a_val = 0;
        int b_val = 0;
        std::reverse(a.begin(), a.end());
        for (auto &c : a) {
            if (c == '1') {
                a_val += std::pow(2, count);
            }
            count++;
        }
        count = 0;
        std::reverse(b.begin(), b.end());
        for (auto &c : b) {
            if (c == '1') {
                b_val += std::pow(2, count);
            }
            count++;
        }
        std::cout << a_val << " = " << b_val << std::endl; 
        std::string ans =  std::bitset< 32 >( a_val + b_val ).to_string(); // string conversion

        int kill_zeros = 0;
        while (ans[kill_zeros] == '0') {
            kill_zeros++;
        }
        if (kill_zeros != std::size(ans)) {
            return ans.substr(kill_zeros, std::size(ans));
        }
        else {
            return "0";
        }
    }
};
