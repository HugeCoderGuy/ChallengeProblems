/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::map<char, int> s_count;
        std::map<char, int> t_count;
        for (auto c : s) {
            if (s_count.find(c) == s_count.end()) {
                s_count[c] = 1;
            }
            else {
                s_count[c]++;
            }
        }
        for (auto c : t) {
            if (t_count.find(c) == t_count.end()) {
                t_count[c] = 1;
            }
            else {
                t_count[c]++;
            }
        }
        if (s_count == t_count) {
            return true;
        }
        else {
            return false;
        }
    }
};
