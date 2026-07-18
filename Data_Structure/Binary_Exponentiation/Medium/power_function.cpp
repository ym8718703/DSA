#include <iostream>
using namespace std;

/*
 * LC | 50 | Pow(x,n)  
 * Difficulty: Medium
 * Topic: Math, Recursion
 * Date: 
 * Status: 
 * 
 * 
 * Approach: Modified binary search
 * Time: O() | Space: O()
*/

class Solution {
    public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long N = n;   // convert to wider type first
        if(N < 0){
            x = 1.0/x;
            N = -N;        // now safe: -(-2147483648) = 2147483648, fits easily in long long
        }
        
        while(N > 0){
            if(N%2 == 1){
                ans *= x;
            }
            x *= x;
            N /= 2;
        }
        return ans;
    }
    };