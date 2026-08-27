#include <iostream>
#include <vector>
using namespace std;

/*
 * LC | 238 | Product of Array Except Self 
 * Difficulty: Medium 
 * Topic: Prfix sum
 * Date: June 20
 * Status: solved
 * 
 * Approach: Prefix sum
 * Time: O(n) | Space: O(1)
 * 
*/

class Solution {
public:
    vector<int> product(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n , 1);

        for(int i = 1; i < n; i++) {
            ans[i] = ans[i-1]*nums[i-1];
        }
        
        int suffix = 1;
        for(int i = n-2; i >= 0; i--){
            suffix *= nums[i+1];
            ans[i] = ans[i]*suffix;
        }
        return ans;
    }
};

int main() {
    Solution S1;
    int i = 0;
    vector<int> array;
    int x;
    while(cin >> x) {
        array.push_back(x);
        i++;
    }

    vector<int> ans = S1.product(array);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}