#include<iostream>
#include<vector>
using namespace std;



int nextMaximum(vector<int> arr,int n,int i){

    while(i<n){
        if (i+1 >= n){
            return i;
        }
        if (arr[i] > arr[i+1]){
            return i;
        }
        i++;
    }

    return i;
}

int range(vector<int> arr,vector<pair<int,int>> &buckets,int n,int i){
    int max = -1;

    int start = i;
    // just traverse and whenever you get bigger value than previous then update max
    int prev = i;
    i++;
    while(i<n){
        if (arr[i] > arr[prev]){
            // update the max 
            if (arr[i] >= arr[start]){
                buckets.push_back({start,i});
                return i;
            }
            if ( max == -1 || arr[max] <= arr[i]){
            max = i;
            }
            
        }

        prev = i;
        i++;
    }

    if (max != -1){
        buckets.push_back({start,max});
    }
    return max;
}


long long traps(vector<int> arr,vector<pair<int,int>> buckets){
    long long output = 0;
    for(auto i: buckets){
        // raange
        int start = i.first+1;
        int end = i.second-1;
        int min = (arr[i.first]<arr[i.second]) ? arr[i.first] : arr[i.second];
        for(int j = start ;j<=end;j++){
            if (arr[j] > min){
                arr[j] = min;
            }
            // cout<<min-arr[j]<<endl;
            output+=min - arr[j];
        }
    }

    return output;
}

// THIS CODE HAVE TIME  COMPLEXITY O(N) WHY CHAT GPT IS SAYING O(N2) IDK.
long long trappingWater(vector<int> &arr){
    // code here
    int n = arr.size();
    vector<pair<int,int>> buckets;

    int i =0;
    while(i<n){


        // now here first find maximum adjecent bar if it is there
        i = nextMaximum(arr,n,i);

        // find the next maximum bar and add the range in the vector/data structure

        int last = range(arr,buckets,n,i);
        if (last == -1){
            break;
        }
        i = last;
    }



    // now we have the pairs in our hands can we find the traps with the help of this ranges
    long long output = traps(arr,buckets);
    return output;
}
int main(){
    vector<int> arr = {3,4,3,2,5,2,3};
    // 3,4,3,2,5,2,3
    // 4,1,3,1,2
    // 4,3,6,6,4,4,2,3,1,0,2
    // find the trapped water
    long long ans = trappingWater(arr);
    cout<<"total amount of water stored "<<ans<<endl;
}