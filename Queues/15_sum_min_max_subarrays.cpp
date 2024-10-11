
// approach 1 : Not Optimized one.

// #include<iostream>
// #include<vector>
// using namespace std;

// void print(vector<int> arr,int start,int last){
//     for(int i = start; i<=last;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }

// void window_min_max(vector<int> arr, vector<int> &result,int start,int last){
//     int min = INT_MAX;
//     int max = INT_MIN;
//     for(int i = start;i<=last;i++){
//         if (arr[i]>max){
//             max = arr[i];
//         }
//         if (arr[i]<min){
//             min = arr[i];
//         }

//     }

//     result.push_back(min+max);
    
// }

// vector<int> arr_min_max(vector<int> arr,int k){  // brute force ...
//     int mysize = arr.size();
//     // startting of window
//     vector<int> result;
//     int start = 0;
//     int last = k-1;
//     while(last < mysize){
//         window_min_max(arr,result,start,last);
//         start++;
//         last++;
//     }

//     return result;
// }
// int main(){
//     vector<int> arr= {1,-6,3,7,8,2,-10,6,1,9,5,7,6,2};
//     int k;
//     cout<<"enter the value of k"<<endl;
//     cin>>k;

//     vector<int> result = arr_min_max(arr,k);
//     for(int i : result){
//         cout<<i<<" ";
//     }
//     cout<<endl;

// }



// approach 2 : this is optimized but hard one.


// time complexity is O(N).

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void print_queue(deque<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop_front();
    }
    cout<<endl;
}

int sum_min_max(vector<int> arr , int size ,int k){
    // initialize the deque for storing max in decreasing order
    deque<int> maxi;
    // initialize the deque for storing min in increse order.
    deque<int> mini;

    // to store total sum.
    int ans = 0;

    // now add min and max for firat window.
    for(int i =0;i<k;i++){
        
        // biggest number at first and then decrease after that 
        while(!maxi.empty() && arr[maxi.back() <= arr[i]]){
            maxi.pop_back();
        }

        // most min number then increasing after that.
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }

        mini.push_back(i);
        maxi.push_back(i);
    }
    
    // now add most max value and most min value
    ans+= arr[maxi.front()] + arr[mini.front()];

    // now do it for other windows also 
    // update the window and find min and max.

    for(int i=k;i<size;i++){

        // update the windows
        // maxi

        if (maxi.front() == i-k){
            maxi.pop_front(); // yes it is in the deque.
        }

        if (mini.front() == i-k){
            mini.pop_front();
        }

        // check mini and maxi for new window
        while(!maxi.empty() && arr[maxi.front()] <= arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.front()] >= arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);

        // sum of max and min of this window is 
        ans+= arr[maxi.front()] + arr[mini.front()];
    }

    return ans;

}
int main(){
    vector<int> arr = {2,5,-1,7,-3,-1,-2};
    int k;
    cout<<"enter the k value "<<endl;
    cin>> k;
    int mysize = arr.size();
    int ans = sum_min_max(arr,mysize,k);
    cout<<"total sum of all windows maximumm and minimum is "<<ans<<endl;

}
