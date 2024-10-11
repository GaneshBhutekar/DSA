#include<iostream>
#include<cstring>
using namespace std;


class Hero {
    int value=10;
    public:
    int getvalue() const{
        return value;
    }
    void setvalue(int v) {
        this-> value = v;
    }

};
int main(){
    int value=10;
    int value1 =10;
    int value2 =10;
    int value3 = 10;


    const int *ptr = &value;
    // cannot modify value through pointer but  address can modifyable
    // *ptr=10; error

    // ptr = &value1; valid

    int *const ptr1 = &value;
    // cannot modify addresss but value can.

    // ptr1=&value2; Error
    // *ptr1= 1000; valid

    const int *const ptr3=&value2;

    // ptr3 = &value3; Error
    // *ptr3=11; Error

    const Hero Ramesh;

    cout<<Ramesh.getvalue()<<endl; 
    // this is accessible becaoz we ensure that it is not change any value by using const.
    // Ramesh.setvalue(10); //inaccessible because there is not written const that means it is changable




}