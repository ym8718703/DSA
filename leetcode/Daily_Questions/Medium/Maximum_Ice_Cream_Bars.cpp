#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
 * LC | 1833 |  Maximum Ice Cream Bars
 * Topic: Array
 * Date: June 23
 * Status: daily | struggling
 * 
 * 
 * Approach: 
 * Time: O() | Space: O()
*/


class Solution {
    public:
        int maxIceCream(vector<int>& costs, int coins) {
            sort(costs.begin(),costs.end());
            int icecream = 0;
            int index = 0;
            
            while(coins > 0 && index < costs.size()) {
                if(costs[index] <= coins) {
                    ++icecream;
                    coins -= costs[index];
                }
                else {
                    return icecream;
                }
                ++index;
            }
            return icecream;
        }
    };