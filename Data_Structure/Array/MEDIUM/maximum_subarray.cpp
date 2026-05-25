#include <iostream>
#include <vector>
using namespace std;

/*
 * LC | 53 | Maximum Subarray
 * Difficulty: Medium
 * Topic: DP, Divide & Conquer
 * Date: Apr 14
 * Status: SOLVED
 *
 * 
 * Approach : Kadane's Algorithm
 * Time: O(n) | Space: O(1) 
 */

int maxSubarray(vector<int>& arr) {
    int maxSum = arr[0];        
    int currentSum = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        currentSum = max(arr[i], currentSum + arr[i]); 
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main(){
    vector<int> array = {-4,-5,-6,5,7,8};

    cout<<maxSubarray(array);    
    return 0;
}