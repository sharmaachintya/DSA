#include<iostream>
using namespace std;
class Animal{
    public:
        int weight;
        int age;

        void Barking()
        {
            cout<<"Barking!"<<endl;
        }
};

class Human{
    public:
        void Speaking()
        {
            cout<<"Speaking!"<<endl;
        }
};

class Hybrid: public Animal, public Human{

};

int main()
{
    Hybrid obj1;
    obj1.Speaking();
    obj1.Barking();
}