#include<iostream>
#include<vector>
using namespace std;

int rotateDelete(vector<int> &arr){
    int elements = arr.size();


    
    if (elements == 1){
        return arr[0];
    }
    // int end= elements-1;
    int k =1;
    int point = elements -1;
    while(elements > k){
        // rotate the first one
        // int i = point;
        int j = point-1;
        int value = arr[point];
        while(j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = value;

        // now delete the kth element
        j = 1;
        int i = point;
        while(j<k){
            j++;
            i--;
        }
        arr[i] = -1;
        k++;
        elements--;

        // now shift the i to thhe right most
        for(int p =i;p<point;p++){
            arr[p] = arr[p+1];
        }
        point--;
    }
    return arr[0];
}

int main(){
    vector<int> arr = {1,2};
    int ans = rotateDelete(arr);
    cout<<ans<<endl;

}