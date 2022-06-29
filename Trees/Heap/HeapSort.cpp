#include<iostream>
#include<vector>
using namespace std;

class Heap{
    public:
        int arr[100];
        int size = 0;

        Heap()
        {
            arr[0] = -1;
            int size = 0;
        }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int size = n;
    while(size > 1)
    {
        // 1: swap root node with the last 
        swap(arr[size], arr[1]);
        size--;

        // 2: Find the correct position of of root node

        heapify(arr, size, 1);
    }
}

int main()
{
    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;

    // Heap Creation
    for (int i=n/2;i>0;i--)
    {
        heapify(arr, n, i);
    }

    cout<<"Printing heap Array: "<<endl;
    for (int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // HeapSort
    heapSort(arr, n);

    cout<<"Printing heap sort Array: "<<endl;

    for (int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }

}