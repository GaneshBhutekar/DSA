#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



long long findMinDiff(vector<long long> a , long long n,long long m){

    if (m > n ){
        return -1;
    }
    // sort the array
    sort(a.begin(),a.end());

    long long minValue = INT_MAX;


    int i=0;
    int stop = n-m;
    while(i<=stop){
        minValue = min(a[m+i-1] - a[i],minValue);
        i++;

    }
    return minValue;
    

}

int main(){
    vector<long long> a = {1,2,3,4};
    long long n=a.size();
    long long m = 4;
    long long ans = findMinDiff(a,n,m);
    cout<<"minimum diff will be "<<ans<<endl;
}