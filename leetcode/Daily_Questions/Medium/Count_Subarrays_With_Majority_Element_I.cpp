#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
 * LC | 3737 |  Count Subarrays With Majority Element I
 * Topic: Array
 * Date: June 27
 * Status: daily | struggling
 * 
 * 
 * Approach: 
 * Time: O() | Space: O()
*/


class Solution {
    public:
        int countMajoritySubarrays(vector<int>& nums, int target) {
            int ans = 0;
            
            for(int i = 0; i < nums.size(); i++) {
                int target_count = 0;
                
                vector<int> subarrays = {nums[i]};
                if(nums[i]==target) {
                     target_count++; ans++;
                }
                
                for(int j = i+1; j < nums.size(); j++) {
                    subarrays.push_back(nums[j]);
                    
                    if(nums[j]==target) target_count++;
                    
                    if(2*target_count > subarrays.size()) {
                        ans++; 
                    }
                }
            }
            return ans;
            
        }
    };
};