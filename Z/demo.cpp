#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {1,2,9,0,7};

    int maximum = nums[0];
    int minimum = nums[0];
    int max_it = 0;
    int min_it = 0;

    for(int i = 1; i < nums.size(); i++) {

        if(maximum < nums[i]) {
            maximum = nums[i];
            max_it = i;
        }
        else if(minimum > nums[i]) {
            minimum = nums[i];
            min_it = i;
        }
    }

    cout << "max_it = " << max_it << " min_it = " << min_it;
    return 0;

}