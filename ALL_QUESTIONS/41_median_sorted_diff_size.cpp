#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

double median(vector<int> arr1,vector<int> arr2){
    // get the size
    int n1 = arr1.size();
    int n2 = arr2.size();
    // arr1 should be smaller
    if (n1 > n2){
        return median(arr2,arr1);
    }

    int n = n1+n2;
    // determine low and high
    int low = 0;
    int high = n1;
    // how much should be in left
    int left = (n+1)/2;

    while(low <= high){
        //here middle would be 
        int mid1 =  low + (high-low)/2; // how much element of smaller one is at left
        int mid2= left - mid1; // how much element of bigger one is at right
        
        // now check for r1,r2,l1,l2
        int l1 = INT_MIN,l2 = INT_MIN;
        int r1 = INT_MAX,r2 = INT_MAX;
        if (mid1-1 >= 0) l1 = arr1[mid1-1]; // checm for left side ones
        if (mid2-1 >= 0) l2 = arr2[mid2-1];
        if (mid1 <n1) r1 = arr1[mid1];
        if (mid1 < n2) r2 = arr2[mid2];

        // check that they all are correct or not
        if (l1 <= r2 && l2 <=r1){
            // n is even or oddd
            if (n%2 == 1){
                return max(l1,l2);
            }
            else{
                return (max(l1,l2) + min(r1,r2))/2.0;
            }
        }

        else if(l1 > r2){
            // there are all of the right smaller greater so crease the high
            high = mid1-1;
        }
        else{
            low = mid1+1;
        }
    }

    return 0;
}

int main(){
    vector<int> arr1 = {1,2,3,4,5};
    vector<int> arr2 = {6,7,8};
    double ans = median(arr1,arr2);
    cout<<"ans is "<<ans<<endl;
}