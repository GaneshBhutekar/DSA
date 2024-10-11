#include<iostream>
#include<stack>
using namespace std;


// S : - source 
// D : - destination
// H : - Helper.

void tower_of_hanoi(int n, string S,string D,string H){
    // if base case
    if (n <= 1){
        cout<<"moved disk from "<<S<<" to "<<D<<endl;
        return;
    }

    // break till it becames 1 
    tower_of_hanoi(n-1,S,H,D); // here helper became the destination so that n-1 one stack at helper and the last one get moved to the end

    // now move the last one to the  destination.
    cout<<"moved disk from "<<S<<" to "<< D<<endl;

    tower_of_hanoi(n-1,H,D,S);
}
int main(){

    string S= "source";
    string H ="helper";
    string D= "Destination";
    int n;
    cout<<"enter the number of disks "<<endl;
    cin>> n;
    tower_of_hanoi(n,S,D,H);
    
}