/*
 * LC #33 - 
 * Difficulty: 
 * Topic: 
 * Date: 
 * 
 * Approach: Modified binary search
 * Time: O() | Space: O()
 * 
 * Status: 
 */

#include <iostream>
#include <vector>
using namespace std;

int my_two(){
    int nums[10] = {1,2,3,4,5,6,7,-54,-5,10};
    int st = 0;
    int end = sizeof(nums)/sizeof(nums[0]);
    int sum = 0 ;
    int maxnum = INT_MIN;
    for(st ; st < end ; st++){
        sum = 0;
        for(int j = st ; j < end ; j++){
            sum += nums[j];
            maxnum = max(sum , maxnum);
        }
    }
    return  maxnum;

}

int two_pointer(){
    int array[10] = {3,-4,5,4,-1,7,-8};
    int m = INT16_MIN;
    int st = 0;
    int end = sizeof(array)/sizeof(array[0]);

    while(st <= end){
    int sum = 0;
        for(int i = st ; i < end ; i++){
            sum  = sum + array[i];
            m = max(sum, m);
        }
        st++;
    }
    cout<<"Given Array:\n";
    for(int i = 0 ; i < end ; i++){
        cout<<array[i]<<" ";
    }
    return x;
}

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
    int ans = maxSubarray(array);

    cout<<ans;
    
    return 0;
}