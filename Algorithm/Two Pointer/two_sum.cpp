#include <iostream>
#include <vector>
using namespace std;


int brute(){
    int target = 9;
    vector<int> vec = {1,3,4,5,6,7,8,9};
    for(int i = 0 ; i < vec.size() ; i++){
        for(int j = i+1 ; j < vec.size() ; j++){
            if(vec[i] + vec[j] == target){
                cout<<"Indexes: "<<i <<" and "<<j;
                cout<<endl; 
            }
        }
    }
    return 0 ;
}

vector<int> pairsum(vector<int> a ,int n, int target){
    vector<int> ans;
    int i = 0 ; int j = n-1;
    
    while(i < j){
        int sum = a[i]+a[j];
        if(sum < target){
            i++;
        }else if(sum > target){
            j--;
        }else{
            ans.push_back(i);
            ans.push_back(j);
            return ans;

        }
    }
}

int main(){
    int target = 36;
    vector<int> nums = {2,3,5,6,7,8,9,12,14,16,30};
    int n = nums.size();

    vector<int> ans = pairsum(nums , n , target);
    cout<<ans[0]<<','<<ans[1];

    return 0;
}
