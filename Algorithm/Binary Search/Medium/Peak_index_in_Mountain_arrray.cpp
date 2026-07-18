#include <iostream>
#include <vector>
using namespace std;

/*
 * LC | 852 | Peak Index in Mountain array
 * Difficulty: Medium
 * Topic: BS
 * Date: June 18
 * Status: SOLVED
 * 
 * 
 * Approach: Modified binary search
 * Time: O(log n) | Space: O(1)
*/

class Solution {
    public:
        int peakIndexInMountainArray(vector<int>& arr) {
            int st = 0;
            int end = arr.size()-1;
    
            while(st < end) {
                int mid = st + (end-st)/2;
                if(arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1]) {
                    st = mid++;
                }
                else if(arr[mid-1]>arr[mid] && arr[mid]>arr[mid+1]) {
                    end = mid--;
                }
                else {
                    return mid;
                }
            }
                return -1;
            
        }
    };