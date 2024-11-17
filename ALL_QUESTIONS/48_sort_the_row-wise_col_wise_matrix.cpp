#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


vector<vector<int>> sortedMatrix1(int N,vector<vector<int>> Mat){
    vector<int> ans;
    for(int i =0;i<N;i++){
        for(int j=0;j<N;j++){
               ans.push_back(Mat[i][j]);
        }
    }
    sort(ans.begin(),ans.end());
    // return it in 2D matrix
    vector<vector<int>> ans_mat(N,vector<int>(N));
    int iter = 0;
    for(int i =0;i<N;i++){
        for(int j=0;j<N;j++){
            ans_mat[i][j] = ans[iter];
            iter++;
        }
    }
    return ans_mat;
}


vector<vector<int>> sortedMatrix(int N,vector<vector<int>> Mat){
    // take a size 
    vector<int> row_first(N,0);
    // contains first index of all column
    vector<vector<int>> ans(N,vector<int>(N));

    vector<int> store;
    int element=0;
    while(element < N*N){
        int pos = 0;
        int small = INT_MAX;
        for(int i = 0;i<N;i++){
            // check for the smallest
            if (row_first[i] < N && Mat[i][row_first[i]] < small){
                small = Mat[i][row_first[i]];
                // update the row_first
                pos = i;
            }
            // now push this small

        }
        store.push_back(small);
        row_first[pos] ++;
        element++;
    }
    
    //we have store value
    int p =0;
    for(int i =0;i<N;i++ ){
        for(int j =0;j<N;j++){
            ans[i][j] = store[p];
            p++;
        }
    }

    return ans;
    
}


vector<vector<int>> sortedMatrix(int N,vector<vector<int>> Mat){
    priority_queue<int,vector<int>,greater<int>> pq;
    // traverse evry row evrry tie
}
int main(){
    vector<vector<int>> Mat = {
        {10,20,30,40},
        {15,25,35,45},
        {27,29,37,48},
        {32,33,39,50}
    };

    int N = Mat.size();
    vector<vector<int>> ans = sortedMatrix(N,Mat);
    for(auto i : ans){
        for(int j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}