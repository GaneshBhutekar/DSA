
// Type of inheritance

#include<iostream>
using namespace std;


// Single inheritance.

/*
class Human{
    public:
    int eyes=2;
    int legs=2;
    void print(){
        cout<<"Hello world"<<endl;
    }

};

class male:public Human{
    public:
    bool beard=true;
};




int main(){
    male freddy;
    cout<<freddy.legs<<endl;
}   
*/


// mutilevel inheritance
/*

class animal{
    public:
    bool speak=true;
};

class dog: public animal{
    public:
    int speed = 70;

};

class rottwheiler: public dog{
    public:
    string color = "Black";
};

int main(){
    rottwheiler sheru;
    cout<<sheru.speak<<endl;
}
*/



/*
class father{
    public:
    int pitch=23;
    string hair_color="black";
};

class mother{
    public:
    string color ="skin";
    
};

class child: public father,public mother{
    public:
    string behaviour="dumb";
};
int main(){
    child ek_banda;

    cout<<ek_banda.color<<endl; // from mother
    cout<<ek_banda.pitch<<endl; // from father

}

*/



// hierarchical inheritance.

//          dada
//    papa         chacha

// me    bhai

/*
class dada{
    public:
    string language="marathi";

};

class papa: public dada{
    public:
    string job="government";
};

class chacha: public dada{
    int vehicals = 4;
};

class bhai:public papa {
    string degree="BCA";
};

class me: public papa{
    int motivation_level=0;
};

int main(){
    me ganesh;
    cout<<ganesh.language<<endl;
    bhai om;
    cout<<om.job<<endl;

}




// hybrid inheritence.
/*

    A       D
  /   \   /
B       C

*/

/*
class A{
    public:
    string varA="class A";
};

class B: public A{
    public:
    string varB="class B";

};

class D {
    public:
    string varD="class D";
};

class C: public A,public D{
    public:
    string varC="class C";
};

int main(){
    C obj;
    cout<<obj.varA<<endl;
    cout<<obj.varD<<endl;
}
*/

// inheritance amibiguity
class A{
    public:
    void func(){
        cout<<"this is from A class"<<endl;
    }
};

class B{
    public:
    void func(){
        cout<<"THis is from B class"<<endl;

    }
};

class C:public A,public B{

};
int main(){
    C obj;
    obj.A::func();
    obj.B::func();  // scope resolution operator.
}

