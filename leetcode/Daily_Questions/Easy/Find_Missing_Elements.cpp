#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
 * LC | 3731 | Find Missing Elements
 * Topic: Array
 * Date: Aug 04
 * Status: daily | solved
 * 
 * 
 * Approach: brute force
 * Time: O(n) | Space: O(n)
*/

class Solution {
    public:
        vector<int> findMissingElements(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            vector<int> ans;
            int current;
            
            for(int i = 0; i < nums.size()-1; i++) {
                current = nums[i];
                while(current+1 < nums[i+1]) {
                    ans.push_back(current+1);
                    current += 1;
                }
            }
            
            return ans;
        }
    };