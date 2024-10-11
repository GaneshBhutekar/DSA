#include<iostream>
using namespace std;

// -----COMPILE TIME POLYMORPHISM ----//

// function overloading.
/*
class A{
    public:
    void sayHello(){
        cout<<"here no input parameter"<<endl;
    }
    int sayHello(string name){
        cout<<"Here 1 input parameter which is "<<name<<endl;
        return 1;
    }
    bool sayHello(string name1,string name2){
        cout<<"here there are two parameter which are "<<name1<<" and "<<name2<<endl;
        return true;
    }
    bool sayHello(string name1,int name2){
        cout<<"Here Data type of each parameter is different"<<endl;
        return true;
    }
    int defaultone(int a,int b,int c=0,int d=0){
        return a+b+c+d;
    }
    // here retturn type does'nt matter in function overloading input parameter number should be different

};
int main(){
    A obj;
    obj.sayHello();
    obj.sayHello("Ganesh");
    obj.sayHello("Ganesh","Bhutekar");
    obj.sayHello("Ganesh","Bhutekar");
    cout<<obj.defaultone(10,20)<<endl; // from here to below code we can see that diffrent default is also make function overloading
    cout<<obj.defaultone(10,20,30)<<endl;
    cout<<obj.defaultone(10,20,30,40)<<endl;
    (4>3)? cout<<"Yes"<<endl :cout<<"no"<<endl; // ternary operator
}
*/


// operator overloading

/*
class B{
    public:
    int a;

    void operator+ (B& obj){ 
        // here the second argument is input (a+b so b is input argument)
        // and a is "this" here.
        int value1=this->a; // here the object called value is accessed. a in this situation
        int value2 = obj.a; // here the object passed value is accessed b in this situation

        cout<<"output is subsract so it is :"<<value1-value2<<endl;

    }

    // below obj is obj2 and class called for obj1 (obj2 is input argument)
    void operator/ (B&obj){
        int val1 = this-> a;
        int val2 = obj.a;
        cout<<"here you used '/' this but it do * :"<<val1*val2<<endl;
    }

    // below is unary opeartor so here only one obj is there which is calling the class 
    // no argument is passed.
    void operator() (){
        cout<<"here no argument used but called by which a value is "<<this-> a<<endl;
    }

    void operator~ (){
        cout<<this-> a<<endl;
    }
};

int main(){
    // a+b
    // create object a and b .
    B obj1,obj2;

    obj1.a=100;
    obj2.a=10;

    obj1+obj2; // here obj1 is the called object and obj2 is passed in it.

    obj1/obj2; // here / is used but it do * and print.

    //unary opeartions no argument 
    obj1();

    ~obj2;




}
*/


// ---RUNTIME POLYMORPHISM ---//

class A{
    public:
    void print(){
        cout<<"here this print of class A" <<endl;
    }

};
class B:public A{
    public:
    void print(){
        cout<<"Here this print of class B"<<endl;

    }
};
class C: public B{
    public:
    void print(){
        cout<<"Here this print of class C"<<endl;
    }

};
int main(){
    C obj;
    obj.print();     
    // where, :: used to access the global variable or bigger variable if local is there 
    // here print is in local that's why we go to the B and there also print() 
    //then also we go A
    obj.B::A::print();
    obj.B::print();
}
