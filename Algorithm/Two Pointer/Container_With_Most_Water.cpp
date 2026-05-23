#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int brute(vector<int> &b){
    int length, height;
    int st = 0;
    int end = b.size();
    int vol = INT_MIN;
    while(st < end){
        for(int i = st+1; i < end; i++){
            length = i - st;
            height = min(b[i], b[st]);
            vol = max(vol, height*length);
        }
        st++;
    }
    return vol;
}

int container(vector<int> &b){
    int length, height;
    int st = 0;
    int end = b.size();
    int vol = INT_MIN;
    while(st < end){
        length = end - st;
        height = min(b[end], b[st]);
        vol = max(vol,length*height);

        if(b[st] < b[end]){
            st++;
        }else{
            end--;
        }
    }
    return vol;
}

int main(){
    vector<int> arry = {1,8,6,2,5,4,8,3,7};
    int ans = container(arry);
    cout<<ans;

    return 0 ;
}