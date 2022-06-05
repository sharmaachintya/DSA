#include<iostream>
using namespace std;
class A {
    public:
        void func1()
        {
            cout<<"IN CLASS A!"<<endl;
        }
};

class B : public A{
    public:
        void func2()
        {
            cout<<"IN CLASS B!"<<endl;
        }
};

class C : public A, public B{                    //Multiple + Hierarchical Inheritance
    public:
        void func3()
        {
            cout<<"IN CLASS C!"<<endl;
        }
};
int main()
{
    C obj1;
    A obj2;
    obj1.func2();
    obj1.func3();
    obj2.func1();
}