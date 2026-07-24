#include <iostream>
using namespace std;
#include <vector>

bool isvalid(vector<int>& a,int possible_ans, int m) {
    int student = 1;
    int page_count = 0;
    int n = a.size();
    for(int i = 0; i < n; i++) {
        if(page_count + a[i] <= possible_ans) {
            page_count += a[i];
        } else {
            page_count = a[i];
            student++;
        }
    }

    return student <= m ? true: false; 
};
int minmaxallocate(vector<int> &nums, int m) {
    
    int end = 0;
    int n = nums.size();

    if(n < m) return -1;
    for(int i = 0; i < n; i++) {
        end += nums[i];
    }

    int st = 0;
    int ans = -1;

    while(st <= end) {
        int mid = st + (end-st)/2;
        if(isvalid(nums,mid,m)) {
            end = mid-1;
            ans = mid;
        } else {
            st = mid+1;
        }
    }
    return ans;
}


int main () {
    vector<int> books;
    int students;
    cin >> students;
 
    int x;
    while(cin >> x) {
        books.push_back(x);
    }


    cout << minmaxallocate(books,students);
    return 0;
}