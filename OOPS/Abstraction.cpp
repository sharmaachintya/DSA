#include<iostream>
using namespace std;
class A{
    private:
        int a, b; 
    public:
        void set(int a, int b)
        {
            this->a = a;
            this->b = b;
        }
        void display()
        {
            cout<<"a = "<<a<<endl;
            cout<<"b = "<<b<<endl;
        }
};

int main()
{
    A obj;
    obj.set(10,20);
    obj.display();
}