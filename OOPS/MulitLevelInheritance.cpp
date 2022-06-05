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

class GermanShephard : protected Dog{
    public:
        int getAge()
        {
            return this->age;
        }
        void setAge(int age)
        {
            this->age = age;
        }
};
int main()
{
    GermanShephard obj1;
    obj1.setAge(20);
    cout<<obj1.getAge()<<endl;
} 