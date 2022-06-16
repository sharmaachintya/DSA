#include<iostream>
#include<vector>
#include<stack>
using namespace std;
    
int max(int a,int b) {
        return a>b ? a: b;
    }
    int max_histgram_area(int *arr,int n) {
        int ans=0;
        stack<int>s;
        int tp,max_area_with_tp;
        int i=0;
        while(i<n) {
            if(s.empty() || arr[s.top()]<=arr[i]) {
                s.push(i++);
            } else {
                tp=s.top(); 
                s.pop();
                max_area_with_tp = arr[tp] * (s.empty() ? i : i-s.top()-1);
                ans= max(ans,max_area_with_tp);
            }
        }
        
        while(s.empty() == false) {
            tp=s.top(); 
            s.pop();
            max_area_with_tp = arr[tp] * (s.empty() ? i : i-s.top()-1);
            ans= max(ans,max_area_with_tp);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        long long int ans=0;
        int arr[201]= {0};
        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[0].size();j++) {
                if(matrix[i][j] == '0') {
                    arr[j]=0;
                }
                else {
                    arr[j]++;
                }
            }
            int tmp = max_histgram_area(arr, matrix[0].size());
            if(tmp>ans) ans=tmp;
        }
        return ans;
    }

int main()
{
     vector<vector<char>> arr = {{0, 1, 1, 0},
                                {1, 1, 1, 1},
                                {1, 1, 1, 1},
                                {1, 1, 0, 0}};
    
    int ans = maximalRectangle(arr);
    cout<<ans;
}