#include<iostream>
using namespace std;



// COPY CONSTRUCTOR
class Hero3 {
    public:
    int Health;
    int socre;
    Hero3(){
    Health=70;
    socre=90;
    }
    public:
    Hero3(Hero3& temp){
        this -> Health = temp.Health;
        this -> socre = temp.socre;
        cout<<"copying done...."<<endl;
    }

};

// PARAMETERISED CONSTRUCTOR
class Hero {
    public:
    int health = 100;
    int score = 20;
    int armor=45;

    public:
    Hero(){
        cout<<"This is default constructor"<<endl;

    }
    Hero(int health){
        cout<<"'this' keyword store the object address :"<<this<<endl;
        (*this).health=health; 
        // here "this" is address of the current holding object who call this contructor
    }
    Hero (int score , int armor){
        this -> score=score;
        this -> armor=armor;
    }
    void print(){
        cout<<"score "<< score<<endl;
        cout<<"armoer "<<armor<<endl;
        cout<<"health "<<health<<endl;
    }
};




class Hero2{
    //default constructor.
    public:
    Hero2(int value){
        
        cout<<"This is default constructor"<<endl;
    }
    private:
    int XP=77;
    public:
    int Health = 100;

    //getter function
    int getter(){
        return XP;  // member function can have the access of private variables.
    }

    //setter function.
    void setter(int power){
        XP=power ; // and can change it.
    }

};
// int main(){
//     Hero2 obj1;
//     cout<<"Health"<<obj1.Health<<endl;
//     // cout<<"name :"<<obj1.name<<endl;
//     // access the private variable we have to do....
//     int ans = obj1.getter();
//     cout<<"Xp is "<<ans <<endl;
//     // and to change we have to do setter.

//     obj1.setter(15);

//     ans = obj1.getter();
//     cout<<"Xp is "<<ans <<endl;

//     cout<<"Size of obj here is "<<sizeof(obj1)<<endl;



// }




// MEMORY ALLOCATION

/*

int main(){
    // dynamic allocation
    cout<<"Kya hua"<<endl;

    Hero2 obj1;
    // here obj1 is stored in stack
    //how to access members if the function
    //public
    obj1.Health=1200;
    cout<<obj1.Health<<endl;

    //private
    obj1.setter(300);
    int ans =obj1.getter();
    cout<<ans<<endl;

    //Dynamic memory allocation.
    Hero2 *obj2 = new Hero2; 
    // here obj2 is pointer which store the address of the heap allocation.

    //How to access
    //public
    cout<<(*obj2).Health<<endl;    // here obj is pointer so to get value we have to do *obj2.
    cout<<obj2->Health<<endl;  // instead of doing above we do directly this using ->

    //private
    (*obj2).setter(200);  // here also we have to do it like this
    cout<<(*obj2).getter()<<endl;
    cout<<obj2->getter()<<endl;






}
*/

//  DEFAULT CONSTRUCTOR
/*
int main(){
    
    //static way
    Hero2 obj1 ; // obj.Hero2()

    //dynamic way 

    Hero2 *obj2 = new Hero2;
    // OR
    Hero2 *obj3 = new Hero2();
}
*/


// parameterized constructor.
/*
int main(){
    Hero object;
    
    Hero object1(40);
    cout<<"address of object 1 "<<&object1<<endl;
    Hero object2(50,50);


    cout<<"object 1"<<endl<<endl;
    object1.print();
    cout<<endl<<"object 2"<<endl<<endl;
    object2.print();
    
}

*/


// COPY CONSTRUCTOR

int main(){
    Hero Ramesh(40,50);

    cout<<"Ramesh properties"<<endl;
    Ramesh.print();
    // instead of doing this ...
    //hero Suresh(40,50) OR
    // suresh.Health=ramesh.Health
    // suresh.armor=ramesh.armor

    // we can do simply
    Hero Suresh(Ramesh); // this is by default copy contructor is created we can create it seperatly
    cout<<"After copy Suresh properties "<<endl;
    Suresh.print();


    // created COPY CONSTRUCTOR
    Hero3 santa;
    cout<<"Health of santa "<<santa.Health<<endl;
    cout<<"score of santa "<<santa.socre<<endl;
    Hero3 banta(santa); //copy constructor created here.
    cout<<"copied Health to banta "<<banta.Health<<endl;
    cout<<"copied score to banta "<<banta.socre<<endl;

    
    
}



    

