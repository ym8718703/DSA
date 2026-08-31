#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
 * LC | 33 |  Search in Rotated Sorted Array
 * Topic: Array
 * Date: May 24
 * Status: daily | solved
 * 
 * 
 * Approach: Math
 * Time: O(1) | Space: O(1)
*/


class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int st = 0, end = nums.size() -1;
    
            while(st <= end){
                int mid = st + (end-st)/2;
                if(nums[mid] == target){
                    return mid;
                }
                if(nums[st] <= nums[mid]){
                    if(nums[st] <= target && target < nums[mid]){
                        end = mid-1;
                    }else{
                        st = mid+1;
                    }
                }else{
                    if(nums[mid] < target && target <= nums[end]){
                        st = mid+1;
                    }else{
                        end = mid-1;
                    }
                }
            }
            return -1;
            
        }
    };