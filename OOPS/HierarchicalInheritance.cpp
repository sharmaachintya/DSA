#include<iostream>
using namespace std;
class A {
    public:
        void func1()
        {
            cout<<"Class A function!"<<endl;
        }
};

class B : public A{
    public:
        void func2()
        {
            cout<<"Class B function!"<<endl;
        }
};

class C : public A{
    public:
        void func3()
        {
            cout<<"Class C function!"<<endl;
        }
};

int main()
{
    A obj1;
    obj1.func1();
    B obj2;
    obj2.func2();
    obj2.func1();
    C obj3;
    obj3.func3();
    obj3.func1();

}