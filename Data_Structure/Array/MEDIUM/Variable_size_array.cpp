#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int st = 0;w
    int end = nums.size()-1;
    int mid;
    while(st < end) {
        mid = st + (end+st)/2;

        if(nums[mid] == target) {
            return mid;
        }
    }
    if(nums[mid-1] < target && nums[mid+1] > target) return mid++;
    return mid;
}

int main() {
    vector<int> nums = {1,3,5,7};
    int target;
    cin >> target;
    cout << search(nums,target);

    return 0;
}