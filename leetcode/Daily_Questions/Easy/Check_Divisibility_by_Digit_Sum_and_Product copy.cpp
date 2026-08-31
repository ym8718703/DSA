#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

/*
 * LC | 3622 | Check Divisibility by Digit Sum and Product
 * Topic: Array
 * Date: Aug 22
 * Status: daily | solved
 * 
 * 
 * Approach: hahahaha
 * Time: O(n) | Space: O(1)
*/

class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum = 0;
        long long product = 1;
        
        int given = n;
        
        while(n > 0) {
            sum += n%10;
            product *= n%10;
            
            n /= 10;
        }
        
        return given % (sum+product) == 0 ? true : false;
    }
};