#include<iostream>
// #include "demo.cpp " 
//   instead of this we have to use it as .h not .cpp because demo.cpp has main function block
using namespace std;

class Hero {
    private:
    char alpha='a'; // not accesssed outside this class.
    public:
    char alpha2='5';

    void setter(int ch){
        alpha=ch;
        return;
    };
    // alpha = 'b';
    char getter(){
        return alpha;
    }

};

int main(){
    Hero obj;
    obj.setter('c');
    char ans=obj.getter();
    cout<<ans<<endl;


}