#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
 * LC | 3345 | Smallest Divisible Digit Product I
 * Topic: Array
 * Date: Aug 06
 * Status: daily | solved
 * 
 * 
 * Approach: brute force
 * Time: O() | Space: O(1)
*/

class Solution {
    public:
        int smallestNumber(int n, int t) {
            int product;
    
            while(n < 101) {
                if(n%10 == 0) return n;
                else if(n < 10) product = n;
                else product = (n/10)*(n%10);
    
                if(product % t == 0) return n;
                n++;
            }
    
            return n;
    
        }
    };