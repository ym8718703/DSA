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
 * Approach : two pointer
 * Time: O(n2) | Space: O(1)
 */


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

int apancollege(vector<int>& b){
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
    return m;
}


int main(){
    vector<int> array = {-4,-5,-6,5,7,8};
    int ans = apancollege(array);

    cout<<ans;
    
    return 0;
}