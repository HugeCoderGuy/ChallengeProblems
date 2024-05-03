/*
  You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
  */

class Solution {
public:
    int climbStairs(int n) {
        int ans = 0;
        int r = 0;
        while (r <= n) {
            std::cout << n << " - " << r << std::endl;
            ans += choose(n, r);
            n--;
            r++;
        }
        return ans;
    }
    unsigned long long int factorial(int x) {
        unsigned long long int ans = 1;
        while (x > 0) {
            ans = ans * x;
            x--;
        }
        return ans;
    }
    int choose(int n, int r) {
        return factorial(n) / (factorial(n-r) * factorial(r));
    }
};
