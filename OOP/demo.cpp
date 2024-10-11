#include<iostream>
using namespace std;

// class human{
//     private:
//     int hands=2;
//     protected:
//     int fingers=11;
//     void print(){
//         cout<<"get this, this is protected"<<endl;
//     }
//     public:
//     int getter_finger(){
//         return fingers;
//     }
//     int weight=60;
//     int height=160;
//     void print1(){
//         cout << "you can get this , this is public"<<endl;
//     }



// };

// class male : protected human{
//     // to access the public one it is possible direclty
//     // for private it is not accessible for child class also
//     // protected one can be access as private to the child class. so use getter and setter
    
//     public:
//     void getter_print1(){
//         print1();
//     }
//     int getter_height(){
//         return this-> height;
//     }   
//     int getter(){
//         return this-> fingers;
//     }

//     void getter_func(){
//         print();
//     }

// };
// int main(){
//     male ramesh;
//     // cout<<ramesh.height<<endl; // if the mode of inheritance is public

//     // ramesh.print1(); if the mode of inheritance is public;
//     cout<<ramesh.getter()<<endl;
//     ramesh.getter_func();

//     human manus;
//     cout<<manus.getter_finger()<<endl;

//     cout<<ramesh.getter_height()<<endl; // when mode of onheritance is protected.
//     ramesh.getter_print1();  // when mode of inheritance is protected.
    




// }



class human{
    protected:
    int hands=2;
    public:
    int fingers =11;
};

class male : public human{
    // only setter and constructor ciuld do that.
    public:
    this-> fingers=10;
    void setter(){
        this->fingers = 2;
    }  
    int getter(){
        return this-> fingers;
    }
};
int main(){
    male ramesh;
    ramesh.setter();
    cout<<ramesh.getter()<<endl;
}