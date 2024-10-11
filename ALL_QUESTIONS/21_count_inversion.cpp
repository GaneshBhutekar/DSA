#include<iostream>
#include<vector>
#include<map>

using namespace std;

// merge sort do what:
// sort in nlogn
// sort using recurssion
// merge sort is stable matains the relative order.

void sortit(vector<long long> &arr,long long int &cnt,int start , int mid , int end){
    vector<long long> demo;
    int i = start;
    int j = mid+1;
    while(i<=mid && j<= end) {
        if (arr[i] <= arr[j]){
            demo.push_back(arr[i]);
            i++;
        }
        else{
            cnt += mid - i +1;
            demo.push_back(arr[j]);
            j++;
        }
    }

    // push the remaining one 
    while(i<= mid){
        demo.push_back(arr[i]);
        i++;
    }
    while(j<= end){
        demo.push_back(arr[j]);
        j++;
    }

    int x = start;
    // now demo has alll element in sorted way for this portion now copy this in orignal portion
    for(int i : demo){
        arr[x] = i;
        x++;
    }

}


void mergeSort(vector<long long> &arr,long long int  &cnt,int start,int end){
    if (start >= end){
        return;
    }

    // find the mid
    int mid = start + (end-start)/2;
    // go for the left
    mergeSort(arr,cnt,start,mid);

    // for right 
    mergeSort(arr,cnt,mid+1,end);

    // now sort this two partitions
    sortit(arr,cnt,start,mid,end);

}

long long int inversionCount(vector<long long> arr){
    int pairs =0;
    int start = 0;
    int end = arr.size() -1;
    long long int cnt=0;
    mergeSort(arr,cnt,start,end);
    return cnt;
}
int main(){
    vector<long long> arr = {5,4,3,2,1} ;
    long long int ans = inversionCount(arr);
    cout<<"Answer is "<<ans<<endl;

}