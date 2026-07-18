#include <iostream>
#include <vector>
using namespace std;

/*
 * LC | 3963 |  Create Grid With Exactly One Path
 * Difficulty: Easy
 * Topic: Array, matirx
 * Date: June 20
 * Status: contest | solved
 * 
 * 
 * Approach: Logic
 * Time: O() | Space: O()
*/


class Solution {
public:
    // O(n)
    vector<string> createGrid1(int m, int n) {
        string grid(n,'#');
        string first(n,'.');
        vector<string> ans(m,grid);
        ans[0] = first;

        for(int i = 1; i < m; i++) {
            ans[i][n-1] = '.';
        }
        return ans;
    }

    // O(n^2)
    vector<string> createGrid(int m, int n) {
        vector<string>  ans(m , "");
        for(int i = 0; i < m; i++) {
            for(int j = 0; j<n; j++) {
                if(m > n) {
                    if(i < n) {
                        if(j == i || j == i+1) {
                            ans[i] += ".";
                        }
                        else {
                            ans[i] += "#";
                        }
                    }
                    else {
                        if(j == n-1) {
                            ans[i] += ".";
                        }
                        else {
                            ans[i] += "#";
                        }
                    }
                }
                else if(m < n) {
                    if(j < m) {
                        if(j == i || j == i+1) {
                        ans[i] += ".";
                        }
                        else {
                            ans[i] += "#";
                        }  
                    }
                    else {
                        if(i == m-1) {
                            ans[i] += ".";
                        }
                        else {
                            ans[i] += "#";
                        }
                    }
                    
                }
                else {
                    if(j == i || j == i+1) {
                        ans[i] += ".";
                    }
                    else {
                        ans[i] += "#";
                    }  
                }
            }
        }
        return ans;
    }
};

    int main() {
        Solution s1;
        int m,n;
        cout<<"enter rows (m) : ";
        cin>>m;
        cout<<"enter columns (n) : ";
        cin>>n;

        vector<string> ans = s1.createGrid(m,n);

        cout<<"\noutput\n\n";
        for(int i = 0; i< m; i++){
            cout<<ans[i]<<endl;
        }

        return 0;
    }