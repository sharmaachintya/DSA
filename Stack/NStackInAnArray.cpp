#include<iostream>
#include<stack>
using namespace std;
class Nstack{
    private:
        int *arr;
        int *top;
        int *next;
        int n, s;
        int freespot;
    public:
        Nstack(int N, int S)
        {
            n = N;
            s = S;
            arr = new int[s];
            top = new int[n];
            next = new int[s];
            for (int i=0;i<n;i++)   // Initialising Top
            {
                top[i] = -1;
            }
            for (int i=0;i<s;i++)   // Initialising next
            {
                next[i] = i+1;
            }
            next[s-1] = -1;

            freespot = 0;
        }

        bool push(int x, int m)
        {
            if(freespot == -1)        // STACK Overflow
            {
                return false;
            }

            int index = freespot;     // Find the freespot

            freespot = next[index];   // Update freespot

            arr[index] = x;           // Insert Value
        
            next[index] = top[m-1];   // Update next

            top[m-1] = index;         // Update top

            return true;
        }

        int pop(int m)
        {
            if (top[m-1] == -1)  // STACK Underflow
            {
                return -1;
            }

            int index = top[m-1];   // Find the index 

            top[m-1] = next[index];       // Update top

            next[index] = freespot; // Update next

            freespot = index;       // Update freespot

            return arr[index];
        }

};
int main()
{
    
}