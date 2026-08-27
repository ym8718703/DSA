#include <iostream>
#include <vector>
using namespace std;

/*
 * LC | 540 | Single Element in a Sorted Arrayy
 * Difficulty: Medium
 * Topic: BInary Search
 * Date: June 20
 * Status: SOLVED
 * 
 * 
 * Approach:  binary search
 * Time: O(log n) | Space: O(1)
*/


// bitwise manupulation

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            ans = ans^nums[i];
        }
        return ans;
    }
};



class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int st = 0;
        int end = nums.size()-1;

        // edge case 1 : single size array
        if(end == 1) {
            return nums[0];
        }
    

        while(st <= end) {
            int mid = st + (end-st)/2;
            
            // edge case 2 : when mid is at start
            if(mid == 0) {   
                return nums[mid];
            }

            // edge case 3 : when mid is at end
            if(mid == nums.size()-1) {
                return nums[mid];
            }

            
            if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]) {
                return nums[mid];
            }
            else if(nums[mid] == nums[mid-1]) {
                if(mid%2 == 0) {
                    end = mid-1;
                }
                else {
                    st = mid+1;
                }
            }
            else {
                if(mid%2 == 0) {
                    st = mid+1;
                }
                else {
                    end = mid-1;
                }
            }
        }
        return -1;
    }
};