

// IMPORTANT :---- N number of stack.


#include<iostream>
#include<vector>
using namespace std;
// create the N stack 
class NStack{
    public:
    int *arr;
    int * Next;
    int * top;
    int s;
    int n;
    int free = 0;
    int i = 0;
    NStack(int s,int n){
        // initialize all the value.
        arr = new int[s];
        this -> s = s;
        this  -> n = n;
        Next = new int[s];
        top = new int[n];

        // initialize the next with next free space.
        for(int i = 0;i<s;i++){
            Next[i] = i+1;
        }
        Next[s-1] = -1;

        // initialize the top array 

        for(int i = 0; i<n; i++){
            top[i] = -1;
        }


    }

    bool push(int value,int stackn){


        // check whether stack is full or not 
        if (free == -1){
            cout<<"stack is full already "<<endl;
            return false;
        }

        // point the next free block
        i = free;
        // store next free element after this
        free = Next[i];
        // store the elemnt in i index of the array.
        arr[i] = value; // push the vallue.

        // update the nedxt now point behind element of that stack so that it will delete.
        Next[i] = top[stackn];

        //update the top for given stack

        top[stackn] = i;

        // hence 1 element is push into the stack in optimized way.
        return true;

    } 

    bool pop(int stackn){
        // pop the element from that stack.

        if (top[stackn] == -1){
            cout<<"stack is underflow (empty) "<<endl;
            return false;
        }
        i = top[stackn];
        top[stackn] = Next[i]; // where Next[i] is pointing to the previous stack element.
        Next[i] =   free;
        free = i;

        return true;
    }


    int attop(int stackn){
        if (top[stackn] == -1){
            cout<<"stack is under flow empty "<<endl;
            return -1;
        }
        int index = top[stackn];
        return arr[index];
    }

    bool isempty(int stackn){
        if (top[stackn] == -1){
            return true;
        }
        return false;
    }
};

int main(){

    int size = 10;
    int stacks = 5;

    NStack stack(10,5);

    stack.attop(1);

    stack.push(1,0);
    stack.push(2,0);
    cout<<"at the top of stack 0 stack "<<stack.attop(0)<<endl;

    stack.push(3,0);
    stack.push(10,1);
    stack.push(20,1);
    stack.push(30,1);

    if (stack.isempty(2)){
        cout<<"it is empty "<<endl;
    }
    else{
        cout<<"not empty "<<endl;
    }

    stack.push(40,1);
    stack.push(100,2);
    stack.push(200,2);
    stack.push(300,2);

    cout<<"top of the stack 2 "<<stack.attop(2)<<endl;

    stack.push(400,0); // here array is fulled it will not push


    
    
}