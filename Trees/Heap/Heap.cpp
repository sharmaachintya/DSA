#include<iostream>
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

        // INSERION
        void insert(int val)
        {
            size = size + 1;
            int index = size;
            arr[index] = val;

            while (index > 1)
            {
                int parent = index / 2;
                if (arr[parent] < arr[index])
                {
                    swap(arr[parent], arr[index]);
                }
                else
                {
                    return;
                }
            }
        }

        // DELETION
        void deleteFromHeap()
        {
            if (size == 0)
            {
                cout<<"Nothing to Delete"<<endl;
                return;
            }
            // Copy value of last node into root node
            arr[1] = arr[size];

            // Remove last element
            size--;

            // Take root Node to it's correct position
            int i = 1;
            while(i < size)
            {
                int leftIndex = 2*i;
                int rightIndex = 2*i + 1;

                if (leftIndex < size && arr[i] < arr[leftIndex])
                {
                    swap(arr[i], arr[leftIndex]);
                    i = leftIndex;
                } 
                else if (rightIndex < size && arr[i] < arr[rightIndex])
                {
                    swap(arr[i], arr[rightIndex]);
                    i = rightIndex;
                }
                else
                {
                    return;
                }
            }

        }


        void print()
        {
            for (int i=1;i<=size;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

// HEAPIFY ALGORITHM
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int leftChild = 2 * i;
    int rightChild  = 2 * i + 1;

    if (leftChild <= n && arr[largest] < arr[leftChild])
    {
        largest = leftChild;
    }
    if (rightChild <= n && arr[largest] < arr[rightChild])
    {
        largest = rightChild;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main()
{
    Heap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    //h.deleteFromHeap();

    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;
    for (int i=n/2;i>0;i--)
    {
        heapify(arr, n, i);
    }
    cout<<"Printing the heapify array: "<<endl;
    for (int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    //h.print();
}