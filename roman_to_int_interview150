class Solution {
public:
    int romanToInt(string s) {
        int added_val = 0; 
        char last_char = s[0];
        std::map<char, int> roman_char = {{'I', 1}, {'V', 5,}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for (char& c : s) {
            added_val += roman_char[c];
            if (last_char == 'I' & (c == 'V' | c == 'X')) {
                added_val -= 2;
            }
            else if (last_char == 'X' & (c=='L' | c=='C')) {
                added_val -= 20;
            }
            else if (last_char == 'C' & (c=='D' | c=='M')) {
                added_val -= 200;
            }
            last_char = c;
        }

        return added_val;
    }
};
