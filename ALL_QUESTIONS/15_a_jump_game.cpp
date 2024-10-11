#include<iostream>
#include<vector>
using namespace std;


// jump game ......



bool check_reachable(vector<int> arr,int size){
    int max_index=0;
    for(int i =0;i<size;i++){

        if(i>max_index){
            return false;
        }

        if (i+arr[i] > max_index){
            max_index = i+arr[i];
        }
    }
    return true;
}
void jump_game(vector<int> arr , int start_index,int size,int &min_dist,int dist){
    if (start_index >= size -1){
        if (min_dist>dist){
            min_dist = dist;
            
        }
        return;
    }

    for(int i =1;i<=arr[start_index];i++){
        jump_game(arr,start_index+i,size, min_dist,dist+1);

    }

}


int game(vector<int> arr){
    int size = arr.size();
    if(!check_reachable(arr,size)){
        return -1;
    }

    int min_dist = INT_MAX;
    int dist =0;
    int start_index = 0;
    jump_game(arr,start_index,size,min_dist,dist);
    return min_dist;

}
int main(){
    // 2,3,1,3,1,1,0,2
    vector<int> arr = {2,3,1,1,4};
    int ans = game(arr);
    cout<<"minimum jump taken is "<<ans<<endl;
}