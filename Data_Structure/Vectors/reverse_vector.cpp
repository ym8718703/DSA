#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {1,2,3};
    nums.push_back(6);
    nums.push_back(7);

    int st = 0;
    int end = nums.capacity()-1;

    while(st < end){
        swap(nums[st],nums[end]);
        st++;
        end--;
    }
    for(int val : nums){
        cout<<val<<" ";
    }
    cout<<"\nCapacity of vector: "<<nums.capacity();
    return 0;
    
}