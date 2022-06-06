#include<iostream>
using namespace std;
class Animal{                            // Method Overriding
    public:
        void speak()
        {
            cout<<"Speaking!"<<endl;
        }
};
 
class Dog : public Animal{
    public:
        void speak()
        {
            cout<<"Barking!"<<endl;
        }
};
int main()
{
    Dog obj1;
    obj1.speak();
}