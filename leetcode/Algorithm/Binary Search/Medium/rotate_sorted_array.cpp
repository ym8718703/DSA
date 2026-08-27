#include <iostream>
#include <vector>
using namespace std;

/*
 * LC | 33 | Search in Rotated Sorted Array
 * Difficulty: Medium
 * Topic: BS
 * Date: May 24
 * Status: SOLVED
 * 
 * 
 * Approach: Modified binary search
 * Time: O(log n) | Space: O(1)
*/

int ans(vector<int>& nums,int target){
    int st = 0, end = nums.size()-1, mid;

    while(st <= end){
        mid = st + (end-st)/2;
        //left sorted
        if(nums[st] < nums[mid]){
            end = mid-1;
            if(target < nums[mid]){
                end = mid-1;
            }
            else if(target > nums[mid]){
                st = mid+1;
            }
            else{
                return mid;
            }
        }
        else{
            
        }
    }
}