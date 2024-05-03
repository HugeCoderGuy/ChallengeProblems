/*
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
 

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::map<char, std::string> pattern_checker;
        std::map<std::string, char> been_matched;
        // variable to store token obtained from the original
        // string
        std::string str;
    
        // constructing stream from the string
        stringstream ss(s);
    
        // declaring vector to store the string after split
        vector<string> v;
    
        // using while loop until the getline condition is
        // satisfied
        // ' ' represent split the string whenever a space is
        // found in the original string
        while (getline(ss, str, ' ')) {
    
            // store token string in the vector
            v.push_back(str);
        }
        if (std::size(pattern) != std::size(v)) {
            return false;
        }
        
        for (int i=0; i<std::size(pattern); i++) {
            std::cout << pattern[i] << " - "  << v[i] << std::endl;
            if ((been_matched.find(v[i]) != been_matched.end()) && (been_matched[v[i]] != pattern[i])) {
                return false;
            }
            else if (pattern_checker.find(pattern[i]) == pattern_checker.end()) {
                pattern_checker[pattern[i]] = v[i];
                been_matched[v[i]] = pattern[i];
            }
            else if ((pattern_checker[pattern[i]] != v[i])) {
                return false;
            }
        }
        return true;
    }
};
