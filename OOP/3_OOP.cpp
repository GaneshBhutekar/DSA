#include<iostream>
using namespace std;

class hero{
    public:
    int score;
    int number;
    //static variable
    static int timeToComplete; // declare here and initialize outside the class.

    // static function
    static int random(){
        // no this so can't access varibles only static variable
        // cout<<this-> score<<endl; Error
        cout<<"Hello this is in static function"<<endl;
        cout<<hero::timeToComplete<<endl;
        return hero::timeToComplete;
    }


    hero(int score,int number){
        this-> score = score;
        this-> number = number;

    }
    void print(){
        cout<<this-> score<<endl;
        cout<<this-> number<<endl;
    }
    ~hero(){
        cout<<"This is Destructor"<<endl;
    }
};

int hero::timeToComplete = 5;
int main(){
    hero A(50,60);
    hero B(500,600);
    cout<<"Before copy Assignment"<<endl;
    A.print();
    // instead of doing this 
    // A.number=B.number;
    // A.score=B.score;
    // we do
    cout<<"After Copy Assignment"<<endl;
    A=B;
    cout<<"A"<<endl;
    A.print();
    cout<<"B"<<endl;
    B.print();

    cout<<"DEstructor"<<endl;

    hero *C = new hero(100,100);

    hero *D = new hero(200,200);

    // only destructor manually needed to dynamic allocation object. here it is two

    //accessing the static variable

    cout<<hero::timeToComplete<<endl; // good practice

    cout<<A.timeToComplete<<endl; // bad practice.

    hero::timeToComplete=100;

    cout<<hero::timeToComplete<<endl; // or

    A.timeToComplete = 1000;

    cout<<hero::timeToComplete<<endl;

    // calling static function
    cout<<hero::random()<<endl;


    




}