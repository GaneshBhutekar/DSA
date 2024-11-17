#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;



// Time Complexity is O(log(C) * R);
int rowWithMax1s(vector<vector<int>> &arr){
    int row = arr.size();
    int col = arr[0].size();

    int maximum=0;
    int max_row = -1;
    int count=0;
    // now traverse 
    for(int i =0;i<row;i++){
        // now do BS in it
        int start =0;
        int end = col-1;
        int mid = start + (end-start)/2;
        count = -1;
        while(start<=end){
            if(arr[i][mid] == 1){
                // agar ye 1 hain iska matlb hame left main jana chahiye
                count = mid;
                end = mid-1;
            }
            else{
                // aggar nahi hain iska matlb right
                start = mid+1;
            }
            mid = start+(end-start)/2;
        }
        if (count != -1 && col-count > maximum){
            max_row = i;
            maximum = col-count;
        }
        
    }
    
    if (max_row == -1){
        return -1;
    }
    return max_row;
}
int main(){
    vector<vector<int>> arr = {
        {0,0,1,1,1,1},
        {0,0,0,0,0,0},
        {0,1,1,1,1,1},
        {0,0,0,1,1,1}
    };
    int ans = rowWithMax1s(arr);
    cout<<"ans is "<<ans<<endl;

}