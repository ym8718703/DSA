#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

/*
 * LC | 2996 |  Smallest Missing Integer Greater Than Sequential Prefix Sum
 * Topic: Array
 * Date: Aug 13
 * Status: daily | solved
 * 
 * 
 * Approach: hahahaha
 * Time: O(n) | Space: O(1)
*/


class Solution {
    public:
        int missingInteger(vector<int>& nums) {
            int n=nums.size();
            unordered_set<int>st(nums.begin(),nums.end());
            int j=1;
            int curr=nums[0];
            while(j<n && nums[j]==nums[j-1]+1)
            {
                curr+=nums[j];
                j++;
            }    
            while(st.find(curr)!=st.end()) curr++;
            int ans=curr;
            
            return ans;
        }
    };