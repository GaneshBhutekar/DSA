#include<iostream>
using namespace std;
#include<vector>
#include<set>
using namespace std;
int main(){
    vector<int> arr1={1,2,2,1,3};
    vector<int> arr2={2,2,3};
    vector<int> arr3;


    set<int> set1(arr1.begin(),arr1.end());
    set<int> set2(arr2.begin(),arr2.end());

    for(int i : set1){
        if(set2.find(i) != set2.end()){
            arr3.push_back(i);
        }
    }

    for(int i =0; i<arr3.size();i++){
        cout<<arr3[i]<<" ";
    }
    cout<<endl;

}
    