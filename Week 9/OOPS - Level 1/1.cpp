#include <bits/stdc++.h>
using namespace std;

class Animal{
    //state or properties
    public:
    int age;
    string name;

    //behavior - functions
    void eat(){
        cout<<"Eating"<<endl;
    }
    void sleep(){
        cout<<"Eating"<<endl;
    }
};

int main()
{
    //Object creation
    //Static
    Animal ramesh;
    ramesh.age = 12;
    ramesh.name = "Lion";
    cout<<"Age of Ramesh is: "<<ramesh.age<<endl;
    cout<<"Name of Ramesh is: "<<ramesh.name<<endl;
    ramesh.eat();
    ramesh.sleep();
    //Dynamic
    return 0;
}