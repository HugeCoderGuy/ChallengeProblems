/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
*/

#include <string.h>

int strStr(char* haystack, char* needle) {
    int maxlen = strlen(haystack);
    bool found = false;
    int iter = 0;
    while (!found && iter < maxlen) {
        printf("Iter is %d\n", iter);
        int subIter = 0;
        if (haystack[iter] == needle[subIter]) {
            while ((subIter<strlen(needle)) && (subIter+iter < maxlen)) {
                printf("Comparing %c and %c\n", haystack[iter + subIter], needle[subIter]);
                if (haystack[iter + subIter] != needle[subIter]) {
                    break;
                }
                else if (subIter == strlen(needle) - 1) {
                    return iter;
                }
                subIter += 1;
            }
        }
        iter += 1;
    }
    return -1;
}
