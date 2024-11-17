#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;



// Time Complexity is O(log(C) * R);
int rowWithMax1s(vector<vector<int>> &arr){
    int row = arr.size();
    int col = arr[0].size();
    int j = col-1;
    int max_row =-1;
    int max_one = 0;

    for(int i =0;i<row;i++){
        // go for every row
        while(j>=0 && arr[i][j] == 1){
            j--;
        }

        // check every time j is now how much
        int count = col - 1 - j;
        if (count > max_one){
            max_one = count;
            max_row = i;
        }
    }
    return max_row;

}
int main(){
    vector<vector<int>> arr = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
    int ans = rowWithMax1s(arr);
    cout<<"ans is "<<ans<<endl;

}