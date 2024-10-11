#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){

    // vector<int> arr={90 ,64 ,-76, 65, 1 ,93 ,-99 ,-76 ,-87 ,88 ,63 ,-79 ,85 ,-15 ,4 ,-32, 69 ,-22};

    // Brute Force..........................................
    // int Mysize=arr.size();
    // int ans=arr[0];

    // for(int i=0;i<Mysize;i++){
    //     int temp = 0;
    //     for(int j=i;j<Mysize;j++){
    //         temp+=arr[j];
    //         if (temp > ans){
    //             ans = temp;
    //         }
    //     }

    // }

    // cout<<"maximum value sub array is "<<ans<<endl;
    // // arr={90 ,64 ,-76, 65, 1 ,93 ,-99 ,-76 ,-87 ,88 ,63 ,-79 ,85 ,-15 ,4 ,-32, 69 ,-22};


    // // wrong codee...........................
    // int max_so_far=arr[0];
    // int max_ending_here=0;
    
    // for(int i = 0; i<Mysize;i++){

    //     if (max_ending_here+arr[i]>=0){
    //         max_ending_here += arr[i];
    //         cout<<"max_ending "<<max_ending_here<<endl;
    //         // cout<<"max so far "<<max_so_far<<endl;
    //         if (max_ending_here>=max_so_far){
    //             max_so_far=max_ending_here;
    //         }
            
    //     }
    //     else{
    //         max_ending_here = 0;
    //     }
    // }



    // cout<<"WORNG maximum possible sum of sub array is (by kedane algorithm) "<<max_so_far<<endl;
    vector<int> arr={-6,-5,-70,-4,-1};
    int max_so_far=arr[0];
    int max_ending_here=0;
    int Mysize=arr.size();
    

    for(int i =0;i<Mysize;i++){
        max_ending_here+=arr[i];

        if (max_ending_here > max_so_far){
            max_so_far = max_ending_here;
        }

        if (max_ending_here < 0){
            max_ending_here = 0;
        }
    }

    cout<<"using Kedane Algorithm "<<max_so_far<<endl;



}