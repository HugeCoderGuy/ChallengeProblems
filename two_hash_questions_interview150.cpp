class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::map<char, char> morph;
        std::map<char, char> back_morph;
        for (int i=0; i<s.size();i++) {
            if (!morph.count(s[i])) { //& s[i] != t[i]) {
                morph[s[i]] = t[i];
                if (back_morph[t[i]]) {
                    return false;
                }
                back_morph[t[i]] = s[i];
            }
            else {
                if (morph[s[i]] != t[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::map<char, int> mag_map;
        for (int i=0; i<magazine.size(); i++) {
            if (!mag_map.count(magazine[i])) {
                mag_map[magazine[i]] = 1;
            }
            else {
                mag_map[magazine[i]] += 1;
            }
        }
        for (int i=0; i<ransomNote.size(); i++) {
            if (mag_map.count(ransomNote[i])) {
                mag_map[ransomNote[i]]--;
                if (mag_map[ransomNote[i]] < 0) {
                    return false;
                }
            }
            else {
                return false;
            }
        }

        return true;
    }
};
