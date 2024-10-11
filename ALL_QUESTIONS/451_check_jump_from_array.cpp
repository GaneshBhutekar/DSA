#include<iostream>
#include<vector>
using namespace std;


bool check_jump(vector<int> arr, int size,int &cnt){
    int maxindex=0;
    for(int i =0;i<size ;i++){
        if (maxindex < i){
            return false;
        }

        // check which is maximum update it.
        else{
            if (maxindex < arr[i]+i){
                maxindex = arr[i]+i;
                cnt+=1;
            }
        }

        if (maxindex >= size){
            return true;
        }
    }

    return true;
}
int main(){
    vector<int> arr= {1,2,4,1,1,0,2,5};
    // check that it is possible or not to jump over this array 
    int mysize = arr.size();
    int cnt =0
    if(check_jump(arr,mysize,cnt)){
        cout<<"yes it is possible to jump till the last "<<endl;
        cout<<"total count for this is "<<cnt<<endl;
    }
    else{
        cout<<"no we can't able to jump over this array "<<endl;
    }
}