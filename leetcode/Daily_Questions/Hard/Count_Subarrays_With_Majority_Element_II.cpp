#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
 * LC | 3739 |  Count Subarrays With Majority Element II
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
        long long countMajoritySubarrays(vector<int>& nums, int target) {
            int n = nums.size();
    
            bool found = false;
            vector<int> pref(n + 1);
            for (int i = 0; i < n; i++) {
                if (nums[i] == target) found = true;
                pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
            }
    
            if (!found) return 0;
    
            vector<int> vals = pref;
            sort(vals.begin(), vals.end());
            vals.erase(unique(vals.begin(), vals.end()), vals.end());
    
            int m = vals.size();
            vector<int> bit(m + 1);
    
            auto upd = [&](int i) {
                for (; i <= m; i += i & -i)
                    bit[i]++;
            };
    
            auto qry = [&](int i) {
                int res = 0;
                for (; i > 0; i -= i & -i)
                    res += bit[i];
                return res;
            };
    
            long long ans = 0;
    
            for (int x : pref) {
                int id = lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
                ans += qry(id - 1);
                upd(id);
            }
    
            return ans;
        }
    };