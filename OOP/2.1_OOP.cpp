#include <iostream>
#include <cstring>
using namespace std;

// SHALLOW COPY

// Shalloow copy :here numbers not copied because it is pass by value default
// but array of char is passiung the pointer here soo at the time of copy constructor
// it will copy the address of the name first element.

// class Hero {
//     public:
//     int health;
//     int score;
//     char *name;
//     Hero(int health , int score){
//         cout<<"contructor called"<<endl;
//         this-> health=health;
//         this-> score = score;
//         this-> name = new char[100];
//     }

//     void setter_health(int health){
//         this-> health = health;
//     }
//     void setter_score(int score){
//         this-> score = score;
//     }
//     void setter_name(char name[]){
//         strcpy(this-> name,name);
//     }
//     void print(){
//         cout<<"Name :"<<this-> name<<endl;
//         cout<<"health :"<<this-> health<<endl;
//         cout<<"score :"<<this-> score <<endl;
//     }

// };
// int main(){
//     Hero R(90,100);
//     char name[7]="Ganesh";
//     R.setter_name(name);
//     R.print();

//     cout<<"COPYING THE DATA TO S OBJECT"<<endl;
//     Hero S(R); // copy contructor

//     S.print();

//     cout<<"CHANGES TO R OBJECT"<<endl;

//     R.setter_health(1000);
//     R.setter_score(1000);
//     R.setter_name("GANESH");
//     // R.name[0]='M';

//     R.print();
//     cout<<endl<<endl;

//     cout<<"DUE TO S IS SWALLOW COPY OF R THEN "<<endl;

//     S.print();

// }

// DEEP COPY
// here we need to make copy constructor by self.

class hero
{
public:
    char *name;
    hero()
    {
        cout << "constructor" << endl;
        name = new char[100];
    }

    // copy constructor for deep copy.
    hero(hero &temp)
    {
        // copy it first to other char array
        // strcpy(this->name,temp.name);
        char *naya_array = new char[strlen(temp.name) + 1];
        // here we can't do direct copy because temp.name is pointer
        strcpy(naya_array, temp.name); // here we copied the address of temp.name to naya_array
        this->name = naya_array;
    }

    void setter_name(char name[])
    {
        strcpy(this->name, name); // new pointer is saved in name
    }

    void print()
    {
        cout << this->name << endl;
    }
};

int main()
{
    hero Ramesh;
    Ramesh.setter_name("Ganesh");

    Ramesh.print();

    // now this is  not default here above created copy cntructor will run.
    hero Suresh(Ramesh);

    Suresh.print();

    cout << "changes in Ramesh" << endl;

    char name[10] = "Uttam";
    Ramesh.setter_name(name);

    Ramesh.print();

    cout << "Changes in Suresh" << endl;
    Suresh.print();
    cout << "you canm see above that name is not changed" << endl;
}

