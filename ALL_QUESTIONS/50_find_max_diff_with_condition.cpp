#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

/*
        DESCRIPTION:
        Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b) over all choices of indexes such that both c > a and d > b.
*/

int findMaxValue1(vector<vector<int>> &mat,int N){ // Time complexity O(N4)
    // write the code
    // turn it into the vector and the next biggest value
    map<int,pair<int,int>,greater<int>> mp;
    for(int i =0;i<N;i++){
        for(int j =0;j<N;j++){
            // now add row,col and value in map
            mp[mat[i][j]] = {i,j};
        }
    }
    // now travserse again in matrix and get the biggest value with row and col greater
    int diff = INT_MIN;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            // check every element in sorted dict 
            int element = mat[i][j];
            for(auto k : mp){
                if(k.second.first > i && k.second.second > j){
                    diff = max(diff,k.first - element);
                }
            }
        }
    }
    if (diff == INT_MIN){
        return 0;
    }
    return diff;

    
}

void print2D(vector<vector<int>> arr){
    for(auto i : arr){
        for(int j :i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int findMaxValue(vector<vector<int>> &mat,int N){
    // This is optimized approach 
    // here g diagonally and get maximum every time example
    vector<vector<int>> maxElement(N,vector<int>(N));
    for(int i = N-1;i>=0;i--){
        for(int j = N-1;j>=0;j--){
            // evrry time check his right and down to get the maximum value
            int right = INT_MIN;
            int down = INT_MIN;
            // now check that they are not out of bond
            if (j+1 <N){
                // it means that there is no rightexist
                right = maxElement[i][j+1];
            }
            if (i+1 < N){
                // no downwords
                down = maxElement[i+1][j];
            }
            // get the max
            maxElement[i][j] = max(mat[i][j],max(right,down));

        }
    }
    // now we have every point maximum from the right so, we can get the maximum according to the condition
    int max_diff = INT_MIN;
    for(int i =0;i<N;i++){
        for(int j = 0;j<N;j++){
            // get the max diff every time
            if (i+1 < N && j+1 < N){
                // check who is larger
                max_diff = max(maxElement[i+1][j+1] - mat[i][j],max_diff);
            }
        }
    }
    // now return the max_diff
    return max_diff;
}
int main(){
    vector<vector<int>>mat {
        // {1,2,-1,-4,-20},
        // {-8,-3,4,2,1},
        // {3,8,6,1,3},
        // {-4,-1,1,7,-6},
        // {0,-4,10,-5,1}
        // {6,3,4},
        // {2,4,2},
        // {1,8,3}
        {1,2,3},
        {-2,5,4},
        {-3,-2,-1}
    };
    int N = mat.size();
    // answer aho
    int ans = findMaxValue(mat,N);
    cout<<ans<<endl;
}