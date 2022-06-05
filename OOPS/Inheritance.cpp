#include<iostream>
using namespace std;
class Human {
    public:
        int weight;
        int age;
        int height;
    public:
        int getAge()
        {
            return this->age;
        }
        int setWeight(int w)
        {
            return this->weight = w;
        }
};

class Male: public Human{                 // Male Inheriting classs Human Publically
    public:
        string color;
        
        void sleep()
        {
            cout<<"Male Sleeping!"<<endl;
        }
};
int main()
{
    Male obj1;
    cout<<obj1.age<<endl;
    cout<<obj1.weight<<endl;
    cout<<obj1.height<<endl;
    cout<<obj1.color<<endl;
    obj1.setWeight(100);
    cout<<obj1.weight<<endl;
    obj1.sleep();
}