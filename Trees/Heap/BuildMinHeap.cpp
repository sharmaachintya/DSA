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

void heapify(vector<int> &arr, int n , int i)
{
    int smallest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if (left < n && arr[smallest] > arr[left])
    {
        smallest = left;
    }
    if (right < n && arr[smallest] > arr[right])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
}

int main()
{
    vector<int> arr = {-1,54,53,55,52,50};
    int n = arr.size();
    for (int i=n/2;i>0;i--)
    {
        heapify(arr, n, i);
    }
    cout<<"MIN HEAP: "<<endl;
    for (int i=1;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}