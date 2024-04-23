class Solution {
public:
    string addBinary(string a, string b) {
        int shortest_bit_length = std::min(std::size(a), std::size(b));
        int max_bit_length = std::max(std::size(a), std::size(b));
        string use_me;
        if (std::size(a) > std::size(b)) {
            use_me = a;
        }
        else {
            use_me = b;
        }
                std::string result;
        bool add_next = false;
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        std::reverse(use_me.begin(), use_me.end());

        // std::cout << "memory check" << std::endl;
        // for (int i=shortest_bit_length; i<max_bit_length; i++) {
        //     std::cout << b[i];
        // }
        // std::cout << endl;

        // std::cout << "memory check" << std::endl;

        for (int i=0; i<shortest_bit_length; i++) {
            if (a[i] == '1' & b[i] == '1' & add_next) {
                if (add_next) {
                    result += '1';
                }
                else {
                    result += '0';
                }
                add_next = true;
            }
            else if (a[i] == '1' & b[i] == '1' & !add_next) {
                result += '0';
                add_next = true;
            }
            else if ((a[i] == '1' ^ b[i] == '1') & !add_next) {
                result += '1';
                add_next = false;
            }
            else if ((a[i] == '1' ^ b[i] == '1') & add_next) {
                result += '0';
                add_next = true;
            }
            else if ((a[i] == '0' & b[i] == '0') & add_next) {
                result += '1';
                add_next = false;
            }
            else if ((a[i] == '0' & b[i] == '0') & !add_next) {
                result += '0';
                add_next = false;
            }
            else {
            }
        }
        if (std::size(a) != std::size(b)) {
            for (int i=shortest_bit_length; i<max_bit_length; i++) {
                if (add_next & (use_me[i] == '1')) {
                    result += '0';
                    add_next = true;
                }
                else if (add_next & (use_me[i] == '0')){
                    result += '1';
                    add_next = false;
                }
                else if (!add_next & (use_me[i] == '1')) {
                    result += '1';
                    add_next = false;
                }
                else if (!add_next & (use_me[i] == '0')) {
                    result += '0';
                    add_next = false;
                }
            }
        }

        if (add_next) {
            result += '1';
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};
