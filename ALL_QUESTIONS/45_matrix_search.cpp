#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>> & matrix,int target){
    // find the row and the col
    int row = matrix.size();
    int col = matrix[0].size();

    int n = row * col;
    int start = 0;
    int end = n-1;
    int mid = start+(end-start)/2;
    while(start<=end){  
        // the the row and the col
        int R = mid/col;
        int C = mid%col;

        if (matrix[R][C] == target)   {
            return true;
        }
        else if(matrix[R][C] < target){
            start = mid+1;
        }
        else{
            end = mid-1;
        }

        mid = start+(end-start)/2;
    }
    return false;
}
int main(){
    vector<vector<int>> matrix = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60},
        {68,69,80,90}
    };
    if (searchMatrix(matrix,111)){
        cout<<"present"<<endl;
    }
    else{
        cout<<"not present"<<endl;
    }

}