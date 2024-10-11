#include<iostream>
using namespace std;


// ENCAPSULATION....

/*
class student {
    string name = "Ganesh";
    int age = 21;
    int height =156;
    public:
    int getAge(){
        return this->age;
    }
    string getName(){
        return this->name;
    }

};

int main(){
    student roll_1;

    cout<<roll_1.getName()<<endl;
    
}

*/



// INHERITANCE.....

//parent class 
class Human{
    private:
    int hands=2;

    public:
    int legs=2;
    int weight=60;
    int age=20;

    int getAge(){
        return age;

    }
    void setWeight(int weight){
        this-> weight = weight;
    }

};

class Male : public Human{
    
    
    public:

    string hair="short";
    bool beard = true;

    void strength(){
        cout<<"Man strength is more than  woman"<<endl;
    }

    // if protected as mode of inheritance
    int getter_legs(){
        return this-> legs;
    }



};

int main(){
    Male Ramesh;
    Ramesh.strength();

    cout<<Ramesh.legs<<endl; // this member is from human class.

    cout<<Ramesh.hair<<endl; // this is from Male class.

    cout<<Ramesh.getAge()<<endl; // from Human class.


    // accessing private member from Human by Ramesh from  Male class.
    // cout<<Ramesh.hands<<endl; // not possible because hands is private in parent class/.


    
}

/*
#include<iostream>
using namespace std;

class human{
    private:
    int hands=2;
    protected:
    int fingers=11;
    void print(){
        cout<<"get this, this is protected"<<endl;
    }
    public:
    int getter_finger(){
        return fingers;
    }
    int weight=60;
    int height=160;
    void print1(){
        cout << "you can get this , this is public"<<endl;
    }



};

class male : protected human{
    // to access the public one it is possible direclty
    // for private it is not accessible for child class also
    // protected one can be access as private to the child class. so use getter and setter

    public:
    void getter_print1(){
        print1();
    }
    int getter_height(){
        return this-> height;
    }   
    int getter(){
        return this-> fingers;
    }

    void getter_func(){
        print();
    }

};
int main(){
    male ramesh;
    // cout<<ramesh.height<<endl; // if the mode of inheritance is public

    // ramesh.print1(); if the mode of inheritance is public;
    cout<<ramesh.getter()<<endl;
    ramesh.getter_func();

    human manus;
    cout<<manus.getter_finger()<<endl;

    cout<<ramesh.getter_height()<<endl; // when mode of onheritance is protected.
    ramesh.getter_print1();  // when mode of inheritance is protected.
    




}   
*/