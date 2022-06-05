#include<iostream>
using namespace std;
class A{                                                  // Function Overloading
    public:
        void sayHello()
        {
            cout<<"Hello Achi Boi"<<endl;
        }
        void sayHello(string str)
        {
            cout<<"Hello "<<str<<endl;
        }
        int sayHello(string str, int n)
        {
            cout<<"Hello "<<str<<endl;
            return n;
        }
};

class B{                                                // Operator Overloading
    public:
        int a;
        int b;

        int add()
        {
            return a+b;
        }

        void operator+ (B &obj)
        {
            int value1 = this->a;
            int value2 = obj.a;
            cout<<"Output "<<value2 - value1<<endl;
        }

        void operator() ()
        {
            cout<<"I'm Bracket!"<<endl;
        }
};
int main()
{
    A obj1;
    obj1.sayHello();
    obj1.sayHello("Achi");
    obj1.sayHello("Achi Boi", 1);

    B obj2 ,obj3;
    obj2.a = 4;
    obj3.a = 7;
    obj2 + obj3;
    obj2();
}