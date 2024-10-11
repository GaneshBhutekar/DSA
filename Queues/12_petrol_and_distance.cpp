#include<iostream>
#include<vector>
using namespace std;

// here we create the class so that objects named vector have multiple petdist objects as element and every element has petrol and distace also.

class petdist{
    public:
    int petrol;
    int distance;
};

int find_start(vector<petdist> p ,int size){
    // to avoid double iteration we will do.
    int balance=0;
    int kami = 0;
    int start = 0; // it is front.

    for(int i=0;i<size;i++){
        // iterate it .
        balance += p[i].petrol - p[i].distance;
        if (balance < 0){
            kami += balance;
            balance =0;
            start = i+1;
        }

    }

    if (kami + balance >= 0){
        return start;
    }
    else{
        return -1;
    }

}

int main(){ 
    vector<petdist> objects(4);
    for(int i = 0;i<objects.size();i++){
        cout<<"enter the value petrol and distance"<<endl;
        cin>> objects[i].petrol;
        cin>> objects[i].distance;
    }


    cout<<"printing the array "<<endl;
    for(auto i:objects){
        cout<<i.petrol<<" ";
        cout<<i.distance<<endl;
    }
    int mysize = objects.size();
    int ans = find_start(objects,mysize);
    cout<<"start from "<<ans <<endl;

}