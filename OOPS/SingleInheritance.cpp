#include<iostream>
using namespace std;
class Animal{
    public:
        int weight;
        int age;

        void speak()
        {
            cout<<"Speaking!"<<endl;
        }
};

class Dog : public Animal {

};
int main()
{
    Dog obj1;
    obj1.speak();
}